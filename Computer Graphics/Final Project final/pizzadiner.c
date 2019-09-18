#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <stdio.h>
//#include <IL/il.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

#define DEFAULT_WIDTH  600
#define DEFAULT_HEIGHT 510
 
int width  = DEFAULT_WIDTH;
int height = DEFAULT_HEIGHT;
int move=0;

double xspot=42.0;
double zspot=-60.0;
double xlook=42.0;
double zlook=-55.0;

GLfloat light[]={1.0, 5.0, 0.0,1.0};
GLfloat light1[]={.0,5.0, 1.0,1.0};
GLfloat amb[]={1.0,1.0,1.0,1.0};
GLfloat diff[]={1.0,1.0,1.0,1.0};
GLfloat spec[]={1.0,1.0,1.0,1.0};


typedef GLubyte Pixel[3]; /*represents red green blue*/

int Width, Height; /*of image*/

/*array of pixels*/
Pixel *Image;

/*name of image file*/
char *Filename = "./texcloth.ppm";//
char *Filename1 = "./pizza1.ppm";//
char *Filename2 = "./plate.ppm";//
char *Filename3 = "./siln.ppm";//
char *Filename4 = "./wc.ppm";//
char *Filename5 = "./candia-carpet-tile.ppm";//
char *Filename6 = "./wpbur.ppm";//Not here
char *Filename7 = "./pizza2.ppm";//
char *Filename8 = "./pizza3.ppm";//
char *Filename9 = "./pizzamix.ppm";//
char *Filename10 = "./doors.ppm";//
char *Filename11 = "./REV.ppm";//
char *Filename12= "./bwood.ppm";//
char *Filename13= "./open.ppm";//
char *Filename14= "./chair.ppm";//
char *Filename15= "./brick-tile.ppm";
char *Filename16= "./frame1.ppm";
char *Filename17= "./frame2.ppm";

int allowedSize(int x)/*returns max power of 2 <= x*/
{
	int r;
	r = 1;
	while(r < x) r=(r<<1);
	
	if(r==x) return r;	
	else return r>>1;
}
/*reads the image file assumes ppm format*/
void readImage(int p){	
	int w,h,max;
	int i,j;
	unsigned int r,g,b,al;
	int k;
	char ch;
	FILE *fp;
	
	if(p==0){//printf("filename = %s\n",Filename);
fp = fopen(Filename,"r");}
	if(p==1){//printf("filename = %s\n",Filename1);
fp = fopen(Filename1,"r");}
	if(p==2){//printf("filename = %s\n",Filename2);
fp = fopen(Filename2,"r");}
	if(p==3){//printf("filename = %s\n",Filename3);
fp = fopen(Filename3,"r");}
	if(p==4){//printf("filename = %s\n",Filename4);
fp = fopen(Filename4,"r");}
	if(p==5){//printf("filename = %s\n",Filename5);
fp = fopen(Filename5,"r");}
	if(p==6){//printf("filename = %s\n",Filename6);
fp = fopen(Filename6,"r");}
	if(p==7){//printf("filename = %s\n",Filename7);
fp = fopen(Filename7,"r");}
	if(p==8){//printf("filename = %s\n",Filename8);
fp = fopen(Filename8,"r");}
	if(p==9){//printf("filename = %s\n",Filename9);
fp = fopen(Filename9,"r");}
	if(p==10){//printf("filename = %s\n",Filename10);
fp = fopen(Filename10,"r");}
	if(p==11){//printf("filename = %s\n",Filename11);
fp = fopen(Filename11,"r");}
	if(p==12){//printf("filename = %s\n",Filename12);
fp = fopen(Filename12,"r");}
	if(p==13){//printf("filename = %s\n",Filename13);
fp = fopen(Filename13,"r");}
	if(p==14){//printf("filename = %s\n",Filename14);
fp = fopen(Filename14,"r");}
///*
	if(p==15){//printf("filename = %s\n",Filename14);
fp = fopen(Filename15,"r");}
	if(p==16){//printf("filename = %s\n",Filename14);
fp = fopen(Filename16,"r");}
	if(p==17){//printf("filename = %s\n",Filename14);
fp = fopen(Filename17,"r");}
//*/

	/*read the header*/
    fscanf(fp, "P%c\n", &ch);
	if (ch != '3') {
	fprintf(stderr, "Only ascii mode 3 channel PPM files");
	exit(-1);
	}

	/*strip comment lines*/
	ch = getc(fp);
	while (ch == '#') {
      do {
		ch = getc(fp);
      }
	  while (ch != '\n');
      ch = getc(fp); 
    }
	ungetc(ch, fp);

	/*read the width*/
	fscanf(fp,"%d",&w);
	
	/*read the height*/
	fscanf(fp,"%d",&h);
	
	/*max intensity - not used here*/
	fscanf(fp,"%d",&max);
	
	/*width and height must be powers of 2
	here of finding the max power of 2 <= w and h*/

	Width = allowedSize(w);
	Height = allowedSize(h);
	
	//printf("Width = %d, Height = %d\n",Width,Height);
	
	Image = (Pixel *)malloc(Width*Height*sizeof(Pixel));

	for(i=0;i<Height;++i){
		for(j=0;j<Width;++j) {
			fscanf(fp,"%d %d %d",&r,&g,&b);
			k = i*Width+j;
			(*(Image+k))[0] = (GLubyte)r;
			(*(Image+k))[1] = (GLubyte)g;
			(*(Image+k))[2] = (GLubyte)b;
			(*(Image+k))[3] = (GLubyte)al;
		}
		/*better scan to the end of the row*/
		for(j=Width; j<w; ++j) fscanf(fp,"%c %c %c",&r,&g,&b);
	}
	fclose(fp);
}

