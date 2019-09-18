#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <stdio.h>

int spot=0;
int time=1;
double h=0.4;

void init(){
glClearColor(0.0,0.7,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,10.0,0.0,10.0);
srand((unsigned) 500);
}


void drawMole(){
//printf("Printing mole and spot %d\n",spot);

if(spot==0){//draw the mole offscreen
glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(10.5,7.5);
		glVertex2f(10.5,9.0);
		glVertex2f(10.5,9.0);
		glVertex2f(10.5,7.5);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(10.6,8.8);
		glVertex2f(10.6,8.6);
		glVertex2f(10.8,8.6);
		glVertex2f(10.8,8.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(10.2,8.8);
		glVertex2f(10.2,8.6);
		glVertex2f(10.4,8.6);
		glVertex2f(10.4,8.8);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(10.7,8.3);
		glVertex2f(10.3,8.3);
		glVertex2f(10.3,8.4);
		glVertex2f(10.7,8.4);
	glEnd();

}
else if(spot==1){//Top right hole
if(h > 0.0){
h=h-.001;
}

glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.5,7.5-h);
		glVertex2f(7.5,9.0-h);
		glVertex2f(8.5,9.0-h);
		glVertex2f(8.5,7.5-h);
	glEnd();

glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.5,9.0-h);
		glVertex2f(7.5,9.3-h);
		glVertex2f(7.7,9.3-h);
		glVertex2f(7.7,9.0-h);
	glEnd();

glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(8.3,9.0-h);
		glVertex2f(8.3,9.3-h);
		glVertex2f(8.5,9.3-h);
		glVertex2f(8.5,9.0-h);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.6,8.8-h);
		glVertex2f(7.6,8.6-h);
		glVertex2f(7.8,8.6-h);
		glVertex2f(7.8,8.8-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.2,8.8-h);
		glVertex2f(8.2,8.6-h);
		glVertex2f(8.4,8.6-h);
		glVertex2f(8.4,8.8-h);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.7,8.35-h);
		glVertex2f(8.3,8.35-h);
		glVertex2f(8.3,8.4-h);
		glVertex2f(7.7,8.4-h);
	glEnd();

}

else if(spot==2){//Top left hole
if(h > 0.0){
h=h-.001;
}

glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.5,7.5-h);
		glVertex2f(1.5,9.0-h);
		glVertex2f(2.5,9.0-h);
		glVertex2f(2.5,7.5-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(1.5,9.0-h);
		glVertex2f(1.5,9.3-h);
		glVertex2f(1.7,9.3-h);
		glVertex2f(1.7,9.0-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.3,9.0-h);
		glVertex2f(2.3,9.3-h);
		glVertex2f(2.5,9.3-h);
		glVertex2f(2.5,9.0-h);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.6,8.8-h);
		glVertex2f(1.6,8.6-h);
		glVertex2f(1.8,8.6-h);
		glVertex2f(1.8,8.8-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.2,8.8-h);
		glVertex2f(2.2,8.6-h);
		glVertex2f(2.4,8.6-h);
		glVertex2f(2.4,8.8-h);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.7,8.35-h);
		glVertex2f(2.3,8.35-h);
		glVertex2f(2.3,8.4-h);
		glVertex2f(1.7,8.4-h);
	glEnd();

}
else if(spot==3){//bottom left hole
if(h > 0.0){
h=h-.001;
}

glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.5,2.5-h);
		glVertex2f(1.5,4.0-h);
		glVertex2f(2.5,4.0-h);
		glVertex2f(2.5,2.5-h);
	glEnd();


	glBegin(GL_POLYGON);
		glVertex2f(1.5,4.0-h);
		glVertex2f(1.5,4.3-h);
		glVertex2f(1.7,4.3-h);
		glVertex2f(1.7,4.0-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.3,4.0-h);
		glVertex2f(2.3,4.3-h);
		glVertex2f(2.5,4.3-h);
		glVertex2f(2.5,4.0-h);
	glEnd();


glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.6,3.8-h);
		glVertex2f(1.6,3.6-h);
		glVertex2f(1.8,3.6-h);
		glVertex2f(1.8,3.8-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.2,3.8-h);
		glVertex2f(2.2,3.6-h);
		glVertex2f(2.4,3.6-h);
		glVertex2f(2.4,3.8-h);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.7,3.35-h);
		glVertex2f(2.3,3.35-h);
		glVertex2f(2.3,3.4-h);
		glVertex2f(1.7,3.4-h);
	glEnd();
}
else{//bottom right hole
if(h > 0.0){
h=h-.001;
}

glColor3f(0.3,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.5,2.5-h);
		glVertex2f(7.5,4.0-h);
		glVertex2f(8.5,4.0-h);
		glVertex2f(8.5,2.5-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(7.5,4.0-h);
		glVertex2f(7.5,4.3-h);
		glVertex2f(7.7,4.3-h);
		glVertex2f(7.7,4.0-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.3,4.0-h);
		glVertex2f(8.3,4.3-h);
		glVertex2f(8.5,4.3-h);
		glVertex2f(8.5,4.0-h);
	glEnd();


glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.6,3.8-h);
		glVertex2f(7.6,3.6-h);
		glVertex2f(7.8,3.6-h);
		glVertex2f(7.8,3.8-h);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(8.2,3.8-h);
		glVertex2f(8.2,3.6-h);
		glVertex2f(8.4,3.6-h);
		glVertex2f(8.4,3.8-h);
	glEnd();

glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.7,3.35-h);
		glVertex2f(8.3,3.35-h);
		glVertex2f(8.3,3.4-h);
		glVertex2f(7.7,3.4-h);
	glEnd();
}

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

