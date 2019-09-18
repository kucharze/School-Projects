#include <GL/glut.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <stdio.h>

void init(){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,32.0,0.0,20.5);
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);

//Northwest Territory
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,17.7);
		glVertex2f(4.6,17.7);
		glVertex2f(5.0,17.2);
		glVertex2f(6.0,17.2);
		glVertex2f(6.0,16.4);
		glVertex2f(2.5,16.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.0,16.4);
		glVertex2f(6.5,16.8);
		glVertex2f(6.5,17.2);
		glVertex2f(6.0,17.2);
	glEnd();
//glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(6.5,17.2);
		glVertex2f(6.8,17.5);
		glVertex2f(7.0,17.2);
		glVertex2f(7.0,16.8);
		glVertex2f(6.5,16.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(6.3,17.2);
		glVertex2f(6.5,17.2);
		glVertex2f(6.5,18.0);
		glVertex2f(6.3,18.4);
		glVertex2f(6.8,18.9);
		glVertex2f(6.6,18.7);
		glVertex2f(6.1,18.0);
		glVertex2f(6.3,17.5);
	glEnd();

//Riberla
	glColor3f(0.0,0.5,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(2.5,16.4);
		glVertex2f(5.5,16.4);
		glVertex2f(5.5,14.5);
		glVertex2f(3.1,14.5);
	glEnd();

//Ontario
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.5,16.4);
		glVertex2f(6.0,16.4);
		glVertex2f(6.2,16.0);
		glVertex2f(6.5,15.7);
		glVertex2f(7.0,15.5);
		glVertex2f(7.5,14.8);
		glVertex2f(7.5,13.5);
		glVertex2f(5.5,13.5);
	glEnd();

//Eastern Canada
	glColor3f(0.0,0.7,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.5,14.8);
		glVertex2f(8.0,15.2);
		glVertex2f(8.6,15.2);
		glVertex2f(8.6,17.4);
		glVertex2f(9.1,17.4);
		glVertex2f(9.1,16.0);
		glVertex2f(9.7,16.0);
		glVertex2f(10.3,15.0);
		glVertex2f(10.3,13.5);
		glVertex2f(7.5,13.5);
	glEnd();

//Greenland
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(9.5,16.7);
		glVertex2f(10.6,15.0);
		glVertex2f(10.6,16.7);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.5,16.7);
		glVertex2f(10.6,16.7);
		glVertex2f(11.8,17.5);
		glVertex2f(11.8,19.0);
		glVertex2f(10.6,19.5);
		glVertex2f(9.5,19.0);
		glVertex2f(9.5,16.7);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(9.7,19.0);
		glVertex2f(9.4,18.7);
		glVertex2f(8.8,18.3);
		glVertex2f(8.8,17.5);
		glVertex2f(9.7,17.5);
	glEnd();

