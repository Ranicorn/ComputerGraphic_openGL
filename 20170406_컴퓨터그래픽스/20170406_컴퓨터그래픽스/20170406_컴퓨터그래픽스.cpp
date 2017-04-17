// 20170406_컴퓨터그래픽스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//


/*
//Prog18: Simply Interactivity

#include "stdafx.h"
#include <math.h>
#include <gl/glut.h>

GLfloat vertices[][3] = {
	{ -1.0, -1.0, -1.0 },{ 1.0, -1.0 , -1.0 },{ 1.0 , 1.0 , -1.0 },{ -1.0 , 1.0 , -1.0 },
	{ -1.0 , -1.0 , 1.0 },{ 1.0 , -1.0 , 1.0 },{ 1.0 , 1.0 , 1.0 },{ -1.0 , 1.0 , 1.0 } };
GLfloat colors[][3] = {
	{ 0.0, 0.0, 0.0 },{ 1.0 , 0.0, 0.0 },{ 1.0 , 1.0 , 0.0 },{ 0.0, 1.0 , 0.0 },
	{ 0.0, 0.0, 1.0 },{ 1.0 , 0.0, 1.0 },{ 1.0 , 1.0 , 1.0 },{ 0.0, 1.0 , 1.0 } };

static GLfloat theta = 0.0; // variable for rotation
static double scale = 1.0;
static int axis = 0;

void init()
{
	glMatrixMode(GL_PROJECTION); // change to projection view
	glLoadIdentity(); // load identity matrix
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW); // restore to model view
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // load an identity matrix
	if (axis == 0)
		glRotatef(theta, 1.0, 0.0, 0.0); // rotation about x-axis 
	if (axis == 1)
		glRotatef(theta, 0.0, 1.0, 0.0); // rotation about y-axis 
	if (axis == 2)
		glRotatef(theta, 0.0, 0.0, 1.0); // rotation about z-axis 

	GLubyte indices[] = { 0, 3, 2, 1, 2, 3, 7, 6 , 0, 4, 7, 3, 1, 2, 6, 5, 4, 5, 6, 7, 0, 1, 5, 4 };

	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);

	//for (int i = 0; i < 6; i++)
	//{
	//	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &indices[4 * i]);
	//}

	glScalef(scale, scale, scale);

	glFlush();
	glutSwapBuffers(); // Use double-buffering
}

void spin_cube()
{
	theta += 0.1;
	if (theta > 360.0) theta -= 360.0;
	glutPostRedisplay();
}

void keyboard_handler(unsigned char key, int x, int y)
{
	if (key == 'w')
		scale += 0.01;
	if (key == 's')
		scale -= 0.01;
	if (scale < 0.1)
		scale = 0.1;
	if (scale > 1.4)
		scale = 1.4;
}

void mouse_handler(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 0;
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;
}

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog18: Simply Interactivity");
	glutIdleFunc(spin_cube);
	glutKeyboardFunc(keyboard_handler); // add keyboard handler
	glutMouseFunc(mouse_handler); // add mouse handler
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
*/





////Prog19: Exercies...
//
//#include "stdafx.h"
//#include <math.h>
//#include <gl/glut.h>
//
//static int Day = 0, Time = 0;
//
//void init()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//	glColor3f(1.0, 0.3, 0.3);
//	glutWireSphere(0.2, 30, 16);
//	glPushMatrix();
//		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
//		glTranslatef(0.7, 0.0, 0.0);
//		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//		glColor3f(0.5, 0.6, 0.7);
//		glutWireSphere(0.1, 10, 8);
//		glPushMatrix();
//			glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
//			glTranslatef(0.2, 0.0, 0.0);
//			glColor3f(0.9, 0.8, 0.2);
//			glutWireSphere(0.04, 10, 8);
//		glPopMatrix();
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void MyKeyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'd':
//		Day = (Day + 10) % 360;
//		glutPostRedisplay();
//		break;
//	case't':
//		Time = (Time + 5) % 360;
//		glutPostRedisplay();
//		break;
//	default:
//		break;
//	}
//}
//
//int main(int argc, char**argv)
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog19: Exercies...");
//	glutDisplayFunc(display);
//	glutKeyboardFunc(MyKeyboard);
//	init();
//	glutMainLoop();
//	return 0;
//}







//Prog20: Exercies...v2

#include "stdafx.h"
#include <math.h>
#include <time.h>
#include <gl/glut.h>

void timer(int t);
static int delay = 10; // milliseconds
static int Day = 0, Time = 0;

void init()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 30, 16);
	glPushMatrix();
		glRotatef((GLfloat)Day, 0.0, 1.0, 0.0);
		glTranslatef(0.7, 0.0, 0.0);
		glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
		glColor3f(0.5, 0.6, 0.7);
		glutWireSphere(0.1, 10, 8);
		glPushMatrix();
			glRotatef((GLfloat)Time, 0.0, 1.0, 0.0);
			glTranslatef(0.2, 0.0, 0.0);
			glColor3f(0.9, 0.8, 0.2);
			glutWireSphere(0.04, 10, 8);
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void timer(int t)
{
	glutPostRedisplay(); // redraw gralatitudecs (rather than calling display() itself)
						 //OS에게 display해 달라고 호출을 넘겨주는 거임!
	glutTimerFunc(delay, timer, t); // set timer function again //재귀호출!

	Time = (Time + 10) % 360;
	glutPostRedisplay();
	Day = (Day + 1) % 360;
	glutPostRedisplay();
}

int main(int argc, char**argv)
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog20: Hello Universe...v2");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0); // set timer function which is called for each delay (ms)
	init();
	glutMainLoop();
	return 0;
}