// 20170328_��ǻ�ͱ׷��Ƚ�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//


////Prog10: Hidden Surface Removal Again!
//
//#include "stdafx.h"
//#include <GL\glut.h>
//
//void init();
//void display();
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // add display mode to enable depth test
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog10: Hidden Surface Removal Again!");
//	glutDisplayFunc(display);
//
//	init();
//	glutMainLoop();
//	return 0;
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(0.0, 50.0, 0.0, 50.0, -50.0, 50.0);
//	glEnable(GL_DEPTH_TEST); // enable depth test
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // add GL_DEPTH_BUFFER_BIT
//
//	GLfloat v0[3] = { 15, 15, 35 }, v1[3] = { 35, 15, 35 }, v2[3] = { 35,35, 35 }, v3[3] = { 15, 35, 35 };
//	GLfloat v4[3] = { 40, 20, 15 }, v5[3] = { 20, 20, 15 }, v6[3] = { 40,40, 15 }, v7[3] = { 20, 40, 15 };
//
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v1);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v1);
//	glVertex3fv(v4);
//	glVertex3fv(v5);
//	glEnd();
//
//	glColor3f(0.0, 0.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v5);
//	glVertex3fv(v4);
//	glVertex3fv(v6);
//	glVertex3fv(v7);
//	glEnd();
//
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v7);
//	glVertex3fv(v6);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(0.0, 1.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v5);
//	glVertex3fv(v7);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(1.0, 0.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v1);
//	glVertex3fv(v4);
//	glVertex3fv(v6);
//	glVertex3fv(v2);
//	glEnd();
//
//	glFlush();
//}






////Prog011: 3D Cube Rotation
//
//#include "stdafx.h"
//#include <GL\glut.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//
//void init();
//void display();
//void timer(int t);
//void rotate(GLfloat*);
//static int delay = 10; // milliseconds
//static int theta = 0;
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // add display mode to enable depth test
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog011: 3D Cube Rotation");
//	glutDisplayFunc(display);
//	glutTimerFunc(delay, timer, 0);
//
//	init();
//	glutMainLoop();
//	return 0;
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
//	glEnable(GL_DEPTH_TEST); // enable depth test
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // add GL_DEPTH_BUFFER_BIT
//
//	GLfloat v0[3] = { 15, 15, 35 }, v1[3] = { 35, 15, 35 }, v2[3] = { 35,35, 35 }, v3[3] = { 15, 35, 35 };
//	GLfloat v4[3] = { 40, 20, 15 }, v5[3] = { 20, 20, 15 }, v6[3] = { 40,40, 15 }, v7[3] = { 20, 40, 15 };
//	
//	rotate(v0);
//	rotate(v1);
//	rotate(v2);
//	rotate(v3);
//	rotate(v4);
//	rotate(v5);
//	rotate(v6);
//	rotate(v7);
//
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v1);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v1);
//	glVertex3fv(v4);
//	glVertex3fv(v5);
//	glEnd();
//
//	glColor3f(0.0, 0.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v5);
//	glVertex3fv(v4);
//	glVertex3fv(v6);
//	glVertex3fv(v7);
//	glEnd();
//
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v7);
//	glVertex3fv(v6);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(0.0, 1.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v5);
//	glVertex3fv(v7);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(1.0, 0.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v1);
//	glVertex3fv(v4);
//	glVertex3fv(v6);
//	glVertex3fv(v2);
//	glEnd();
//
//	glFlush();
//}
//
//void rotate(GLfloat* v)
//{
//	float thetar = theta*(4.0*atan(1.0)) / 180.0;
//
//	v[0] = (v[0] * cos(thetar)) + (v[2] * sin(thetar));
//	v[2] = (v[0] * -sin(thetar)) + (v[2] * cos(thetar));
//}
//
//void timer(int t)
//{
//	glutPostRedisplay(); // redraw gralatitudecs (rather than calling display() itself)
//						 //OS���� display�� �޶�� ȣ���� �Ѱ��ִ� ����!
//	glutTimerFunc(delay, timer, t); // set timer function again //���ȣ��!
//	
//	theta++;
//}