void initialiseTextures(int p){
	GLint level = 0;/*only one level-no level of detail*/
	GLint components = 3; /*R,G,B components only*/
	GLint border = 0; /*no border around the image*/
	
	/*read the image file*/
	readImage(p);
	
	/*each pixelrow on a byte alignment boundary*/
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	
	/*define information about the image*/
	glTexImage2D(GL_TEXTURE_2D,level,components,
			(GLsizei)Width, (GLsizei)Height,
		     	border, GL_RGB, GL_UNSIGNED_BYTE,Image);

/*ensures that image is not wrapped*/	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	
/*chooses mapping type from texels to pixels*/	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
/*GL_LINEAR which performs a linear interpolation on the 4 surrounding texels*/
	
	/*GL_DECAL - overwrite pixel with texture colour*/
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
	/*alternative is GL_MODULATE. modulates the lighting
	by the texel value by multiplication*/
	
}

void init(){
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glEnable(GL_LIGHTING);
glDepthMask(GL_TRUE);

glEnable(GL_LIGHT0);
glLightfv(GL_LIGHT0,GL_POSITION,light);
glLightfv(GL_LIGHT0,GL_AMBIENT_AND_DIFFUSE, amb);
glLightfv(GL_LIGHT0,GL_SPECULAR, spec);

glEnable(GL_LIGHT1);
glLightfv(GL_LIGHT1,GL_POSITION,light1);
glLightfv(GL_LIGHT1,GL_AMBIENT_AND_DIFFUSE, amb);
glLightfv(GL_LIGHT1,GL_SPECULAR, spec);

	/*create normals normalised and automatically*/
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);
	
	/*for 2D the modelview matrix is the identity*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    	/*enable the depth buffer*/
    	glEnable(GL_DEPTH_TEST);
    
    	/*set the depth buffer for clearing*/
    	glClearDepth(1.0);
}

