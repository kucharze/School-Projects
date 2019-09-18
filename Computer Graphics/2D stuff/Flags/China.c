#include<GL/glut.h>

void init(){
glClearColor(1.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,10.0,0.0,9.0);
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
//The big star
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,1.0,0.0);
	
	glBegin(GL_POLYGON);
		glVertex2f(1.0,7.0);
		glVertex2f(3.0,7.0);
		glVertex2f(2.0,6.0);
	
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.0);
		glVertex2f(2.5,5.5);
		glVertex2f(1.7,6.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.0);
		glVertex2f(1.4,5.5);
		glVertex2f(2.3,6.3);
	glEnd();

//The small stars
//Star 1
	glBegin(GL_POLYGON);
		glVertex2f(3.15,8.2);
		glVertex2f(4.05,7.7);
		glVertex2f(3.40,7.65);
	
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(3.7,8.5);
		glVertex2f(3.7,7.2);
		glVertex2f(3.35,7.7);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(3.7,8.5);
		glVertex2f(3.7,7.7);
		glVertex2f(3.15,7.45);
	glEnd();
//star 2
	//glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(4.0,7.4);
		glVertex2f(4.8,6.6);
		glVertex2f(4.2,6.4);
	glEnd();
	//glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(4.0,7.4);
		glVertex2f(4.2,5.9);
		glVertex2f(4.5,6.7);
	glEnd();
	//glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(3.8,6.3);
		glVertex2f(4.4,6.4);
		glVertex2f(4.6,7.6);
	glEnd();
//star 3
	glBegin(GL_POLYGON);
		glVertex2f(4.0,5.3);
		glVertex2f(5.0,5.3);
		glVertex2f(4.5,4.8);
	
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.5,5.8);
		glVertex2f(4.8,4.5);
		glVertex2f(4.3,5.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(4.5,5.8);
		glVertex2f(4.7,5.0);
		glVertex2f(4.2,4.5);
	glEnd();


//start 4
	glBegin(GL_POLYGON);
		glVertex2f(3.15,4.8);
		glVertex2f(4.05,4.3);
		glVertex2f(3.40,4.25);
	
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(3.7,5.1);
		glVertex2f(3.7,3.8);
		glVertex2f(3.35,4.2);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(3.7,5.1);
		glVertex2f(3.7,4.3);
		glVertex2f(3.15,4.05);
	glEnd();

	glFlush();

}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(300,200);
	glutCreateWindow("Simple");
	glutDisplayFunc(display);
	init();
	glutMainLoop();

}
