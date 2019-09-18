#include<GL/glut.h>

void init(){
glClearColor(0.0,0.0,0.5,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,5.0,0.0,4.0);
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.0,0.0);
		glVertex2f(2.0,0.0);
		glVertex2f(2.0,4.0);
		glVertex2f(1.0,4.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(0.0,2.5);
		glVertex2f(0.0,1.5);
		glVertex2f(5.0,1.5);
		glVertex2f(5.0,2.5);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.25,0.0);
		glVertex2f(1.75,0.0);
		glVertex2f(1.75,4.0);
		glVertex2f(1.25,4.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(0.0,2.3);
		glVertex2f(0.0,1.7);
		glVertex2f(5.0,1.5);
		glVertex2f(5.0,2.3);
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
