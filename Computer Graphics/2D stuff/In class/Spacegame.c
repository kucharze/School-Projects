#include <GL/glut.h>
#include<GL/freeglut.h>
#include<GL/freeglut_ext.h>
#include<GL/freeglut_std.h>
//freeglut.h
//-ext
//_std.h

//_Bool paused=false;
int count=0;
double space_x=0.0;
double space_y=0.0;

void init(){
	glClearColor(0.0,0.0,0.2,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,5.0,0.0,5.0);
	srand((unsigned) time(&t));
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT);

	//Draw stars

	//Draw spaceship
	draw_spaceship();

	glFlush();

}

void draw_spaceship(){
glColor3f(1.0,0.0,0.0);
gloBegin(GL_POLYGON);
	glPoint(space_x - 0.05, space_y - 0.05);
	glPoint(space_x - 0.05, space_y + 0.05);
	glPoint(space_x + 0.05, space_y - 0.05);
	glPoint(space_x + 0.05, space_y + 0.05);
}

void my_keyboard(char ch, int x, int y){
	if(ch== 'q' ||  ch == 'Q')exit(0);
//pause and quit
}


void Eric(){
//if(!paused)
	count++;

if(count % 10000 == 0){
space_x=(rand()*0.8)/RAND_MAX + 0.1;
space_y=(rand()*0.8)/RAND_MAX + 0.1;
}
glutPostRedisplay();

}

void my_mouse(int button, int state, int x, int y){
double newx,newy;
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
printf("mouse pressed at (%d,%d)\m",x,y);
newx=x/500.0;
newy=1.0 - (y/500.0);
printf("Converted coordintates at (%ld,%ld)\m",newx,newy);
}
if(newx > (space_x -0.05) && newx < (space_x + 0.05) &&
  newy > (space_y -0.05) && newy > (space_y + 0.05)){
	printf("Ouch");
}
}


int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutInitWindowSize(400,400);
glutCreateWindow("Space game");
glutDisplayFunc(display);
glutMouseFunc(my_mouse);
glutKeyboardFunc(my_keyboard);
glutIdleFunc(Eric);
}
