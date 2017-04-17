// 20170413_컴퓨터그래픽스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

////Prog19: Moving Camera
//
//#include "stdafx.h"
//#include <math.h>
//#include <gl/glut.h>
//
//GLfloat vertices[][3] = {
//	{ -1.0, -1.0, -1.0 },{ 1.0, -1.0 , -1.0 },{ 1.0 , 1.0 , -1.0 },{ -1.0 , 1.0 , -1.0 },
//	{ -1.0 , -1.0 , 1.0 },{ 1.0 , -1.0 , 1.0 },{ 1.0 , 1.0 , 1.0 },{ -1.0 , 1.0 , 1.0 } };
//GLfloat colors[][3] = {
//	{ 0.0, 0.0, 0.0 },{ 1.0 , 0.0, 0.0 },{ 1.0 , 1.0 , 0.0 },{ 0.0, 1.0 , 0.0 },
//	{ 0.0, 0.0, 1.0 },{ 1.0 , 0.0, 1.0 },{ 1.0 , 1.0 , 1.0 },{ 0.0, 1.0 , 1.0 } };
//
//static GLfloat x_axis = 1;
//static GLfloat y_axis = 1;
//static GLfloat z_axis = 1;
//
//void init()
//{
//	glMatrixMode(GL_PROJECTION); // change to projection view
//	glLoadIdentity(); // load identity matrix
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_MODELVIEW); // restore to model view
//}
//
//void polygon(int a, int b, int c, int d)
//{
//	glBegin(GL_POLYGON);
//	glColor3fv(colors[a]);
//	glVertex3fv(vertices[a]);
//	glColor3fv(colors[b]);
//	glVertex3fv(vertices[b]);
//	glColor3fv(colors[c]);
//	glVertex3fv(vertices[c]);
//	glColor3fv(colors[d]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity(); // load an identity matrix
//
//	gluLookAt(x_axis, y_axis, z_axis, 0, 0, 0, 0, 1, 0);
//
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
//
//	glFlush();
//	glutSwapBuffers(); // Use double-buffering
//}
//
//void keyboard_handler(unsigned char key, int x, int y)
//{
//	if (key == 'x')
//		x_axis -= 0.1;
//	if (key == 'X')
//		x_axis += 0.1;
//	if (key == 'y')
//		y_axis -= 0.1;
//	if (key == 'Y')
//		y_axis += 0.1;
//	if (key == 'z')
//		z_axis -= 0.1;
//	if (key == 'Z')
//		z_axis += 0.1;
//	if (key == 'd')
//	{
//		x_axis = 1;
//		y_axis = 1;
//		z_axis = 1;
//	}
//
//	glutPostRedisplay();
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog19: Moving Camera");
//	glutKeyboardFunc(keyboard_handler); // add keyboard handler
//	glutDisplayFunc(display);
//	init();
//	glutMainLoop();
//	return 0;
//}