void table(){
initialiseTextures(0);
//Table stand ground for all objects
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(5.0,4.0,-5.0);
glTexCoord2f(1,1);glVertex3f(-6.5,4.0,-5.0);
glTexCoord2f(0,1);glVertex3f(-6.5,4.0,5.0);
glTexCoord2f(0,0);glVertex3f(5.0,4.0,5.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,1);glVertex3f(5.0,4.0,-5.0);
glTexCoord2f(0,1);glVertex3f(5.0,4.0,5.0);
glTexCoord2f(0,0);glVertex3f(5.0,3.5,5.0);
glTexCoord2f(1,0);glVertex3f(5.0,3.5,-5.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(0,1);glVertex3f(5.0,4.0,5.0);
glTexCoord2f(1,1);glVertex3f(-6.5,4.0,5.0);
glTexCoord2f(1,0);glVertex3f(-6.5,3.5,5.0);
glTexCoord2f(0,0);glVertex3f(5.0,3.5,5.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(0,1);glVertex3f(5.0,4.0,-5.0);
glTexCoord2f(1,1);glVertex3f(-6.5,4.0,-5.0);
glTexCoord2f(1,0);glVertex3f(-6.5,3.5,-5.0);
glTexCoord2f(0,0);glVertex3f(5.0,3.5,-5.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,1);glVertex3f(-5.5,4.0,-5.0);
glTexCoord2f(0,1);glVertex3f(-5.5,4.0,5.0);
glTexCoord2f(0,0);glVertex3f(-5.5,3.5,5.0);
glTexCoord2f(1,0);glVertex3f(-5.5,3.5,-5.0);
glEnd();
glDisable(GL_TEXTURE_2D);

//The leg of the table
GLfloat color[]={0.5,0.5,0.0,1.0};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,color);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,color);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,color);
glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10.0);
//glPushMatrix();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,0.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,4.0,0.0);
//glTexCoord2f(0,1);
glVertex3f(-0.5,4.0,1.0);
//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,1.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-1.5,0.0,0.0);
//glTexCoord2f(1,1);
glVertex3f(-1.5,4.0,0.0);
//glTexCoord2f(0,1);
glVertex3f(-0.5,4.0,0.0);
//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,0.0);
glEnd();

glBegin(GL_POLYGON);
//glTexCoord2f(1,0);
glVertex3f(-1.5,0.0,0.0);
//glTexCoord2f(1,1);
glVertex3f(-1.5,4.0,0.0);
//glTexCoord2f(0,1);
glVertex3f(-1.5,4.0,1.0);
//glTexCoord2f(0,0);
glVertex3f(-1.5,0.0,1.0);
glEnd();

glBegin(GL_POLYGON);
//glTexCoord2f(1,0);
glVertex3f(-1.5,0.0,1.0);
//glTexCoord2f(1,1);
glVertex3f(-1.5,4.0,1.0);
//glTexCoord2f(0,1);
glVertex3f(-0.5,4.0,1.0);
//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,1.0);
glEnd();

glBegin(GL_POLYGON);//the base of the leg
//glTexCoord2f(1,0);
glVertex3f(1.0,0.01,-1.7);
//glTexCoord2f(1,1);
glVertex3f(-3.0,0.01,-1.7);
//glTexCoord2f(0,1);
glVertex3f(-3.0,0.01,2.3);
//glTexCoord2f(0,0);
glVertex3f(1.0,0.01,2.3);
glEnd();
}

//The pizza
void pizza(){
initialiseTextures(1);

glEnable(GL_TEXTURE_2D);
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(1.5,4.01,-2.3);
glTexCoord2f(1,1);glVertex3f(-3.5,4.01,-2.3);
glTexCoord2f(0,1);glVertex3f(-3.5,4.01,2.1);
glTexCoord2f(0,0);glVertex3f(1.5,4.01,2.1);
glEnd();
glDisable(GL_TEXTURE_2D);
}

//Both beer mugs
void glass(){
GLfloat color[]={1.0,1.0,1.0,1.0};
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,color);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,color);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,color);
glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10.0);
glPushMatrix();

glTranslatef(3.0,0,-4.0);

//draw sections of cup starting from back
for(int i=0; i<35; i++){
glBegin(GL_POLYGON);
glVertex3f(-0.8,4.0,-0.2);glVertex3f(-0.8,4.6,-0.2);
glVertex3f(-0.8,4.6,0.1);glVertex3f(-0.8,4.0,0.1);
glEnd();

glRotatef(10,0.0f,-1.0f,0.0f);
}
glPopMatrix();

glPushMatrix();
//the second mug
glTranslatef(-4.5,0,4);

//draw sections of cup starting from back
for(int i=0; i<35; i++){
glBegin(GL_POLYGON);
glVertex3f(-0.8,4.0,-0.2);glVertex3f(-0.8,4.6,-0.2);
glVertex3f(-0.8,4.6,0.1);glVertex3f(-0.8,4.0,0.1);
glEnd();

glRotatef(10,0.0f,-1.0f,0.0f);
}
glPopMatrix();
}

