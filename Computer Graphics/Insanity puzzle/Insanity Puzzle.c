#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <stdio.h>
int stance=0;
double xpos=0;
double zpos=-0.3;

void init(){
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}

void sep(){
if(zpos<0){
//Square 1
glColor3f(1.0,0.0,0.0);//left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,5.0);
glVertex3f(-1.0,1.0,5.0);
glVertex3f(-3.0,1.0,5.0);
glVertex3f(-3.0,-1.0,5.0);
glEnd();

glColor3f(1.0,0.0,0.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,3.0);
glVertex3f(-1.0,1.0,3.0);
glVertex3f(-3.0,1.0,3.0);
glVertex3f(-3.0,-1.0,3.0);
glEnd();

glColor3f(0.0,0.0,1.0);//top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,5.0);
glVertex3f(-1.0,1.0,3.0);
glVertex3f(-3.0,1.0,3.0);
glVertex3f(-3.0,1.0,5.0);
glEnd();

glColor3f(0.0,1.0,0.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,3.0);
glVertex3f(-1.0,1.0,3.0);
glVertex3f(-1.0,1.0,5.0);
glVertex3f(-1.0,-1.0,5.0);
glEnd();

//Square 2
glColor3f(1.0,1.0,1.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,2.5);
glVertex3f(-1.0,1.0,2.5);
glVertex3f(-3.0,1.0,2.5);
glVertex3f(-3.0,-1.0,2.5);
glEnd();

glColor3f(0.0,1.0,0.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.5);
glVertex3f(-1.0,1.0,0.5);
glVertex3f(-3.0,1.0,0.5);
glVertex3f(-3.0,-1.0,0.5);
glEnd();

glColor3f(1.0,0.0,0.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,0.5);
glVertex3f(-1.0,1.0,2.5);
glVertex3f(-3.0,1.0,2.5);
glVertex3f(-3.0,1.0,0.5);
glEnd();

glColor3f(0.0,0.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.5);
glVertex3f(-1.0,1.0,0.5);
glVertex3f(-1.0,1.0,2.5);
glVertex3f(-1.0,-1.0,2.5);
glEnd();

//Square 3
glColor3f(0.0,1.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-3.0,-1.0,0.0);
glEnd();

glColor3f(1.0,1.0,1.0);//Right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.0);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-3.0,1.0,-2.0);
glVertex3f(-3.0,-1.0,-2.0);
glEnd();

glColor3f(1.0,1.0,1.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-3.0,1.0,-2.0);
glEnd();

glColor3f(1.0,0.0,0.0);//Front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.0);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,-1.0,0.0);
glEnd();

//Square 4
glColor3f(1.0,0.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.5);
glVertex3f(-1.0,1.0,-2.5);
glVertex3f(-3.0,1.0,-2.5);
glVertex3f(-3.0,-1.0,-2.5);
glEnd();

glColor3f(0.0,0.0,1.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-4.5);
glVertex3f(-1.0,1.0,-4.5);
glVertex3f(-3.0,1.0,-4.5);
glVertex3f(-3.0,-1.0,-4.5);
glEnd();

glColor3f(0.0,1.0,0.0);//top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,-2.5);
glVertex3f(-1.0,1.0,-4.5);
glVertex3f(-3.0,1.0,-4.5);
glVertex3f(-3.0,1.0,-2.5);
glEnd();

glColor3f(1.0,1.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.5);
glVertex3f(-1.0,1.0,-2.5);
glVertex3f(-1.0,1.0,-4.5);
glVertex3f(-1.0,-1.0,-4.5);
glEnd();
}

else{
//Square 4
glColor3f(0.0,0.0,1.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-4.5);
glVertex3f(-1.0,1.0,-4.5);
glVertex3f(-3.0,1.0,-4.5);
glVertex3f(-3.0,-1.0,-4.5);
glEnd();

glColor3f(1.0,0.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.5);
glVertex3f(-1.0,1.0,-2.5);
glVertex3f(-3.0,1.0,-2.5);
glVertex3f(-3.0,-1.0,-2.5);
glEnd();

glColor3f(0.0,1.0,0.0);//top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,-2.5);
glVertex3f(-1.0,1.0,-4.5);
glVertex3f(-3.0,1.0,-4.5);
glVertex3f(-3.0,1.0,-2.5);
glEnd();

glColor3f(1.0,1.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.5);
glVertex3f(-1.0,1.0,-2.5);
glVertex3f(-1.0,1.0,-4.5);
glVertex3f(-1.0,-1.0,-4.5);
glEnd();

//Square 3
glColor3f(1.0,1.0,1.0);//Right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.0);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-3.0,1.0,-2.0);
glVertex3f(-3.0,-1.0,-2.0);
glEnd();

glColor3f(0.0,1.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-3.0,-1.0,0.0);
glEnd();

glColor3f(1.0,1.0,1.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-3.0,1.0,-2.0);
glEnd();

glColor3f(1.0,0.0,0.0);//Front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.0);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,-1.0,0.0);
glEnd();

//Square 2
glColor3f(0.0,1.0,0.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.5);
glVertex3f(-1.0,1.0,0.5);
glVertex3f(-3.0,1.0,0.5);
glVertex3f(-3.0,-1.0,0.5);
glEnd();

glColor3f(1.0,1.0,1.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,2.5);
glVertex3f(-1.0,1.0,2.5);
glVertex3f(-3.0,1.0,2.5);
glVertex3f(-3.0,-1.0,2.5);
glEnd();

glColor3f(1.0,0.0,0.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,0.5);
glVertex3f(-1.0,1.0,2.5);
glVertex3f(-3.0,1.0,2.5);
glVertex3f(-3.0,1.0,0.5);
glEnd();

glColor3f(0.0,0.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.5);
glVertex3f(-1.0,1.0,0.5);
glVertex3f(-1.0,1.0,2.5);
glVertex3f(-1.0,-1.0,2.5);
glEnd();

//Square 1
glColor3f(1.0,0.0,0.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,3.0);
glVertex3f(-1.0,1.0,3.0);
glVertex3f(-3.0,1.0,3.0);
glVertex3f(-3.0,-1.0,3.0);
glEnd();

glColor3f(1.0,0.0,0.0);//left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,5.0);
glVertex3f(-1.0,1.0,5.0);
glVertex3f(-3.0,1.0,5.0);
glVertex3f(-3.0,-1.0,5.0);
glEnd();

glColor3f(0.0,0.0,1.0);//top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,5.0);
glVertex3f(-1.0,1.0,3.0);
glVertex3f(-3.0,1.0,3.0);
glVertex3f(-3.0,1.0,5.0);
glEnd();

glColor3f(0.0,1.0,0.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,3.0);
glVertex3f(-1.0,1.0,3.0);
glVertex3f(-1.0,1.0,5.0);
glVertex3f(-1.0,-1.0,5.0);
glEnd();
}

}

