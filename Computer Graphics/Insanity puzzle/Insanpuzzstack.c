#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <stdio.h>
int xstate=0;
int zstate=0;
double xpos=0.9;
double zpos=0.0;
double ypos=0.3;
double camera=0;

void init(){
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glEnable(GL_CULL_FACE);
glFrontFace(GL_CCW);
glCullFace(GL_BACK);
}

void sq1(){
//Square 1
glColor3f(1.0,1.0,1.0);//Bottom
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0, 0.0);
glVertex3f(-1.0,-1.0,2.0);
glVertex3f(-3.0,-1.0,2.0);
glVertex3f(-3.0,-1.0,0.0);
glEnd();

glColor3f(1.0,0.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,2.0);
glVertex3f(-1.0,1.0,2.0);
glVertex3f(-3.0,1.0,2.0);
glVertex3f(-3.0,-1.0,2.0);
glEnd();

glColor3f(1.0,0.0,0.0);//Back
glBegin(GL_POLYGON);
glVertex3f(-3.0,-1.0,0.0);
glVertex3f(-3.0,-1.0,2.0);
glVertex3f(-3.0,1.0,2.0);
glVertex3f(-3.0,1.0,0.0);
glEnd();

glColor3f(0.0,0.0,1.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-3.0,1.0,2.0);
glVertex3f(-1.0,1.0,2.0);
glEnd();

glColor3f(1.0,0.0,0.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.0);
glVertex3f(-3.0,-1.0,0.0);
glVertex3f(-3.0,1.0,0.0);
glVertex3f(-1.0,1.0,0.0);
glEnd();

glColor3f(0.0,1.0,0.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.0,-1.0,0.0);
glVertex3f(-1.0,1.0,0.0);
glVertex3f(-1.0,1.0,2.0);
glVertex3f(-1.0,-1.0,2.0);
glEnd();
}

//Square 2
void sq2(){
glColor3f(0.0,1.0,0.0);//Bottom
glBegin(GL_POLYGON);
glVertex3f(-1.2,1.3,0.2);
glVertex3f(-1.2,1.3,1.8);
glVertex3f(-2.8,1.3,1.8);
glVertex3f(-2.8,1.3,0.2);
glEnd();

glColor3f(1.0,1.0,1.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.2,1.3,1.8);
glVertex3f(-1.2,2.8,1.8);
glVertex3f(-2.8,2.8,1.8);
glVertex3f(-2.8,1.3,1.8);
glEnd();

glColor3f(1.0,1.0,1.0);//Back
glBegin(GL_POLYGON);
glVertex3f(-2.8,1.3,0.2);
glVertex3f(-2.8,1.3,1.8);
glVertex3f(-2.8,2.8,1.8);
glVertex3f(-2.8,2.8,0.2);
glEnd();

glColor3f(1.0,0.0,0.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.2,2.8,0.2);
glVertex3f(-2.8,2.8,0.2);
glVertex3f(-2.8,2.8,1.8);
glVertex3f(-1.2,2.8,1.8);
glEnd();

glColor3f(0.0,1.0,0.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.2,1.3,0.2);
glVertex3f(-2.8,1.3,0.2);
glVertex3f(-2.8,2.8,0.2);
glVertex3f(-1.2,2.8,0.2);
glEnd();

glColor3f(0.0,0.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.2,1.3,0.2);
glVertex3f(-1.2,2.8,0.2);
glVertex3f(-1.2,2.8,1.8);
glVertex3f(-1.2,1.3,1.8);
glEnd();
}