void silverware(){
initialiseTextures(3);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(0.2,1);glVertex3f(5.0,4.02,2.0);
glTexCoord2f(0.8,1);glVertex3f(5.0,4.02,5.0);
glTexCoord2f(0.8,0);glVertex3f(0.0,4.02,5.0);
glTexCoord2f(0.2,0);glVertex3f(0.0,4.02,2.0);
glEnd();

//second fork
glBegin(GL_POLYGON);
glTexCoord2f(0.2,1);glVertex3f(-6.5,4.02,-1.3);
glTexCoord2f(0.8,1);glVertex3f(-6.5,4.02,-5.0);
glTexCoord2f(0.8,0);glVertex3f(-3.0,4.02,-5.0);
glTexCoord2f(0.2,0);glVertex3f(-3.0,4.02,-1.3);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void plates(){
initialiseTextures(2);
glEnable(GL_TEXTURE_2D);
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(5.0,4.02,-2.5);
glTexCoord2f(1,1);glVertex3f(1.5,4.02,-2.5);
glTexCoord2f(0,1);glVertex3f(1.5,4.02,1.8);
glTexCoord2f(0,0);glVertex3f(5.0,4.02,1.8);
glEnd();

glEnable(GL_TEXTURE_2D);
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(-6.5,4.02,-2.5);
glTexCoord2f(1,1);glVertex3f(-3.0,4.02,-2.5);
glTexCoord2f(0,1);glVertex3f(-3.0,4.02,1.8);
glTexCoord2f(0,0);glVertex3f(-6.5,4.02,1.8);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void sign(){
initialiseTextures(11);
glEnable(GL_TEXTURE_2D);

//Front door from front
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(45.0,8.0,-55.52);
glTexCoord2f(0,0);
glVertex3f(20.0,8.0,-55.52);
glTexCoord2f(0,1);
glVertex3f(20.0,5.0,-55.52);
glTexCoord2f(1,1);
glVertex3f(45.0,5.0,-55.52);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void osign(){//Open sign
initialiseTextures(13);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(6.0,3.0,-55.52);
glTexCoord2f(1,0);
glVertex3f(6.0,4.0,-55.52);
glTexCoord2f(0,0);
glVertex3f(18.0,4.0,-55.52);
glTexCoord2f(0,1);
glVertex3f(18.0,3.0,-55.52);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void door(){
initialiseTextures(10);
glEnable(GL_TEXTURE_2D);

//Front door from front
glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(20.0,0.0,-55.52);
glTexCoord2f(1,0);
glVertex3f(20.0,5.0,-55.52);
glTexCoord2f(0,0);
glVertex3f(45.0,5.0,-55.52);
glTexCoord2f(0,1);
glVertex3f(45.0,0.0,-55.52);
glEnd();

//Front door from inside
glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(20.0,0.0,-55.49);
glTexCoord2f(1,0);
glVertex3f(20.0,5.0,-55.49);
glTexCoord2f(0,0);
glVertex3f(45.0,5.0,-55.49);
glTexCoord2f(0,1);
glVertex3f(45.0,0.0,-55.49);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void wall(){
initialiseTextures(6);
glEnable(GL_TEXTURE_2D);

//Near wall
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(-6.0,0.0,-55.5);
glTexCoord2f(1,1);
glVertex3f(-6.0,9.0,-55.5);
glTexCoord2f(0,1);
glVertex3f(-6.0,9.0,25.5);
glTexCoord2f(0,0);
glVertex3f(-6.0,0.0,25.5);
glEnd();

//Far wall
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(89.0,0.0,-55.5);
glTexCoord2f(1,1);
glVertex3f(89.0,9.0,-55.5);
glTexCoord2f(0,1);
glVertex3f(89.0,9.0,25.5);
glTexCoord2f(0,0);
glVertex3f(89.0,0.0,25.5);
glEnd();

//Front wall inside
glBegin(GL_POLYGON);
glTexCoord2f(0,0);
glVertex3f(-6.0,0.0,-55.5);
glTexCoord2f(0,1);
glVertex3f(-6.0,9.0,-55.5);
glTexCoord2f(1,1);
glVertex3f(89.0,9.0,-55.5);
glTexCoord2f(1,0);
glVertex3f(89.0,0.0,-55.5);
glEnd();

initialiseTextures(15);
glBegin(GL_POLYGON);//Front wall outside
glTexCoord2f(0,0);
glVertex3f(-6.0,0.0,-55.51);
glTexCoord2f(0,1);
glVertex3f(-6.0,9.0,-55.51);
glTexCoord2f(1,1);
glVertex3f(89.0,9.0,-55.51);
glTexCoord2f(1,0);
glVertex3f(89.0,0.0,-55.51);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void floors(){
initialiseTextures(5);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(-6.0,0.0,-55.5);
glTexCoord2f(0,0);glVertex3f(89.0,0.0,-55.5);
glTexCoord2f(0,1);glVertex3f(89.0,0.0,25.5);
glTexCoord2f(1,1);glVertex3f(-6.0,0.0,25.5);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void chairs(){
initialiseTextures(14);
glEnable(GL_TEXTURE_2D);
//Left chair
glBegin(GL_POLYGON);//seat
glTexCoord2f(1,1);glVertex3f(-1.0,3.0,5.0);
glTexCoord2f(0,1);glVertex3f(5.0,3.0,5.0);
glTexCoord2f(0,0);glVertex3f(5.0,3.0,9.0);
glTexCoord2f(1,0);glVertex3f(-1.0,3.0,9.0);
glEnd();

//Back of the chair 1
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex3f(5,3.0,8.0);
glTexCoord2f(0,1);glVertex3f(5,5.0,8.0);
glTexCoord2f(1,1);glVertex3f(5,5.0,9.0);
glTexCoord2f(1,0);glVertex3f(5,3.0,9.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex3f(-1.0,3.0,8.0);
glTexCoord2f(0,1);glVertex3f(-1.0,5.0,8.0);
glTexCoord2f(1,1);glVertex3f(5,5.0,8.0);
glTexCoord2f(1,0);glVertex3f(5,3.0,8.0);
glEnd();

//Not necessary?
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(-1.0,3.0,8.0);
glTexCoord2f(1,1);glVertex3f(-1.0,5.0,8.0);
glTexCoord2f(0,1);glVertex3f(-1.0,5.0,9.0);
glTexCoord2f(0,0);glVertex3f(-1.0,3.0,9.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex3f(-1.0,3.0,9.0);
glTexCoord2f(0,1);glVertex3f(-1.0,5.0,9.0);
glTexCoord2f(1,1);glVertex3f(5,5.0,9.0);
glTexCoord2f(1,0);glVertex3f(5,3.0,9.0);
glEnd();
glDisable(GL_TEXTURE_2D);

//Goldenrod = color red 0.858824 green 0.858824 blue 0.439216
GLfloat legs[]={0.1,0.1,0.0,1.0}; glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,legs);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,legs);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,legs);
glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10.0);

//legs/1
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(4.5,0.0,5.0);
//glTexCoord2f(1,1);
glVertex3f(4.5,3.0,5.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,6.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,6.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,5.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,5.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,5.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,5.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,5.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,5.0);
//glTexCoord2f(0,1);
glVertex3f(3.5,3.0,6.0);
//glTexCoord2f(0,0);
glVertex3f(3.5,0.0,6.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,6.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,6.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,6.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,6.0);
glEnd();

//2
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(4.5,0.0,8.0);
//glTexCoord2f(1,1);
glVertex3f(4.5,3.0,8.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,9.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,9.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,8.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,8.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,8.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,8.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,8.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,8.0);
//glTexCoord2f(0,1);
glVertex3f(3.5,3.0,9.0);
//glTexCoord2f(0,0);
glVertex3f(3.5,0.0,9.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,9.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,9.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,9.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,9.0);
glEnd();

//3
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(0.5,0.0,5.0);
//glTexCoord2f(1,1);
glVertex3f(0.5,3.0,5.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,6.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,6.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,5.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,5.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,5.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,5.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,5.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,5.0);
//glTexCoord2f(0,1);
glVertex3f(-0.5,3.0,6.0);
//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,6.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,6.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,6.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,6.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,6.0);
glEnd();

//4
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(0.5,0.0,8.0);//glTexCoord2f(1,1);
glVertex3f(0.5,3.0,8.0);//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,9.0);//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,9.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,8.0);//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,8.0);//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,8.0);//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,8.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,8.0);//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,8.0);//glTexCoord2f(0,1);
glVertex3f(-0.5,3.0,9.0);//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,9.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,9.0);//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,9.0);//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,9.0);//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,9.0);
glEnd();

//right chair
glEnable(GL_TEXTURE_2D);
glBegin(GL_POLYGON);//seat
glTexCoord2f(0,0);glVertex3f(-1.0,3.0,-3.0);
glTexCoord2f(1,0);glVertex3f(5.0,3.0,-3.0);
glTexCoord2f(1,1);glVertex3f(5.0,3.0,-8.0);
glTexCoord2f(0,1);glVertex3f(-1.0,3.0,-8.0);
glEnd();

//Back of the chair 2
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(5,3.0,-8.0);
glTexCoord2f(1,1);glVertex3f(5,5.0,-8.0);
glTexCoord2f(0,1);glVertex3f(5,5.0,-7.0);
glTexCoord2f(0,0);glVertex3f(5,3.0,-7.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(-1.0,3.0,-7.0);
glTexCoord2f(1,1);glVertex3f(-1.0,5.0,-7.0);
glTexCoord2f(0,1);glVertex3f(5,5.0,-7.0);
glTexCoord2f(0,0);glVertex3f(5,3.0,-7.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(-1.0,3.0,-8.0);
glTexCoord2f(1,1);
glVertex3f(-1.0,5.0,-8.0);
glTexCoord2f(0,1);
glVertex3f(-1.0,5.0,-7.0);
glTexCoord2f(0,0);
glVertex3f(-1.0,3.0,-7.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(-1.0,3.0,-8.0);
glTexCoord2f(1,1);glVertex3f(-1.0,5.0,-8.0);
glTexCoord2f(0,1);glVertex3f(5,5.0,-8.0);
glTexCoord2f(0,0);glVertex3f(5,3.0,-8.0);
glEnd();
glDisable(GL_TEXTURE_2D);

glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,legs);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,legs);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,legs);
glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10.0);
//legs//1
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(0.5,0.0,-3.0);
//glTexCoord2f(1,1);
glVertex3f(0.5,3.0,-3.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,-4.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,-4.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,-3.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,-3.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,-3.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,-3.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,-3.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,-3.0);
//glTexCoord2f(0,1);
glVertex3f(-0.5,3.0,-4.0);
//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,-4.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,-4.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,-4.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,-4.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,-4.0);
glEnd();

//2
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(0.5,0.0,-7.0);
//glTexCoord2f(1,1);
glVertex3f(0.5,3.0,-7.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,-8.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,-8.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,-7.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,-7.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,-7.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,-7.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,-7.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,-7.0);
//glTexCoord2f(0,1);
glVertex3f(-0.5,3.0,-8.0);
//glTexCoord2f(0,0);
glVertex3f(-0.5,0.0,-8.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(-0.5,0.0,-8.0);
//glTexCoord2f(1,1);
glVertex3f(-0.5,3.0,-8.0);
//glTexCoord2f(0,1);
glVertex3f(0.5,3.0,-8.0);
//glTexCoord2f(0,0);
glVertex3f(0.5,0.0,-8.0);
glEnd();

//3
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(4.5,0.0,-7.0);
//glTexCoord2f(1,1);
glVertex3f(4.5,3.0,-7.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,-8.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,-8.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,-7.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,-7.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,-7.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,-7.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,-7.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,-7.0);
//glTexCoord2f(0,1);
glVertex3f(3.5,3.0,-8.0);
//glTexCoord2f(0,0);
glVertex3f(3.5,0.0,-8.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,-8.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,-8.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,-8.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,-8.0);
glEnd();

//4
glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(4.5,0.0,-3.0);
//glTexCoord2f(1,1);
glVertex3f(4.5,3.0,-3.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,-4.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,-4.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,-3.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,-3.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,-3.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,-3.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,-3.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,-3.0);
//glTexCoord2f(0,1);
glVertex3f(3.5,3.0,-4.0);
//glTexCoord2f(0,0);
glVertex3f(3.5,0.0,-4.0);
glEnd();

glBegin(GL_POLYGON);//glTexCoord2f(1,0);
glVertex3f(3.5,0.0,-4.0);
//glTexCoord2f(1,1);
glVertex3f(3.5,3.0,-4.0);
//glTexCoord2f(0,1);
glVertex3f(4.5,3.0,-4.0);
//glTexCoord2f(0,0);
glVertex3f(4.5,0.0,-4.0);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void pic1(){
initialiseTextures(16);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(-5.0,5.0,10.0);
glTexCoord2f(1,0);
glVertex3f(-5.0,6.5,10.0);
glTexCoord2f(0,0);
glVertex3f(-5.0,6.5,25.0);
glTexCoord2f(0,1);
glVertex3f(-5.0,5.0,25.0);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void pic2(){
initialiseTextures(17);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(-5.0,5.0,10.0);
glTexCoord2f(1,0);
glVertex3f(-5.0,6.5,10.0);
glTexCoord2f(0,0);
glVertex3f(-5.0,6.5,25.0);
glTexCoord2f(0,1);
glVertex3f(-5.0,5.0,25.0);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void Window(){
initialiseTextures(4);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(-5.0,4.5,-4.0);
glTexCoord2f(1,0);
glVertex3f(-5.0,7.0,-4.0);
glTexCoord2f(0,0);
glVertex3f(-5.0,7.0,5.0);
glTexCoord2f(0,1);
glVertex3f(-5.0,4.5,5.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,1);
glVertex3f(-5.0,4.5,30.0);
glTexCoord2f(1,0);
glVertex3f(-5.0,7.0,30.0);
glTexCoord2f(0,0);
glVertex3f(-5.0,7.0,40.0);
glTexCoord2f(0,1);
glVertex3f(-5.0,4.5,40.0);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void pizzab(){//pizzas on the buffet bar
initialiseTextures(1);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,15.0);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,15.0);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,7.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,7.0);
glEnd();

initialiseTextures(7);
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,7);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,7);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,0.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,0.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,-0);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,-0);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,-7.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,-7.0);
glEnd();

initialiseTextures(8);
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,-7.0);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,-7.0);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,-14.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,-14.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,-14.0);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,-14.0);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,-21.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,-21.0);
glEnd();