////Prog12: Center of Rotation
//
//#include "stdafx.h"
//#include <GL\glut.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//
//void init();
//void display();
//void timer(int t);
//void rotate(GLfloat*);
//void center(GLfloat*);
//static int delay = 10; // milliseconds
//static int theta = 0;
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // add display mode to enable depth test
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog12: Center of Rotation");
//	glutDisplayFunc(display);
//	glutTimerFunc(delay, timer, 0);
//
//	init();
//	glutMainLoop();
//	return 0;
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
//	glEnable(GL_DEPTH_TEST); // enable depth test
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // add GL_DEPTH_BUFFER_BIT
//
//	GLfloat v0[3] = { 15, 15, 35 }, v1[3] = { 35, 15, 35 }, v2[3] = { 35,35, 35 }, v3[3] = { 15, 35, 35 };
//	GLfloat v4[3] = { 40, 20, 15 }, v5[3] = { 20, 20, 15 }, v6[3] = { 40,40, 15 }, v7[3] = { 20, 40, 15 };
//
//	center(v0);
//	center(v1);
//	center(v2);
//	center(v3);
//	center(v4);
//	center(v5);
//	center(v6);
//	center(v7);
//
//	rotate(v0);
//	rotate(v1);
//	rotate(v2);
//	rotate(v3);
//	rotate(v4);
//	rotate(v5);
//	rotate(v6);
//	rotate(v7);
//
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v1);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(0.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v1);
//	glVertex3fv(v4);
//	glVertex3fv(v5);
//	glEnd();
//
//	glColor3f(0.0, 0.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v5);
//	glVertex3fv(v4);
//	glVertex3fv(v6);
//	glVertex3fv(v7);
//	glEnd();
//
//	glColor3f(1.0, 1.0, 0.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v7);
//	glVertex3fv(v6);
//	glVertex3fv(v2);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(0.0, 1.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v0);
//	glVertex3fv(v5);
//	glVertex3fv(v7);
//	glVertex3fv(v3);
//	glEnd();
//
//	glColor3f(1.0, 0.0, 1.0);
//	glBegin(GL_POLYGON);
//	glVertex3fv(v1);
//	glVertex3fv(v4);
//	glVertex3fv(v6);
//	glVertex3fv(v2);
//	glEnd();
//
//	glFlush();
//}
//
//void rotate(GLfloat* v)
//{
//	float thetar = theta*(4.0*atan(1.0)) / 180.0;
//
//	v[0] = (v[0] * cos(thetar)) + (v[2] * sin(thetar));
//	v[2] = (v[0] * -sin(thetar)) + (v[2] * cos(thetar));
//}
//
//void center(GLfloat* v)
//{
//	v[0] = v[0] - 25;
//	v[1] = v[1] - 25;
//	v[2] = v[2] - 25;
//}
//
//void timer(int t)
//{
//	glutPostRedisplay(); // redraw gralatitudecs (rather than calling display() itself)
//						 //OS���� display�� �޶�� ȣ���� �Ѱ��ִ� ����!
//	glutTimerFunc(delay, timer, t); // set timer function again //���ȣ��!
//
//	theta++;
//}



//Prog13: Scaling

#include "stdafx.h"
#include <GL\glut.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void init();
void display();
void timer(int t);
void rotate(GLfloat*);
void translate(GLfloat*);
static int delay = 10; // milliseconds
static int theta = 0;

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // add display mode to enable depth test
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog13: Scaling");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0);

	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
	glEnable(GL_DEPTH_TEST); // enable depth test
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // add GL_DEPTH_BUFFER_BIT

	GLfloat v0[3] = { 15, 15, 35 }, v1[3] = { 35, 15, 35 }, v2[3] = { 35,35, 35 }, v3[3] = { 15, 35, 35 };
	GLfloat v4[3] = { 40, 20, 15 }, v5[3] = { 20, 20, 15 }, v6[3] = { 40,40, 15 }, v7[3] = { 20, 40, 15 };

	translate(v0);
	translate(v1);
	translate(v2);
	translate(v3);
	translate(v4);
	translate(v5);
	translate(v6);
	translate(v7);

	rotate(v0);
	rotate(v1);
	rotate(v2);
	rotate(v3);
	rotate(v4);
	rotate(v5);
	rotate(v6);
	rotate(v7);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(v0);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(v0);
	glVertex3fv(v1);
	glVertex3fv(v4);
	glVertex3fv(v5);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(v5);
	glVertex3fv(v4);
	glVertex3fv(v6);
	glVertex3fv(v7);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3fv(v7);
	glVertex3fv(v6);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(v0);
	glVertex3fv(v5);
	glVertex3fv(v7);
	glVertex3fv(v3);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3fv(v1);
	glVertex3fv(v4);
	glVertex3fv(v6);
	glVertex3fv(v2);
	glEnd();

	glFlush();
}

void rotate(GLfloat* v)
{
	float thetar = theta*(4.0*atan(1.0)) / 180.0;

	v[0] = (v[0] * cos(thetar)) + (v[2] * sin(thetar));
	v[2] = (v[0] * -sin(thetar)) + (v[2] * cos(thetar));
}

void translate(GLfloat* v)
{
	v[0] = v[0] - 25;
	v[1] = v[1] - 25;
	v[2] = v[2] - 25;
}

void timer(int t)
{
	glutPostRedisplay(); // redraw gralatitudecs (rather than calling display() itself)
						 //OS���� display�� �޶�� ȣ���� �Ѱ��ִ� ����!
	glutTimerFunc(delay, timer, t); // set timer function again //���ȣ��!

	theta++;
}