void tog(){
//Square 1
glColor3f(0.0,1.0,0.0);//Front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,2.0);
glVertex3f(-1.0,1.0,2.0);
glVertex3f(-1.0,1.0,4.0);
glVertex3f(-1.0,-1.0,4.0);
glEnd();

if(zpos>0){
glColor3f(1.0,0.0,0.0);//left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,4.0);
glVertex3f(-1.0,1.0,4.0);
glVertex3f(-3.0,1.0,4.0);
glVertex3f(-3.0,-1.0,4.0);
glEnd();
}
glColor3f(0.0,0.0,1.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,4.0);
glVertex3f(-1.0,1.0,2.0);
glVertex3f(-3.0,1.0,2.0);
glVertex3f(-3.0,1.0,4.0);
glEnd();

//Square 2
glColor3f(0.0,0.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,1.0,2.0);
glVertex3f(-1.0,-1.0,2.0);
glEnd();

glColor3f(1.0,0.0,0.0);//top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,1.0,2.0);
glVertex3f(-3.0,1.0,2.0);
glVertex3f(-3.0,1.0,0.0);
glEnd();

//Square 3
glColor3f(1.0,0.0,0.0);//Front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.0);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,-1.0,0.0);
glEnd();

glColor3f(1.0,1.0,1.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-3.0,1.0,-2.0);
glEnd();

//Square 4
glColor3f(1.0,1.0,1.0);//Front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-2.0);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,-4.0);
glVertex3f(-1.0,-1.0,-4.0);
glEnd();

if(zpos<0){
glColor3f(0.0,0.0,1.0);//Right
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,-4.0);
glVertex3f(-1.0,1.0,-4.0);
glVertex3f(-3.0,1.0,-4.0);
glVertex3f(-3.0,-1.0,-4.0);
glEnd();
}
glColor3f(0.0,1.0,0.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,-2.0);
glVertex3f(-1.0,1.0,-4.0);
glVertex3f(-3.0,1.0,-4.0);
glVertex3f(-3.0,1.0,-2.0);
glEnd();

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
//The camera
gluLookAt(1.0,0.4,zpos,0.0,0.0,0.0,0.0,1.0,0.0);

if(stance==1){
sep();
}

else {
tog();
}

glutSwapBuffers();

	glFlush();
}


void reshape(int w, int h){
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-6.0,6.0,-4.0,4.0,-5.0,5.0);
}

void mouseClick(int button,int state,int x,int y){
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
if(stance==0){
  stance=1;
}
else{
  stance=0;
}

}
//printf("%d\n", stance);
glutPostRedisplay();
}

void Keyboard(unsigned char k, int x, int y){
if(k == 'a' || k =='A'){
zpos=zpos+.2;
}
else if(k=='d' || k=='D'){
zpos=zpos-.2;
}
glutPostRedisplay();

}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Insanity Puzzle");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutKeyboardFunc(Keyboard);
	init();
	glutMainLoop();
}