//Draw circles
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(2.0,8.0);
		glVertex2f(1.0,8.0);
		glVertex2f(1.2,8.3);
		glVertex2f(1.4,8.6);
		glVertex2f(1.7,8.8);
		glVertex2f(2.0,9.0);
		glVertex2f(2.4,8.8);
		glVertex2f(2.6,8.6);
		glVertex2f(2.8,8.4);
		glVertex2f(2.9,8.3);
		glVertex2f(3.0,8.0);
		glVertex2f(2.98,7.9);
		glVertex2f(2.9,7.8);
		glVertex2f(2.8,7.7);
		glVertex2f(2.7,7.5);
		glVertex2f(2.6,7.4);
		glVertex2f(2.4,7.2);
		glVertex2f(2.2,7.1);
		glVertex2f(2.0,7.0);
		glVertex2f(1.9,7.05);
		glVertex2f(1.6,7.2);
		glVertex2f(1.4,7.4);
		glVertex2f(1.2,7.6);
		glVertex2f(1.05,7.8);
		glVertex2f(1.0,8.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(8.0,8.0);
		glVertex2f(7.0,8.0);
		glVertex2f(7.2,8.3);
		glVertex2f(7.4,8.6);
		glVertex2f(7.7,8.8);
		glVertex2f(8.0,9.0);
		glVertex2f(8.4,8.8);
		glVertex2f(8.6,8.6);
		glVertex2f(8.8,8.4);
		glVertex2f(8.9,8.3);
		glVertex2f(9.0,8.0);
		glVertex2f(8.98,7.9);
		glVertex2f(8.9,7.8);
		glVertex2f(8.8,7.7);
		glVertex2f(8.7,7.5);
		glVertex2f(8.6,7.4);
		glVertex2f(8.4,7.2);
		glVertex2f(8.2,7.1);
		glVertex2f(8.0,7.0);
		glVertex2f(7.9,7.05);
		glVertex2f(7.6,7.2);
		glVertex2f(7.4,7.4);
		glVertex2f(7.2,7.6);
		glVertex2f(7.05,7.8);
		glVertex2f(7.0,8.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(2.0,3.0);
		glVertex2f(1.0,3.0);
		glVertex2f(1.2,3.3);
		glVertex2f(1.4,3.6);
		glVertex2f(1.7,3.8);
		glVertex2f(2.0,4.0);
		glVertex2f(2.4,3.8);
		glVertex2f(2.6,3.6);
		glVertex2f(2.8,3.4);
		glVertex2f(2.9,3.3);
		glVertex2f(3.0,3.0);
		glVertex2f(2.98,2.9);
		glVertex2f(2.9,2.8);
		glVertex2f(2.8,2.7);
		glVertex2f(2.7,2.5);
		glVertex2f(2.6,2.4);
		glVertex2f(2.4,2.2);
		glVertex2f(2.2,2.1);
		glVertex2f(2.0,2.0);
		glVertex2f(1.9,2.05);
		glVertex2f(1.6,2.2);
		glVertex2f(1.4,2.4);
		glVertex2f(1.2,2.6);
		glVertex2f(1.05,2.8);
		glVertex2f(1.0,3.0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(8.0,3.0);
		glVertex2f(7.0,3.0);
		glVertex2f(7.2,3.3);
		glVertex2f(7.4,3.6);
		glVertex2f(7.7,3.8);
		glVertex2f(8.0,4.0);
		glVertex2f(8.4,3.8);
		glVertex2f(8.6,3.6);
		glVertex2f(8.8,3.4);
		glVertex2f(8.9,3.3);
		glVertex2f(9.0,3.0);
		glVertex2f(8.98,2.9);
		glVertex2f(8.9,2.8);
		glVertex2f(8.8,2.7);
		glVertex2f(8.7,2.5);
		glVertex2f(8.6,2.4);
		glVertex2f(8.4,2.2);
		glVertex2f(8.2,2.1);
		glVertex2f(8.0,2.0);
		glVertex2f(7.9,2.05);
		glVertex2f(7.6,2.2);
		glVertex2f(7.4,2.4);
		glVertex2f(7.2,2.6);
		glVertex2f(7.05,2.8);
		glVertex2f(7.0,3.0);
	glEnd();

drawMole();
	glFlush();
}


void mouseClick(int button,int state,int x,int y){
	GLfloat xpos=(x/600.0) *10.0;
	GLfloat ypos=10.0 - (y/600.0) *10.0;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	  if(xpos > 7.5 && xpos < 8.5 && ypos>7.5 && ypos<9.0){
		if(spot==1)
		spot=0;
		h=.5;
	  }
	  else if(xpos > 1.5 && xpos < 2.5 && ypos>7.5 && ypos<9.0){
		if(spot==2)
		spot=0;
		h=.5;
	  }
	  else if(xpos > 1.5 && xpos < 2.5 && ypos>2.5 && ypos<4.0){
		if(spot==3)
		spot=0;
		h=.5;
	  }
	  else if(xpos > 7.5 && xpos < 8.5 && ypos>2.5 && ypos<4.0){
		if(spot==4)
		spot=0;
		h=.5;
	  }

	}

	glutPostRedisplay();
}

void idle(){
time++;
//printf("%d\n", time);
if(time % 5000 == 0){

if(spot > 4 || spot <1){
   spot=1+ rand() % 3;
}

}
glutPostRedisplay();

}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("WackaMole");
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutIdleFunc(idle);
	init();
	glutMainLoop();
}
