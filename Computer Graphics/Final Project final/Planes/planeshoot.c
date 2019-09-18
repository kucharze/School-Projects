#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <stdio.h>

int spot=0;
int location=0;
int time=0;
double h=0.4;

int state=0;
int e1=0;
int e2=0;
int shoot=0;
double planeb1=16;
double planeb2=19;
double us=7.5;
double target=7.5;//7.5 or 5
double treestump=14;
double treeleaves=13;
double treestump2=25;
double treeleaves2=24;
double cl=21;
double cl2=30;
double rx=6;
double ry=8;

#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>

#define DEFAULT_WIDTH  600
#define DEFAULT_HEIGHT 510
 
int width  = DEFAULT_WIDTH;
int height = DEFAULT_HEIGHT;

typedef GLubyte Pixel[3]; /*represents red green blue*/

int Width, Height; /*of image*/

/*array of pixels*/
Pixel *Image;

/*name of image file*/
char *Filename = "./planeg.ppm";
char *Filename1 = "./planeb.ppm";
char *Filename2 = "./bark.ppm";
char *Filename3 = "./leaves.ppm";
char *Filename4 = "./explosion.ppm";
char *Filename5 = "./rocket.ppm";
char *Filename6 = "./go.ppm";
char *Filename7 = "./cloud.ppm";

int allowedSize(int x)/*returns max power of 2 <= x*/
{
	int r;r = 1;
	while(r < x) r=(r<<1);
	
	if(r==x) return r;	
	else return r>>1;
}
/*reads image file assumes ppm format*/
void readImage(int p){	
	int w,h,max;int i,j;
	unsigned int r,g,b,al;
	int k;char ch;FILE *fp;
	
	if(p==0){fp = fopen(Filename,"r");}
	if(p==1){fp = fopen(Filename1,"r");}
	if(p==2){fp = fopen(Filename2,"r");}
	if(p==3){fp = fopen(Filename3,"r");}
	if(p==4){fp = fopen(Filename4,"r");}
	if(p==5){fp = fopen(Filename5,"r");}
	if(p==6){fp = fopen(Filename6,"r");}
	if(p==7){fp = fopen(Filename7,"r");}


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
	
	/*read the given image file*/
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
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,20.0,0.0,13.0);
srand((unsigned) 500);
}