void sq3(){
//Square 3
glColor3f(1.0,0.0,0.0);//Bottom
glBegin(GL_POLYGON);
glVertex3f(-1.5,3.0,0.5);
glVertex3f(-1.5,3.0,1.5);
glVertex3f(-2.5,3.0,1.5);
glVertex3f(-2.5,3.0,0.5);
glEnd();

glColor3f(0.0,1.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.5,3.0,1.5);
glVertex3f(-1.5,4.2,1.5);
glVertex3f(-2.5,4.2,1.5);
glVertex3f(-2.5,3.0,1.5);
glEnd();

glColor3f(0.0,0.0,1.0);//Back
glBegin(GL_POLYGON);
glVertex3f(-2.5,3.0,0.5);
glVertex3f(-2.5,3.0,1.5);
glVertex3f(-2.5,4.2,1.5);
glVertex3f(-2.5,4.2,0.5);
glEnd();

glColor3f(1.0,1.0,1.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.5,4.2,0.5);
glVertex3f(-2.5,4.2,0.5);
glVertex3f(-2.5,4.2,1.5);
glVertex3f(-1.5,4.2,1.5);
glEnd();

glColor3f(1.0,1.0,1.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.5,3.0,0.5);
glVertex3f(-2.5,3.0,0.5);
glVertex3f(-2.5,4.2,0.5);
glVertex3f(-1.5,4.2,0.5);
glEnd();

glColor3f(1.0,0.0,0.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.5,3.0,0.5);
glVertex3f(-1.5,4.2,0.5);
glVertex3f(-1.5,4.2,1.5);
glVertex3f(-1.5,3.0,1.5);
glEnd();
}

void sq4(){
//Square 4
glColor3f(0.0,0.0,1.0);//Bottom
glBegin(GL_POLYGON);
glVertex3f(-1.6,4.5,0.7);
glVertex3f(-1.6,4.5,1.3);
glVertex3f(-2.3,4.5,1.3);
glVertex3f(-2.3,4.5,0.7);
glEnd();

glColor3f(1.0,0.0,0.0);//Left side
glBegin(GL_POLYGON);
glVertex3f(-1.6,4.5,1.3);
glVertex3f(-1.6,5.2,1.3);
glVertex3f(-2.3,5.2,1.3);
glVertex3f(-2.3,4.5,1.3);
glEnd();

glColor3f(1.0,1.0,1.0);//Back
glBegin(GL_POLYGON);
glVertex3f(-2.3,4.5,0.7);
glVertex3f(-2.3,4.5,1.3);
glVertex3f(-2.3,5.2,1.3);
glVertex3f(-2.3,5.2,0.7);
glEnd();

glColor3f(0.0,1.0,0.0);//Top
glBegin(GL_POLYGON);
glVertex3f(-1.6,5.2,0.7);
glVertex3f(-2.3,5.2,0.7);
glVertex3f(-2.3,5.2,1.3);
glVertex3f(-1.6,5.2,1.3);
glEnd();

glColor3f(0.0,0.0,1.0);//right side
glBegin(GL_POLYGON);
glVertex3f(-1.6,4.5,0.7);
glVertex3f(-2.3,4.5,0.7);
glVertex3f(-2.3,5.2,0.7);
glVertex3f(-1.6,5.2,0.7);
glEnd();

glColor3f(1.0,1.0,1.0);//front
glBegin(GL_POLYGON);
glVertex3f(-1.6,4.5,0.7);
glVertex3f(-1.6,5.2,0.7);
glVertex3f(-1.6,5.2,1.3);
glVertex3f(-1.6,4.5,1.3);
glEnd();

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
//The camera
gluLookAt(xpos,ypos,zpos,0.0,0.0,0.0,0.0,1.0,0.0);

glRotatef(camera,0.0f,-1.0f,0.0f);
sq1();
sq2();
sq3();
sq4();
glPushMatrix();

glutSwapBuffers();

	glFlush();
}


void reshape(int w, int h){
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-5.0,5.0,-2.0,7.0,-5.0,6.0);
}

void mouseClick(int button,int state,int x,int y){
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
//glRotatef(20.0,0.0f,1.0f,0.0f);
ypos+=.1;
//camera+=4;
}
else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
ypos-=.1;
//camera-=4;
}
glutPostRedisplay();
}

void Keyboard(unsigned char k, int x, int y){
if(k=='a' || k=='A'){
camera+=5;
}//end A


else if(k=='d' || k=='D'){//begin d
camera-=5;
}//end d

glutPostRedisplay();
}

void idle(){

//glPushMatrix();
//glRotatef(45.5,0,1,0);

glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);	
	glutInitWindowSize(450,450);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Insanity Puzzle Stack");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(idle);
	init();
	glutMainLoop();
}