initialiseTextures(9);
glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,-21.0);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,-21.0);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,-28.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,-28.0);
glEnd();

glBegin(GL_POLYGON);
glTexCoord2f(1,0);glVertex3f(4.5,2.51,-28.0);
glTexCoord2f(1,1);glVertex3f(-4.5,2.51,-28.0);
glTexCoord2f(0,1);glVertex3f(-4.5,2.51,-35.0);
glTexCoord2f(0,0);glVertex3f(4.5,2.51,-35.0);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void buffet(){
initialiseTextures(12);
glEnable(GL_TEXTURE_2D);

//back
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(-5.0,0.0,-35.0);
glTexCoord2f(1,1);
glVertex3f(-5.0,2.5,-35.0);
glTexCoord2f(0,1);
glVertex3f(-5.0,2.5,15.0);
glTexCoord2f(0,0);
glVertex3f(-5.0,0.0,15.0);
glEnd();

//front
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(5.0,0.0,-35.0);
glTexCoord2f(1,1);
glVertex3f(5.0,2.5,-35.0);
glTexCoord2f(0,1);
glVertex3f(5.0,2.5,15.0);
glTexCoord2f(0,0);
glVertex3f(5.0,0.0,15.0);
glEnd();

//right
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(-5.0,0.0,-35.0);
glTexCoord2f(1,1);
glVertex3f(-5.0,2.5,-35.0);
glTexCoord2f(0,1);
glVertex3f(5.0,2.5,-35.0);
glTexCoord2f(0,0);
glVertex3f(5.0,0.0,-35.0);
glEnd();

//left
glBegin(GL_POLYGON);
glTexCoord2f(1,0);
glVertex3f(-5.0,0.0,15.0);
glTexCoord2f(1,1);
glVertex3f(-5.0,2.5,15.0);
glTexCoord2f(0,1);
glVertex3f(5.0,2.5,15.0);
glTexCoord2f(0,0);
glVertex3f(5.0,0.0,15.0);
glEnd();
glDisable(GL_TEXTURE_2D);

GLfloat col[]={1,1,1,1.0};//Top of the buffet bar
glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,col);
glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,col);
glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,col);
glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,10.0);
glBegin(GL_POLYGON);
glVertex3f(-5.0,2.5,15.0);
glVertex3f(-5.0,2.5,-35.0);
glVertex3f(5.0,2.5,-35.0);
glVertex3f(5.0,2.5,15.0);
glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(xspot,0.2,zspot,xlook,0.0,zlook,0.0,1.0,0.0);
	wall();
	door();
	osign();
	sign();
	floors();
	glPushMatrix();

	glTranslatef(0,0,22);
	glLightfv(GL_LIGHT0,GL_POSITION,light);
	glPopMatrix();

	glPushMatrix();//Draw near set of tables
	glRotatef(90,0,1,0);
	glLightfv(GL_LIGHT1,GL_POSITION,light1);
	table();pizza();silverware();
	plates();glass();
	glPopMatrix();
	chairs();
	glPushMatrix();
	glTranslatef(0,0,-35);
	glPushMatrix();
	glRotatef(90,0,1,0);
	glLightfv(GL_LIGHT1,GL_POSITION,light1);
	table();pizza();silverware();
	plates();glass();
	glPopMatrix();
	chairs();
	Window();
	pic1();

	//Shift to draw the buffet
	glPopMatrix();
	glPushMatrix();
	glTranslatef(40,0,0);
	buffet();
	pizzab();

	//Shift to draw tables at the other end
	glTranslatef(40,0,-34);
	glRotatef(180,0,1,0);
	glPushMatrix();

	glTranslatef(0,0,22);
	glLightfv(GL_LIGHT0,GL_POSITION,light);
	glPopMatrix();

	glPushMatrix();//draw far set of tables
	glRotatef(90,0,1,0);
	glLightfv(GL_LIGHT1,GL_POSITION,light1);
	table();pizza();silverware();
	plates();glass();
	glPopMatrix();
	chairs();
	glPushMatrix();
	glTranslatef(0,0,-35);
	glPushMatrix();
	glRotatef(90,0,1,0);
	glLightfv(GL_LIGHT1,GL_POSITION,light1);
	table();pizza();silverware();
	plates();glass();
	glPopMatrix();
	chairs();
	Window();
	pic2();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h){
glViewport(0,0,w,h);glMatrixMode(GL_PROJECTION);
glLoadIdentity();glOrtho(-25.0,50.0,-1.0,8.0,-40.0,40.0);
}

void Keyboard(unsigned char k, int x, int y){
if(k == '1'){//near side tables
move=1;
xspot=2;
xlook=-2;
zspot=-5;
zlook=-5;
}
else if(k=='2'){//Far side tables
move=1;
xspot=62.0;
zspot=-28.0;
xlook=65.0;
zlook=-28.0;
}
else if(k=='3'){//The front door
move=0;
xspot=42.0;
zspot=-60.0;
xlook=42.0;
zlook=-55.0;
}
else if(k=='4'){
move=0;
xspot=39.0;
zspot=-0.0;
xlook=38.0;
zlook=-0.0;
}
else if(k=='d'){
if(move==1)
zspot-=1;
}
else if(k=='a'){
if(move==1)
zspot+=1;
}

glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glEnable(GL_DEPTH_TEST);glEnable(GL_TEXTURE_2D);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glDepthMask(GL_TRUE);glDepthFunc(GL_LEQUAL);
	glDepthRange(0.0f, 1.0f);
	glutInitWindowSize(450,450);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Pizza Dinner");
	glutDisplayFunc(display);glutReshapeFunc(reshape);
	glutKeyboardFunc(Keyboard);
	init();
	glutMainLoop();
}