void planeg(){//Our plane
initialiseTextures(0);
glEnable(GL_TEXTURE_2D);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glTexCoord2f(1,1);glVertex2f(0.3,us);
glTexCoord2f(1,0);glVertex2f(0.3,us+2);
glTexCoord2f(0,0);glVertex2f(4.0,us+2);
glTexCoord2f(0,1);glVertex2f(4.0,us);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void planebad1(){//Enemy plane 1
if(e1==0){initialiseTextures(1);}
else{initialiseTextures(4);}
glEnable(GL_TEXTURE_2D);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(planeb1,7.5);
glTexCoord2f(0,1);glVertex2f(planeb1,9.5);
glTexCoord2f(1,1);glVertex2f(planeb1+3,9.5);
glTexCoord2f(1,0);glVertex2f(planeb1+3,7.5);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void planebad2(){//Enemy plane 2
if(e2==0){initialiseTextures(1);}
else{initialiseTextures(4);}
glEnable(GL_TEXTURE_2D);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(planeb2,5.0);
glTexCoord2f(0,1);glVertex2f(planeb2,7.0);
glTexCoord2f(1,1);glVertex2f(planeb2+3,7.0);
glTexCoord2f(1,0);glVertex2f(planeb2+3,5.0);
glEnd();

glDisable(GL_TEXTURE_2D);
}

void rocket(){
initialiseTextures(5);
glEnable(GL_TEXTURE_2D);
if(shoot==1){
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(rx-2,ry);
glTexCoord2f(0,1);glVertex2f(rx-2,ry+1);
glTexCoord2f(1,1);glVertex2f(rx,ry+1);
glTexCoord2f(1,0);glVertex2f(rx,ry);
glEnd();
}
else{
rx=-1;
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(rx-1,-1);
glTexCoord2f(0,1);glVertex2f(rx-1,-1);
glTexCoord2f(1,1);glVertex2f(rx,-1);
glTexCoord2f(1,0);glVertex2f(rx,-1);
glEnd();
}
glDisable(GL_TEXTURE_2D);
}

void ground(){
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,0.0);
glVertex2f(0,1.0);
glVertex2f(20.0,1.0);
glVertex2f(20.0,0.0);
glEnd();
}

void tree(){
initialiseTextures(2);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(treestump,1.0);
glTexCoord2f(0,1);glVertex2f(treestump,1.5);
glTexCoord2f(1,1);glVertex2f(treestump+1.0,1.5);
glTexCoord2f(1,0);glVertex2f(treestump+1,1.0);
glEnd();

initialiseTextures(3);
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(treeleaves,1.5);
glTexCoord2f(0.5,1);glVertex2f(treeleaves+1.5,4.0);
glTexCoord2f(1,0);glVertex2f(treeleaves+3,1.5);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void tree2(){
initialiseTextures(2);
glEnable(GL_TEXTURE_2D);

glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(treestump2,1.0);
glTexCoord2f(0,1);glVertex2f(treestump2,1.5);
glTexCoord2f(1,1);glVertex2f(treestump2+1.0,1.5);
glTexCoord2f(1,0);glVertex2f(treestump2+1,1.0);
glEnd();

initialiseTextures(3);
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(treeleaves2,1.5);
glTexCoord2f(0.5,1);glVertex2f(treeleaves2+1.5,4.0);
glTexCoord2f(1,0);glVertex2f(treeleaves2+3,1.5);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void cloud(){
initialiseTextures(7);
glEnable(GL_TEXTURE_2D);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glTexCoord2f(1,1);glVertex2f(cl,11.0);
glTexCoord2f(1,0);glVertex2f(cl,12.0);
glTexCoord2f(0,0);glVertex2f(cl+3,12.0);
glTexCoord2f(0,1);glVertex2f(cl+3,11.0);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void cloud2(){
initialiseTextures(7);
glEnable(GL_TEXTURE_2D);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glTexCoord2f(1,1);glVertex2f(cl2,11.0);
glTexCoord2f(1,0);glVertex2f(cl2,12.0);
glTexCoord2f(0,0);glVertex2f(cl2+3,12.0);
glTexCoord2f(0,1);glVertex2f(cl2+3,11.0);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void sun(){
glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-2,10.0);
glVertex2f(-2,14.0);
glVertex2f(3,14.0);
glVertex2f(1,11.0);
glEnd();
}

void gameover(){
initialiseTextures(6);
glEnable(GL_TEXTURE_2D);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glTexCoord2f(0,0);glVertex2f(1,1.0);
glTexCoord2f(0,1);glVertex2f(1,14.0);
glTexCoord2f(1,1);glVertex2f(19,14.0);
glTexCoord2f(1,0);glVertex2f(19,1.0);
glEnd();
glDisable(GL_TEXTURE_2D);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

planeg();
planebad1();
planebad2();
rocket();
cloud();
cloud2();
sun();
tree();
tree2();
ground();
if(state==1){gameover();}
glFlush();
}

void mouseClick(int button,int state,int x,int y){
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
if(target==7.5){
shoot=1;
rx=6;
ry=8;
}

if(target==5){
shoot=1;
rx=6;
ry=5.5;
}
}
glutPostRedisplay();
}

void Keyboard(unsigned char k, int x, int y){
if(k == 'w'){//near side tables
target=7.5;
}
else if(k =='s'){
target=5;
}

glutPostRedisplay();
}


void idle(){//Handle animations
//time++;

if(state==0){
//move plane to where it should be
if(us>target){us-=.3;}
if(us<target){us+=.3;}

//move necessary objects
if(e1==0){planeb1=planeb1-.1;}
else{e1++;}
if(e2==0){planeb2=planeb2-.1;}
else{e2++;}
treestump-=.2;
treeleaves-=.2;
treestump2-=.2;
treeleaves2-=.2;
rx=rx+.3;
cl=cl-.1;
cl2=cl2-.1;

if(rx>planeb1 && ry>6){shoot=0;e1=1;}
if(rx>planeb2 && ry<6){shoot=0;e2=2;}
if(planeb1 < 4.0){state=1;}
if(planeb2 < 4.0){state=1;}
if(cl<-4){cl=21.0;}
if(cl2<-4){cl2=21.0;}
if(treeleaves<-2){
treeleaves=21;
treestump=22;
}
if(treeleaves2<-2){
treeleaves2=21;
treestump2=22;
}
if(e1>10){e1=0; planeb1=20;}
if(e2>10){e2=0; planeb2=20;}

}//end state0

glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(400,400);
	glutCreateWindow("Planeshooter");
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutIdleFunc(idle);
	glutKeyboardFunc(Keyboard);
	init();
	glutMainLoop();
}
