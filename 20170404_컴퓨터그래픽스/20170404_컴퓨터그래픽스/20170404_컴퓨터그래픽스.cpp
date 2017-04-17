// 20170404_컴퓨터그래픽스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//Prog14: Color Cube

//#include "stdafx.h"
//#include <math.h>
//#include <gl/glut.h>
//
//GLfloat vertices[][3] = {
//	{-1.0, -1.0, -1.0}, {1.0, -1.0 , -1.0 }, { 1.0 , 1.0 , -1.0 },{-1.0 , 1.0 , -1.0 },
//	{-1.0 , -1.0 , 1.0 }, { 1.0 , -1.0 , 1.0 }, { 1.0 , 1.0 , 1.0 }, {-1.0 , 1.0 , 1.0 } };
//GLfloat colors[][3] = {
//	{0.0, 0.0, 0.0}, { 1.0 , 0.0, 0.0}, { 1.0 , 1.0 , 0.0},{0.0, 1.0 , 0.0},
//	{0.0, 0.0, 1.0 }, { 1.0 , 0.0, 1.0 }, { 1.0 , 1.0 , 1.0 }, {0.0, 1.0 , 1.0 } };
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
//	glEnable(GL_DEPTH_TEST);
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

//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
//	glFlush();
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog14: Color Cube");
//	glutDisplayFunc(display);
//	init();
//	glutMainLoop();
//	return 0;
//}



////Prog15: Color Cube with Transformation
//
//#include "stdafx.h"
//#include <math.h>
//#include <gl/glut.h>
//
//GLfloat vertices[][3] = {
//	{-1.0, -1.0, -1.0}, {1.0, -1.0 , -1.0 }, { 1.0 , 1.0 , -1.0 },{-1.0 , 1.0 , -1.0 },
//	{-1.0 , -1.0 , 1.0 }, { 1.0 , -1.0 , 1.0 }, { 1.0 , 1.0 , 1.0 }, {-1.0 , 1.0 , 1.0 } };
//GLfloat colors[][3] = {
//	{0.0, 0.0, 0.0}, { 1.0 , 0.0, 0.0}, { 1.0 , 1.0 , 0.0},{0.0, 1.0 , 0.0},
//	{0.0, 0.0, 1.0 }, { 1.0 , 0.0, 1.0 }, { 1.0 , 1.0 , 1.0 }, {0.0, 1.0 , 1.0 } };
//
//static GLfloat theta = 0.0; // variable for rotation
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
//	glRotatef(theta, 0.0, 1.0, 0.0); // rotation about y-axis (0.0, 1.0, 0.0)
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
//	glFlush();
//}
//
//void spin_cube()
//{
//	theta += 0.1;
//	if (theta > 360.0) theta -= 360.0;
//	glutPostRedisplay();
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog15: Color Cube with Transformation");
//	glutIdleFunc(spin_cube);
//	glutDisplayFunc(display);
//	init();
//	glutMainLoop();
//	return 0;
//}




////Prog16: Smooth Color Cube with Transformation
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
//	glRotatef(theta, 0.0, 1.0, 0.0); // rotation about y-axis (0.0, 1.0, 0.0)
//	polygon(0, 3, 2, 1);
//	polygon(2, 3, 7, 6);
//	polygon(0, 4, 7, 3);
//	polygon(1, 2, 6, 5);
//	polygon(4, 5, 6, 7);
//	polygon(0, 1, 5, 4);
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
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog16: Smooth Color Cube with Transformation");
//	glutIdleFunc(spin_cube);
//	glutDisplayFunc(display);
//	init();
//	glutMainLoop();
//	return 0;
//}





//Prog17: Interactivity

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
static GLfloat scale = 1.0;
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

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
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

	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);

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
	glutCreateWindow("Prog17: Interactivity");
	glutIdleFunc(spin_cube);
	glutKeyboardFunc(keyboard_handler); // add keyboard handler
	glutMouseFunc(mouse_handler); // add mouse handler
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}