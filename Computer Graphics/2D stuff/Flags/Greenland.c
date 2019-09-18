#include<GL/glut.h>

void init(){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,21.0,0.0,20.0);
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.5,0.0,0.0);
//The bottom red rectangle	
	glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,10.0);
		glVertex2f(21.0,10.0);
		glVertex2f(21.0,0.0);
	glEnd();

//The half circles
	glBegin(GL_POLYGON);
		glVertex2f(3.0,10.0);
		glVertex2f(10.0,10.0);
		glVertex2f(9.5,10.5);
		glVertex2f(9.0,12.0);
		glVertex2f(8.5,12.7);
		glVertex2f(7.5,13.5);
		glVertex2f(6.0,13.7);
		glVertex2f(5.5,13.5);
		glVertex2f(4.5,12.7);
		glVertex2f(4.0,12.0);
		glVertex2f(3.5,10.5);

	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(3.0,10.0);
		glVertex2f(10.0,10.0);
		glVertex2f(9.5,9.5);
		glVertex2f(9.0,8.0);
		glVertex2f(8.5,7.3);
		glVertex2f(7.0,6.5);
		glVertex2f(6.0,6.3);
		glVertex2f(5.5,6.5);
		glVertex2f(4.5,7.3);
		glVertex2f(4.0,8.0);
		glVertex2f(3.5,9.5);
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