//Iceland
	glColor3f(0.0,0.85,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(13.0,17.0);
		glVertex2f(16.0,17.0);
		glVertex2f(16.0,16.0);
		glVertex2f(15.0,15.0);
		glVertex2f(14.0,16.0);
	glEnd();

//Great Britian
	glColor3f(0.0,0.0,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(13.0,15.0);
		glVertex2f(13.5,13.0);
		glVertex2f(14.5,13.5);
		glVertex2f(14.5,15.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(12.5,13.0);
		glVertex2f(12.5,14.0);
		glVertex2f(12.0,14.0);
		glVertex2f(12.0,13.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(12.5,14.0);
		glVertex2f(13.0,14.0);
		glVertex2f(13.0,13.5);
		glVertex2f(12.5,13.5);
	glEnd();

//Western Europe
	glColor3f(0.0,0.2,0.9);
	glBegin(GL_POLYGON);
		glVertex2f(13.0,12.3);
		glVertex2f(13.0,11.0);
		glVertex2f(14.0,10.7);
		glVertex2f(15.0,11.0);
		glVertex2f(15.0,12.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(14.0,12.3);
		glVertex2f(16.0,12.3);
		glVertex2f(16.0,13.2);
		glVertex2f(15.0,13.8);
		glVertex2f(14.0,13.0);
	glEnd();

//Russia
	glColor3f(0.0,0.6,0.95);
	glBegin(GL_POLYGON);
		glVertex2f(18.1,13.3);
		glVertex2f(18.1,16.5);
		glVertex2f(20.5,16.5);
		glVertex2f(20.5,13.3);
	glEnd();
	//glColor3f(0.0,0.0,0.00);
	glBegin(GL_POLYGON);
		glVertex2f(21.5,13.3);
		glVertex2f(21.5,12.7);
		glVertex2f(19.5,12.7);
		glVertex2f(19.5,13.3);
	glEnd();
	//glColor3f(1.0,0.0,0.00);
	glBegin(GL_POLYGON);
		glVertex2f(18.4,15.5);
		glVertex2f(18.4,18.0);
		glVertex2f(22.5,18.0);
		glVertex2f(22.5,15.5);
	glEnd();
	//glColor3f(0.0,1.0,0.00);
	glBegin(GL_POLYGON);
		glVertex2f(18.4,18.0);
		glVertex2f(18.4,19.5);
		glVertex2f(19.5,19.5);
		glVertex2f(19.5,19.0);
		glVertex2f(18.9,19.0);
		glVertex2f(18.9,18.0);
	glEnd();

//Ural
	glColor3f(0.0,0.7,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(22.5,14.0);
		glVertex2f(22.5,18.0);
		glVertex2f(25.5,18.0);
		glVertex2f(25.5,14.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(22.5,17.0);
		glVertex2f(22.5,19.0);
		glVertex2f(23.0,19.0);
		glVertex2f(23.0,17.0);
	glEnd();

//Siberia
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(24.5,13.0);
		glVertex2f(24.5,18.0);
		glVertex2f(26.5,18.0);
		glVertex2f(26.5,13.0);
	glEnd();

//Yakulst
	glColor3f(0.0,0.45,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(25.5,16.0);
		glVertex2f(25.5,18.0);
		glVertex2f(29.5,18.0);
		glVertex2f(29.5,16.0);
	glEnd();
//Irkilist
	glColor3f(0.0,0.65,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(25.0,15.0);
		glVertex2f(25.0,16.5);
		glVertex2f(28.5,16.5);
		glVertex2f(28.5,15.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(26.0,16.0);
		glVertex2f(26.0,17.0);
		glVertex2f(28.0,17.0);
		glVertex2f(28.0,16.0);
	glEnd();

//Kamshaka
	glColor3f(0.0,0.30,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(29.5,16.5);
		glVertex2f(29.5,18.0);
		glVertex2f(31.5,18.0);
		glVertex2f(31.5,16.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(31.5,16.5);
		glVertex2f(31.5,15.0);
		glVertex2f(30.5,15.0);
		glVertex2f(30.5,16.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(27.5,15.5);
		glVertex2f(27.5,17.0);
		glVertex2f(30.0,17.0);
		glVertex2f(30.0,15.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(28.0,17.0);
		glVertex2f(29.5,17.0);
		glVertex2f(29.5,13.5);
		glVertex2f(28.0,13.5);
	glEnd();

//Afghanastan
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(21.0,13.8);
		glVertex2f(21.0,15.0);
		glVertex2f(20.5,15.0);
		glVertex2f(20.5,15.5);
		glVertex2f(21.0,15.5);
		glVertex2f(22.5,15.5);
		glVertex2f(23.5,13.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(21.0,14.2);
		glVertex2f(24.5,14.2);
		glVertex2f(24.5,12.8);
		glVertex2f(21.0,12.8);
	glEnd();

//Middle East
	glColor3f(0.9,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(22.0,12.8);
		glVertex2f(18.3,12.8);
		glVertex2f(18.3,11.2);
		glVertex2f(22.0,11.2);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(19.0,11.2);
		glVertex2f(19.0,9.8);
		glVertex2f(21.0,9.8);
		glVertex2f(21.0,11.2);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(19.0,9.8);
		glVertex2f(22.3,9.8);
		glVertex2f(22.3,7.7);
		glVertex2f(21.2,7.7);
	glEnd();

//Mongolia
	glColor3f(0.8,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(26.0,13.0);
		glVertex2f(26.0,15.0);
		glVertex2f(28.2,15.0);
		glVertex2f(28.2,13.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(28.0,15.0);
		glVertex2f(27.5,16.0);
		glVertex2f(26.5,16.0);
		glVertex2f(26.5,15.0);
	glEnd();

//Siarra
	glColor3f(0.5,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(24.5,11.0);
		glVertex2f(28.5,11.0);
		glVertex2f(28.5,10.0);
		glVertex2f(29.0,9.5);
		glVertex2f(28.5,9.0);
		glVertex2f(28.0,8.5);
		glVertex2f(24.5,10.0);
	glEnd();

	glColor3f(0.5,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(27.5,9.5);
		glVertex2f(27.5,8.0);
		glVertex2f(27.0,8.0);
		glVertex2f(27.0,9.5);
	glEnd();

//China
	glColor3f(0.55,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(24.5,11.0);
		glVertex2f(24.5,13.5);
		glVertex2f(28.5,13.5);
		glVertex2f(28.5,11.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(24.5,13.5);
		glVertex2f(24.5,14.2);
		glVertex2f(25.5,14.2);
		glVertex2f(26.5,13.5);
	glEnd();
//India
	glColor3f(0.75,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(22.0,13.0);
		glVertex2f(22.0,12.0);
		glVertex2f(25.5,12.0);
		glVertex2f(25.5,13.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(22.0,12.0);
		glVertex2f(26.5,12.0);
		glVertex2f(26.5,11.2);
		glVertex2f(22.0,11.2);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(23.0,12.0);
		glVertex2f(26.5,12.0);
		glVertex2f(25.0,8.0);
	glEnd();

//Japan
	glColor3f(0.45,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(29.5,12.0);
		glVertex2f(29.5,11.0);
		glVertex2f(28.8,10.0);
		glVertex2f(29.8,10.0);
		glVertex2f(31.0,11.0);
		glVertex2f(31.0,12.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(29.5,13.2);
		glVertex2f(29.5,12.5);
		glVertex2f(31.0,12.5);
		glVertex2f(31.0,13.2);
	glEnd();

//Scandinavia
	glColor3f(0.0,1.0,0.20);
	glBegin(GL_POLYGON);
		glVertex2f(18.4,19.5);
		glVertex2f(17.5,19.5);
		glVertex2f(17.5,18.0);
		glVertex2f(18.4,18.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(17.5,19.5);
		glVertex2f(17.0,19.5);
		glVertex2f(16.5,18.5);
		glVertex2f(17.0,18.5);
		glVertex2f(17.5,19.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(15.6,18.5);
		glVertex2f(17.0,18.5);
		glVertex2f(17.0,17.4);
		glVertex2f(15.6,17.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(17.0,17.4);
		glVertex2f(17.0,17.0);
		glVertex2f(16.5,17.0);
		glVertex2f(16.5,17.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(15.6,17.4);
		glVertex2f(15.6,17.2);
		glVertex2f(16.0,17.2);
		glVertex2f(16.0,17.4);
	glEnd();

//Northern Europe
	glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(16.0,15.0);
		glVertex2f(18.5,15.0);
		glVertex2f(18.5,13.3);
		glVertex2f(15.8,13.1);
		glVertex2f(15.0,13.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.0,15.0);
		glVertex2f(16.0,15.5);
		glVertex2f(16.5,15.5);
		glVertex2f(16.5,15.0);
	glEnd();

//Souther Europe
	glColor3f(0.0,0.3,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(16.0,13.3);
		glVertex2f(18.5,13.3);
		glVertex2f(18.5,12.3);
		glVertex2f(16.0,12.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.3,13.3);
		glVertex2f(16.3,13.8);
		glVertex2f(17.0,13.8);
		glVertex2f(17.0,13.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(18.5,13.3);
		glVertex2f(18.5,13.8);
		glVertex2f(18.0,14.2);
		glVertex2f(17.5,13.8);
		glVertex2f(17.5,13.3);
	glEnd();


	glBegin(GL_POLYGON);
		glVertex2f(16.0,12.3);
		glVertex2f(16.5,11.0);
		glVertex2f(17.0,11.0);
		glVertex2f(16.5,12.3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.5,11.0);
		glVertex2f(16.0,10.7);
		glVertex2f(15.7,11.0);
		glVertex2f(16.5,11.5);
	glEnd();
//Western US
	glColor3f(0.85,0.6,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.0,13.6);
		glVertex2f(5.0,11.5);
		glVertex2f(8.5,11.5);
		glVertex2f(10.3,13.6);
		glVertex2f(7.2,13.6);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(5.0,14.5);
		glVertex2f(7.0,14.5);
		glVertex2f(7.0,12.0);
		glVertex2f(5.0,12.0);
	glEnd();


	glBegin(GL_POLYGON);
		glVertex2f(8.5,11.5);
		glVertex2f(9.0,10.5);
		glVertex2f(9.3,10.8);
		glVertex2f(8.8,12.0);
	glEnd();


//Easter US
	glColor3f(0.8,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(3.1,14.5);
		glVertex2f(6.0,14.5);
		glVertex2f(6.0,12.5);
		glVertex2f(5.5,12.5);
		glVertex2f(5.5,12.0);
		glVertex2f(5.2,12.0);
		glVertex2f(5.2,11.5);
		glVertex2f(3.1,11.5);
		glVertex2f(2.8,12.5);
	glEnd();

//Alaska
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1.0,16.0);
		glVertex2f(2.5,16.0);
		glVertex2f(2.5,17.7);
		glVertex2f(0.6,17.7);
		glVertex2f(1.0,17.2);
		glVertex2f(0.5,17.2);
		glVertex2f(0.5,17.0);
		glVertex2f(0.25,17.0);
		glVertex2f(0.25,16.0);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1.0,17.7);
		glVertex2f(1.8,18.0);
		glVertex2f(2.5,17.7);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(1.0,16.0);
		glVertex2f(1.7,16.0);
		glVertex2f(0.5,15.2);
		glVertex2f(0.5,15.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(2.5,16.0);
		glVertex2f(2.9,15.2);
		glVertex2f(3.1,15.6);
		glVertex2f(2.8,16.4);
		glVertex2f(2.5,16.4);
	glEnd();

//Central America
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(3.1,11.5);
		glVertex2f(5.4,9.5);
		glVertex2f(5.8,9.8);
		glVertex2f(5.2,11.5);
	glEnd();

//Venezuela
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.4,9.8);
		glVertex2f(7.5,10.4);
		glVertex2f(10.5,9.5);
		glVertex2f(10.5,8.5);
		glVertex2f(5.4,8.5);
	glEnd();

//Argentinia
	glColor3f(0.75,0.55,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.0,7.0);
		glVertex2f(7.0,2.5);
		glVertex2f(8.0,1.5);
		glVertex2f(8.7,1.6);
		glVertex2f(9.8,1.8);
		glVertex2f(9.8,3.0);
		glVertex2f(10.3,4.2);
		glVertex2f(10.3,7.0);
	glEnd();

//Peru
	glColor3f(0.9,0.6,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(5.4,8.8);
		glVertex2f(5.2,8.0);
		glVertex2f(7.0,6.0);
		glVertex2f(9.3,5.5);
		glVertex2f(9.3,8.8);
	glEnd();



//Brazil
	glColor3f(0.95,0.65,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(7.0,8.0);
		glVertex2f(7.5,8.0);
		glVertex2f(7.5,9.0);
		glVertex2f(11.0,9.0);
		glVertex2f(12.5,8.0);
		glVertex2f(12.5,6.5);
		glVertex2f(7.0,6.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(11.0,6.5);
		glVertex2f(11.0,4.5);
		glVertex2f(9.2,4.5);
		glVertex2f(9.2,6.5);
	glEnd();

//North Africa
	glColor3f(0.6,0.4,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(14.0,6.0);
		glVertex2f(13.5,7.4);
		glVertex2f(13.5,9.0);
		glVertex2f(14.0,9.8);
		glVertex2f(15.2,9.8);
		glVertex2f(16.8,9.8);
		glVertex2f(16.8,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(14.6,9.6);
		glVertex2f(15.0,10.5);
		glVertex2f(16.3,10.5);
		glVertex2f(16.8,9.6);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(16.8,6.0);
		glVertex2f(17.5,6.0);
		glVertex2f(18.0,7.5);
		glVertex2f(18.0,8.5);
		glVertex2f(16.8,8.5);
	glEnd();

//Egypt
	glColor3f(0.5,0.4,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(16.8,9.8);
		glVertex2f(19.0,9.8);
		glVertex2f(20.0,8.5);
		glVertex2f(16.8,8.5);
	glEnd();

//East Africa
	glColor3f(0.5,0.3,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(20.0,8.5);
		glVertex2f(21.5,6.0);
		glVertex2f(21.5,4.0);
		glVertex2f(18.0,4.0);
		glVertex2f(18.0,8.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(21.5,6.0);
		glVertex2f(23.0,6.0);
		glVertex2f(22.5,5.0);
		glVertex2f(21.5,4.0);
	glEnd();

//Congo
	glColor3f(0.4,0.4,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(17.5,6.0);
		glVertex2f(18.0,7.5);
		glVertex2f(19.5,6.0);
		glVertex2f(19.5,4.0);
		glVertex2f(17.5,4.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(19.5,6.0);
		glVertex2f(20.0,6.0);
		glVertex2f(20.0,5.0);
		glVertex2f(19.5,5.0);
	glEnd();

//South Africa
	glColor3f(0.5,0.55,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(20.5,4.0);
		glVertex2f(17.5,4.0);
		glVertex2f(17.5,1.5);
		glVertex2f(20.5,1.5);
	glEnd();

	//glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(19.0,1.5);
		glVertex2f(17.5,1.5);
		glVertex2f(18.5,0.4);
		glVertex2f(19.0,0.2);
		glVertex2f(19.5,0.4);
		glVertex2f(20.5,1.5);
	glEnd();

//Madagascar
	glColor3f(0.55,0.6,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(22.5,3.5);
		glVertex2f(21.0,3.5);
		glVertex2f(21.0,2.0);
		glVertex2f(22.5,2.0);
	glEnd();

//Indonesia
	glColor3f(0.3,0.0,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(26.5,7.0);
		glVertex2f(26.0,6.0);
		glVertex2f(25.5,6.0);
		glVertex2f(26.0,5.5);
		glVertex2f(26.5,5.5);
		glVertex2f(27.0,7.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(24.5,6.5);
		glVertex2f(25.2,5.3);
		glVertex2f(24.8,5.0);
		glVertex2f(23.0,6.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(25.5,5.3);
		glVertex2f(27.0,5.3);
		glVertex2f(27.0,4.8);
		glVertex2f(25.5,4.8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(27.0,5.5);
		glVertex2f(27.0,6.5);
		glVertex2f(27.5,6.5);
		glVertex2f(27.5,5.5);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(27.5,6.5);
		glVertex2f(27.9,6.5);
		glVertex2f(27.9,6.1);
		glVertex2f(27.5,6.1);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(27.5,6.0);
		glVertex2f(27.7,6.0);
		glVertex2f(27.7,5.8);
		glVertex2f(27.5,5.8);
	glEnd();

//New Guinea
	glColor3f(0.4,0.0,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(30.5,6.0);
		glVertex2f(30.5,7.0);
		glVertex2f(29.0,7.0);
		glVertex2f(29.0,6.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(29.0,6.8);
		glVertex2f(28.7,6.8);
		glVertex2f(28.7,7.1);
		glVertex2f(28.4,7.1);
		glVertex2f(28.4,6.6);
		glVertex2f(29.0,6.6);
	glEnd();

//Western Austrilia
	glColor3f(0.4,0.0,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(26.0,1.5);
		glVertex2f(26.0,3.0);
		glVertex2f(28.0,4.5);
		glVertex2f(28.0,2.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(28.0,2.0);
		glVertex2f(29.0,2.0);
		glVertex2f(29.0,3.0);
		glVertex2f(28.0,3.0);
	glEnd();

//Eastern Austrilia
	glColor3f(0.2,0.0,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(28.0,3.0);
		glVertex2f(30.0,3.0);
		glVertex2f(30.0,4.0);
		glVertex2f(28.5,5.0);
		glVertex2f(28.0,5.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(30.5,4.0);
		glVertex2f(30.5,5.0);
		glVertex2f(29.5,5.0);
		glVertex2f(29.5,4.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(29.5,5.0);
		glVertex2f(29.5,5.5);
		glVertex2f(30.0,5.5);
		glVertex2f(30.0,5.0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(29.0,4.0);
		glVertex2f(29.0,1.0);
		glVertex2f(31.0,1.0);
		glVertex2f(31.5,2.5);
		glVertex2f(31.0,4.0);
	glEnd();

	glFlush();
}

void mouseClick(int button,int state,int x,int y){
	GLfloat xpos=(x/700.0) *32;
	GLfloat ypos=20.5 - (y/600.0) *20.5;
	//printf("x value %f",xpos);
	//printf("y value %f",ypos);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	  if(xpos > 2.5 && xpos < 4.7 && ypos>16.4 && ypos<17.7){
		glutSetWindowTitle("Northwest Territory");
	  }
	  else if(xpos > 4.0 && xpos < 6.0 && ypos>16.4 && ypos<17.2){
		glutSetWindowTitle("Northwest Territory");
	  }
	  else if(xpos > 6.0 && xpos < 6.5 && ypos>16.7 && ypos<17.2){
		glutSetWindowTitle("Northwest Territory");
	  }
	  else if(xpos > 6.1 && xpos < 6.6 && ypos>17.2 && ypos<18.7){
		glutSetWindowTitle("Northwest Territory");
	  }
	  else if(xpos > 2.9 && xpos < 5.5 && ypos>14.5 && ypos<16.4){
		glutSetWindowTitle("Riberla");
	  }
	  else if(xpos > 5.5 && xpos < 6.0 && ypos>14.5 && ypos<16.4){
		glutSetWindowTitle("Ontario");
	  }
	  else if(xpos > 5.5 && xpos < 6.0 && ypos>14.5 && ypos<16.4){
		glutSetWindowTitle("Ontario");
	  }
	  else if(xpos > 6.0 && xpos < 7.0 && ypos>14.5 && ypos<16.0){
		glutSetWindowTitle("Ontario");
	  }
	  else if(xpos > 7.0 && xpos < 7.5 && ypos>13.6 && ypos<15.5){
		glutSetWindowTitle("Ontario");
	  }
	  else if(xpos > 7.5 && xpos < 8.0&& ypos>13.6 && ypos<15.5){
		glutSetWindowTitle("Eastern Canada");
	  }
	  else if(xpos > 8.0 && xpos < 8.6&& ypos>13.6 && ypos<17.4){
		glutSetWindowTitle("Eastern Canada");
	  }
	  else if(xpos > 8.6 && xpos < 9.1&& ypos>13.6 && ypos<17.4){
		glutSetWindowTitle("Eastern Canada");
	  }
	  else if(xpos > 9.1 && xpos < 9.7 && ypos>13.6 && ypos<16.0){
		glutSetWindowTitle("Eastern Canada");
	  }
	  else if(xpos > 9.7 && xpos < 10.3 && ypos>13.6 && ypos<15.4){
		glutSetWindowTitle("Eastern Canada");
	  }
	  else if(xpos > 9.8 && xpos < 10.6 && ypos>15.5 && ypos<16.7){
		glutSetWindowTitle("Greenland");
	  }
	  else if(xpos > 9.5 && xpos < 11.5 && ypos>17.0 && ypos<17.5){
		glutSetWindowTitle("Greenland");
	  }
	  else if(xpos > 9.5 && xpos < 11.8 && ypos>17.5 && ypos<19.3){
		glutSetWindowTitle("Greenland");
	  }
	  else if(xpos > 8.8 && xpos < 9.7 && ypos>17.5 && ypos<18.5){
		glutSetWindowTitle("Greenland");
	  }
	  else if(xpos > 13.5 && xpos < 16.0 && ypos>16.2 && ypos<17.0){
		glutSetWindowTitle("Iceland");
	  }
	  else if(xpos > 14.2 && xpos < 15.3 && ypos>15.3 && ypos<16.2){
		glutSetWindowTitle("Iceland");
	  }
	  else if(xpos > 13.0 && xpos < 14.5 && ypos>13.5 && ypos<15.0){
		glutSetWindowTitle("Great Britian");
	  }
	  else if(xpos > 12.0 && xpos < 12.5 && ypos>13.0 && ypos<14.0){
		glutSetWindowTitle("Great Britian");
	  }
	  else if(xpos > 12.5 && xpos < 13.0 && ypos>13.5 && ypos<14.0){
		glutSetWindowTitle("Great Britian");
	  }
	  else if(xpos > 13.0 && xpos < 15.0 && ypos>10.9 && ypos<12.3){
		glutSetWindowTitle("Western Europe");
	  }
	  else if(xpos > 14.2 && xpos < 16.0 && ypos>12.3 && ypos<13.5){
		glutSetWindowTitle("Western Europe");
	  }
	  else if(xpos > 18.2 && xpos < 20.5 && ypos>13.3 && ypos<16.5){
		glutSetWindowTitle("Russia");
	  }
	  else if(xpos > 19.5 && xpos < 21.5 && ypos>12.9 && ypos<13.3){
		glutSetWindowTitle("Russia");
	  }
	  else if(xpos > 18.4 && xpos < 22.5 && ypos>15.5 && ypos<18.0){
		glutSetWindowTitle("Russia");
	  }
	  else if(xpos > 18.4 && xpos < 19.0 && ypos>18.0 && ypos<19.5){
		glutSetWindowTitle("Russia");
	  }
	  else if(xpos > 18.4 && xpos < 19.5 && ypos>18.7 && ypos<19.5){
		glutSetWindowTitle("Russia");
	  }
	  else if(xpos > 22.5 && xpos < 24.5 && ypos>15.5 && ypos<18.0){
		glutSetWindowTitle("Ural");
	  }
	  else if(xpos > 22.8 && xpos < 24.5 && ypos>14.0 && ypos<15.5){
		glutSetWindowTitle("Ural");
	  }
	  else if(xpos > 22.5 && xpos < 23.0 && ypos>17.0 && ypos<19.0){
		glutSetWindowTitle("Ural");
	  }
	  else if(xpos > 24.5 && xpos < 25.0 && ypos>13.0 && ypos<18.0){
		glutSetWindowTitle("Siberia");
	  }
	  else if(xpos > 25.0 && xpos < 26.0 && ypos>14.0 && ypos<15.0){
		glutSetWindowTitle("Siberia");
	  }
	  else if(xpos > 25.0 && xpos < 25.5 && ypos>16.5 && ypos<18.0){
		glutSetWindowTitle("Siberia");
	  }
	  else if(xpos > 25.5 && xpos < 29.5 && ypos>17.0 && ypos<18.0){
		glutSetWindowTitle("Yakulst");
	  }
	  else if(xpos > 25.0 && xpos < 26.5 && ypos>15.2 && ypos<16.5){
		glutSetWindowTitle("Irkilist");
	  }
	  else if(xpos > 26.0 && xpos < 27.5 && ypos>16.0 && ypos<17.0){
		glutSetWindowTitle("Irkilist");
	  }
	  else if(xpos > 26.0 && xpos < 27.0 && ypos>16.0 && ypos<17.0){
		glutSetWindowTitle("Kamshaka");
	  }
	  else if(xpos > 3.0 && xpos < 5.2 && ypos>11.7 && ypos<14.5){
		glutSetWindowTitle("Eastern US");
	  }
	  else if(xpos > 5.2 && xpos < 5.5 && ypos>12.0 && ypos<14.5){
		glutSetWindowTitle("Eastern US");
	  }
	  else if(xpos > 5.5 && xpos < 6.0 && ypos>12.5 && ypos<14.5){
		glutSetWindowTitle("Eastern US");
	  }
	  else if(xpos > 5.0 && xpos < 9.2 && ypos>11.5 && ypos<13.6){
		glutSetWindowTitle("Western US");
	  }
	  else if(xpos > 9.2 && xpos < 10.0 && ypos>11.7 && ypos<13.4){
		glutSetWindowTitle("Western US");
	  }
	  else if(xpos > 5.0 && xpos < 7.0 && ypos>12.0 && ypos<14.5){
		glutSetWindowTitle("Western US");
	  }
	  else if(xpos > 8.6 && xpos < 9.2 && ypos>10.5 && ypos<11.5){
		glutSetWindowTitle("Western US");
	  }
	  else if(xpos > 3.4 && xpos < 5.6 && ypos>10.0 && ypos<11.5){
		glutSetWindowTitle("Central US");
	  }
	  else if(xpos > 1.0 && xpos < 2.5 && ypos>16.0 && ypos<17.9){
		glutSetWindowTitle("Alaska");
	  }
	  else if(xpos > 0.25 && xpos < 1.0 && ypos>16.0 && ypos<17.0){
		glutSetWindowTitle("Alaska");
	  }
	  else if(xpos > 0.7 && xpos < 1.5 && ypos>15.4 && ypos<16.0){
		glutSetWindowTitle("Alaska");
	  }
	  else if(xpos > 2.5 && xpos < 3.0 && ypos>15.2 && ypos<16.4){
		glutSetWindowTitle("Alaska");
	  }
	  else if(xpos > 16.0 && xpos < 18.5 && ypos>12.3 && ypos<13.3){
		glutSetWindowTitle("Southern Europe");
	  }
	  else if(xpos > 16.3 && xpos < 17.0 && ypos>13.3 && ypos<13.8){
		glutSetWindowTitle("Southern Europe");
	  }
	  else if(xpos > 17.5 && xpos < 18.5 && ypos>13.3 && ypos<14.1){
		glutSetWindowTitle("Southern Europe");
	  }
	  else if(xpos > 16.2 && xpos < 16.9 && ypos>11.0 && ypos<12.3){
		glutSetWindowTitle("Southern Europe");
	  }
	  else if(xpos > 15.7 && xpos < 16.5 && ypos>10.7 && ypos<11.0){
		glutSetWindowTitle("Southern Europe");
	  }
	  else if(xpos > 15.8 && xpos < 18.5 && ypos>13.1 && ypos<15.0){
		glutSetWindowTitle("Northern Europe");
	  }
	  else if(xpos > 15.3 && xpos < 15.8 && ypos>13.4 && ypos<14.6){
		glutSetWindowTitle("Northern Europe");
	  }
	  else if(xpos > 29.5 && xpos < 31.5 && ypos>16.5 && ypos<18.0){
		glutSetWindowTitle("Kamshaka");
	  }
	  else if(xpos > 30.5 && xpos < 31.5 && ypos>15.0 && ypos<16.5){
		glutSetWindowTitle("Kamshaka");
	  }
	  else if(xpos > 27.5 && xpos < 30.0 && ypos>15.5 && ypos<17.0){
		glutSetWindowTitle("Kamshaka");
	  }
	  else if(xpos > 28.0 && xpos < 29.5 && ypos>13.5 && ypos<17.0){
		glutSetWindowTitle("Kamshaka");
	  }
	  else if(xpos > 21.0 && xpos < 24.5 && ypos>12.8 && ypos<14.2){
		glutSetWindowTitle("Afghanastan");
	  }
	  else if(xpos > 20.7 && xpos < 22.5 && ypos>13.8 && ypos<15.5){
		glutSetWindowTitle("Afghanastan");
	  }
	  else if(xpos > 21.0 && xpos < 22.5 && ypos>2.0 && ypos<3.5){
		glutSetWindowTitle("Madagascar");
	  }
	  else if(xpos > 16.8 && xpos < 19.8 && ypos>8.5 && ypos<9.8){
		glutSetWindowTitle("Eqypt");
	  }
	  else if(xpos > 18.3 && xpos < 22.0 && ypos>11.2 && ypos<12.8){
		glutSetWindowTitle("Middle East");
	  }
	  else if(xpos > 19.0 && xpos < 21.0 && ypos>9.8 && ypos<11.2){
		glutSetWindowTitle("Middle East");
	  }
	  else if(xpos > 19.0 && xpos < 21.0 && ypos>8.5 && ypos<9.8){
		glutSetWindowTitle("Middle East");
	  }
	  else if(xpos > 21.0 && xpos < 22.3 && ypos>7.7 && ypos<9.8){
		glutSetWindowTitle("Middle East");
	  }
	  else if(xpos > 29.0 && xpos < 30.8 && ypos>10.3 && ypos<12.0){
		glutSetWindowTitle("Japan");
	  }
	  else if(xpos > 29.5 && xpos < 31.0 && ypos>12.5 && ypos<13.2){
		glutSetWindowTitle("Japan");
	  }
	  else if(xpos > 26.0 && xpos < 28.2 && ypos>13.0 && ypos<15.0){
		glutSetWindowTitle("Mongolia");
	  }
	  else if(xpos > 26.5 && xpos < 28.0 && ypos>15.0 && ypos<16.0){
		glutSetWindowTitle("Mongolia");
	  }
	  else if(xpos > 22.0 && xpos < 25.5 && ypos>12.0 && ypos<13.0){
		glutSetWindowTitle("India");
	  }
	  else if(xpos > 22.0 && xpos < 26.5 && ypos>11.2 && ypos<12.0){
		glutSetWindowTitle("India");
	  }
	  else if(xpos > 23.8 && xpos < 26.0 && ypos>8.8 && ypos<12.0){
		glutSetWindowTitle("India");
	  }
	  else if(xpos > 24.5 && xpos < 28.5 && ypos>11.0 && ypos<13.5){
		glutSetWindowTitle("China");
	  }
	  else if(xpos > 24.5 && xpos < 26.5 && ypos>13.5 && ypos<14.2){
		glutSetWindowTitle("China");
	  }
	  else if(xpos > 24.5 && xpos < 29.0 && ypos>8.8 && ypos<11.0){
		glutSetWindowTitle("Siarra");
	  }
	  else if(xpos > 27.0 && xpos < 27.5 && ypos>8.0 && ypos<9.5){
		glutSetWindowTitle("Siarra");
	  }
	  else if(xpos > 5.4 && xpos < 10.5 && ypos>8.8 && ypos<10.2){
		glutSetWindowTitle("Venezuela");
	  }
	  else if(xpos > 13.5 && xpos < 16.8 && ypos>6.0 && ypos<9.8){
		glutSetWindowTitle("North Africa");
	  }
	  else if(xpos > 15.0 && xpos < 16.8 && ypos>9.6 && ypos<10.5){
		glutSetWindowTitle("North Africa");
	  }
	  else if(xpos > 16.8 && xpos < 18.0 && ypos>6.0 && ypos<8.5){
		glutSetWindowTitle("North Africa");
	  }
	  else if(xpos > 16.8 && xpos < 19.8 && ypos>8.5 && ypos<9.8){
		glutSetWindowTitle("Eqypt");
	  }
	  else if(xpos > 7.0 && xpos < 12.3 && ypos>6.5 && ypos<8.8){
		glutSetWindowTitle("Brazil");
	  }
	  else if(xpos > 9.2 && xpos < 11.0 && ypos>4.5 && ypos<6.5){
		glutSetWindowTitle("Brazil");
	  }
	  else if(xpos > 5.6 && xpos < 9.3 && ypos>5.8 && ypos<8.8){
		glutSetWindowTitle("Peru");
	  }
	  else if(xpos > 17.5 && xpos < 18.4 && ypos>18.0 && ypos<19.5){
		glutSetWindowTitle("Scandanavia");
	  }
	  else if(xpos > 16.7 && xpos < 17.2 && ypos>18.5 && ypos<19.5){
		glutSetWindowTitle("Scandanavia");
	  }
	  else if(xpos > 15.6 && xpos < 17.0 && ypos>17.4 && ypos<18.5){
		glutSetWindowTitle("Scandanavia");
	  }
	  else if(xpos > 16.5 && xpos < 17.0 && ypos>17.0 && ypos<17.5){
		glutSetWindowTitle("Scandanavia");
	  }
	  else if(xpos > 15.6 && xpos < 16.0 && ypos>17.2 && ypos<17.5){
		glutSetWindowTitle("Scandanavia");
	  }
	  else if(xpos > 7.2 && xpos < 8.0 && ypos>1.7 && ypos<7.0){
		glutSetWindowTitle("Argentinia");
	  }
	  else if(xpos > 8.0 && xpos < 10.1 && ypos>1.5 && ypos<7.0){
		glutSetWindowTitle("Argentinia");
	  }
	  else if(xpos > 17.5 && xpos < 18.0 && ypos>4.0 && ypos<7.5){
		glutSetWindowTitle("Congo");
	  }
	  else if(xpos > 18.0 && xpos < 19.5 && ypos>4.0 && ypos<7.2){
		glutSetWindowTitle("Congo");
	  }
	  else if(xpos > 19.5 && xpos < 20.0 && ypos>5.0 && ypos<6.0){
		glutSetWindowTitle("Congo");
	  }
	  else if(xpos > 17.5 && xpos < 20.5 && ypos>1.5 && ypos<4.0){
		glutSetWindowTitle("South Africa");
	  }
	  else if(xpos > 17.7 && xpos < 20.2 && ypos>0.5 && ypos<1.5){
		glutSetWindowTitle("South Africa");
	  }
	  else if(xpos > 18.0 && xpos < 21.5 && ypos>4.0 && ypos<8.5){
		glutSetWindowTitle("East Africa");
	  }
	  else if(xpos > 21.5 && xpos < 22.7 && ypos>4.3 && ypos<6.0){
		glutSetWindowTitle("East Africa");
	  }
	  else if(xpos > 29.0 && xpos < 30.5 && ypos>6.0 && ypos<7.0){
		glutSetWindowTitle("New Guinea");
	  }
	  else if(xpos > 28.4 && xpos < 29.0 && ypos>6.6 && ypos<7.1){
		glutSetWindowTitle("New Guinea");
	  }
	  else if(xpos > 26.0 && xpos < 28.0 && ypos>1.5 && ypos<4.5){
		glutSetWindowTitle("Western Austrilia");
	  }
	  else if(xpos > 28.0 && xpos < 29.0 && ypos>2.0 && ypos<3.0){
		glutSetWindowTitle("Western Austrilia");
	  }
	  else if(xpos > 28.0 && xpos < 30.0 && ypos>3.0 && ypos<5.0){
		glutSetWindowTitle("Eastern Austrilia");
	  }
	  else if(xpos > 29.5 && xpos < 30.5 && ypos>4.0 && ypos<5.0){
		glutSetWindowTitle("Eastern Austrilia");
	  }
	  else if(xpos > 29.5 && xpos < 30.0 && ypos>5.0 && ypos<5.5){
		glutSetWindowTitle("Eastern Austrilia");
	  }
	  else if(xpos > 29.0 && xpos < 31.2 && ypos>1.0 && ypos<4.0){
		glutSetWindowTitle("Eastern Austrilia");
	  }
	  else if(xpos > 25.7 && xpos < 26.8 && ypos>5.7 && ypos<6.8){
		glutSetWindowTitle("Indonesia");
	  }
	  else if(xpos > 23.2 && xpos < 25.0 && ypos>5.2 && ypos<6.5){
		glutSetWindowTitle("Indonesia");
	  }
	  else if(xpos > 25.5 && xpos < 27.0 && ypos>4.8 && ypos<5.3){
		glutSetWindowTitle("Indonesia");
	  }
	  else if(xpos > 27 && xpos < 27.5 && ypos>5.5 && ypos<6.5){
		glutSetWindowTitle("Indonesia");
	  }
	  else if(xpos > 27.5 && xpos < 27.9 && ypos>6.1 && ypos<6.5){
		glutSetWindowTitle("Indonesia");
	  }
	  else if(xpos > 27.5 && xpos < 27.7 && ypos>5.8 && ypos<6.0){
		glutSetWindowTitle("Indonesia");
	  }
	  else{
		glutSetWindowTitle("Open Ocean");
	  }
	}
	glutPostRedisplay();

}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(700,600);
	glutCreateWindow("Risk");
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	init();
	glutMainLoop();
}