////Prog20: Perspective Projection
//
//#include "stdafx.h"
//#include <math.h>
//#include <gl/glut.h>
//
//GLfloat vertices[][3] = {
//	{ -1.0, -1.0, -1.0 },{ 1.0, -1.0 , -1.0 },{ 1.0 , 1.0 , -1.0 },{ -1.0 , 1.0 , -1.0 },
//	{ -1.0 , -1.0 , 1.0 },{ 1.0 , -1.0 , 1.0 },{ 1.0 , 1.0 , 1.0 },{ -1.0 , 1.0 , 1.0 } };
//GLfloat colors[][3] = {
//	{ 0.0, 0.0, 0.0 },{ 1.0 , 0.0, 0.0 },{ 1.0 , 1.0 , 0.0 },{ 0.0, 1.0 , 0.0 },
//	{ 0.0, 0.0, 1.0 },{ 1.0 , 0.0, 1.0 },{ 1.0 , 1.0 , 1.0 },{ 0.0, 1.0 , 1.0 } };
//
//static GLfloat theta = 0.0; // variable for rotation
//static GLfloat scale = 0.7;
//static int axis = 0;
//
//static GLfloat x_axis = 3;
//static GLfloat y_axis = 3;
//static GLfloat z_axis = 3;
//
//static int view = 0;
//
//void init()
//{
//	glMatrixMode(GL_PROJECTION); // change to projection view
//	glLoadIdentity(); // load identity matrix
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	if (view == 0)
//		glFrustum(-2.0, 2.0, -2.0, 2.0, 2.0, 20.0);
//	else
//		glOrtho(-2.0, 2.0, -2.0, 2.0, 2.0, 20.0);
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_MODELVIEW); // restore to model view
//}
//
//void polygon(int a, int b, int c, int d)
//{
//	glBegin(GL_POLYGON);
//	glColor3fv(colors[a]);
//	glVertex3fv(vertices[a]);
//	glColor3fv(colors[b]);
//	glVertex3fv(vertices[b]);
//	glColor3fv(colors[c]);
//	glVertex3fv(vertices[c]);
//	glColor3fv(colors[d]);
//	glVertex3fv(vertices[d]);
//	glEnd();
//}
//
//void display()
//{
//	init();
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity(); // load an identity matrix
//
//	if (view == 1)
//		glScalef(scale, scale, scale);
//
//	if (axis == 0)
//		glRotatef(theta, 1.0, 0.0, 0.0); // rotation about x-axis 
//	if (axis == 1)
//		glRotatef(theta, 0.0, 1.0, 0.0); // rotation about y-axis 
//	if (axis == 2)
//		glRotatef(theta, 0.0, 0.0, 1.0); // rotation about z-axis 
//
//	gluLookAt(x_axis, y_axis, z_axis, 0, 0, 0, 0, 1, 0);
//
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
//
//	glFlush();
//	glutSwapBuffers(); // Use double-buffering
//}
//
//void spin_cube()
//{
//	theta += 0.1;
//	if (theta > 360.0) theta -= 360.0;
//	glutPostRedisplay();
//}
//
//void keyboard_handler(unsigned char key, int x, int y)
//{
//	if (key == 'x')
//		x_axis -= 0.1;
//	if (key == 'X')
//		x_axis += 0.1;
//	if (key == 'y')
//		y_axis -= 0.1;
//	if (key == 'Y')
//		y_axis += 0.1;
//	if (key == 'z')
//		z_axis -= 0.1;
//	if (key == 'Z')
//		z_axis += 0.1;
//	if (key == 'd')
//	{
//		x_axis = 3;
//		y_axis = 3;
//		z_axis = 3;
//	}
//	if (key == 'p')
//	{
//		if (view == 0)
//			view = 1;
//		else
//			view = 0;
//	}
//
//	glutPostRedisplay();
//}
//
//void mouse_handler(int btn, int state, int x, int y)
//{
//	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//		axis = 0;
//	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
//		axis = 1;
//	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//		axis = 2;
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog20: Perspective Projection");
//	//glutIdleFunc(spin_cube);
//	glutKeyboardFunc(keyboard_handler); // add keyboard handler
//	glutMouseFunc(mouse_handler); // add mouse handler
//	glutDisplayFunc(display);
//	init();
//	glutMainLoop();
//	return 0;
//}









//Prog20_1: TeaPot

#include "stdafx.h"
#include <math.h>
#include <gl/glut.h>

int width = 500, height = 500;

static GLfloat theta = 0.0; // variable for rotation
static GLfloat scale = 0.7;
static int axis = 0;

static GLfloat x_axis = 3;
static GLfloat y_axis = 3;
static GLfloat z_axis = 3;

static int view = 0;

void init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.3, 0.3, 0.7);
	glMatrixMode(GL_PROJECTION); // change to projection view
	glLoadIdentity(); // load identity matrix
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW); // restore to model view
	glLoadIdentity(); // load identity matrix
}

void MyDisplay()
{
	glViewport(0, 0, width / 2, height / 2);
	glPushMatrix();
		gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glutWireTeapot(1.0);
	glPopMatrix();
	glViewport(width / 2, 0, width / 2, height / 2);
	glPushMatrix();
		gluLookAt(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glutWireTeapot(1.0);
	glPopMatrix();
	glViewport(0, height / 2, width / 2, height / 2);
	glPushMatrix();
		gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
		glutWireTeapot(1.0);
	glPopMatrix();
	glViewport(width / 2, height / 2, width / 2, height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			glutWireTeapot(1.0);
		glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE| GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Prog20_1: TeaPot");
	init();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}