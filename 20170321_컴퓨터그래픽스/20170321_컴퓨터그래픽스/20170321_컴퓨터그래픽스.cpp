// 20170321_컴퓨터그래픽스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//Prog06: Bouncing Triangle

//#include "stdafx.h"
//#include <stdlib.h>
//#include <time.h>
//#include <GL\glut.h>
//
//void init();
//void display();
//void timer(int t);
//static int delay = 1; // milliseconds
//static double x1, y1, x2, y2, x3, y3;
//double xinc1, yinc1, xinc2, yinc2, xinc3, yinc3;
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("Prog06: Bouncing Triangle");
//	glutDisplayFunc(display);
//	glutTimerFunc(delay, timer, 0); // set timer function which is called for each delay (ms)
//									//timer만드는 func임! callback함수가 밑에 있는 timer라는 함수임!
//	init();
//	glutMainLoop();
//	return 0;
//}
//
//void init()
//{
//	srand(time(0)); // initialize seed for rand() (stdlib, time)
//					//seed를 바꿔서 random하게 해주는 거임!
//	x1 = rand() % 50;
//	y1 = rand() % 50;
//
//	x2 = rand() % 50;
//	y2 = rand() % 50;
//
//	x3 = rand() % 50;
//	y3 = rand() % 50;
//
//	//xinc = ((rand() % 10) + 1) / 10.0 - 0.1;
//	//yinc = ((rand() % 10) + 1) / 10.0 - 0.1;
//
//	xinc1 = (rand() % 21 - 10) / 100.0;
//	yinc1 = (rand() % 21 - 10) / 100.0;
//	xinc2 = (rand() % 21 - 10) / 100.0;
//	yinc2 = (rand() % 21 - 10) / 100.0;
//	xinc3 = (rand() % 21 - 10) / 100.0;
//	yinc3 = (rand() % 21 - 10) / 100.0;
//
//	printf("1. ( %lf, %lf )\n", x1, y1);
//	printf("2. ( %lf, %lf )\n", x2, y2);
//	printf("3. ( %lf, %lf )\n", x3, y3);
//	printf("1. xinc: %lf, yinc: %lf\n", xinc1, yinc1);
//	printf("2. xinc: %lf, yinc: %lf\n", xinc2, yinc2);
//	printf("3. xinc: %lf, yinc: %lf\n", xinc3, yinc3);
//
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
//	glClear(GL_COLOR_BUFFER_BIT); // clear background here
//}
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);//배경 초기화
//	x1 += xinc1;
//	y1 += yinc1;
//	x2 += xinc2;
//	y2 += yinc2;
//	x3 += xinc3;
//	y3 += yinc3;
//
//	printf("1.( %lf, %lf )\n", x1, y1);
//	printf("2.( %lf, %lf )\n", x2, y2);
//	printf("3.( %lf, %lf )\n", x3, y3);
//
//	if (x1 > 50 || x1 < 0)
//		xinc1 = -xinc1;
//	if (y1 > 50 || y1 < 0)
//		yinc1 = -yinc1;
//	if (x2 > 50 || x2 < 0)
//		xinc2 = -xinc2;
//	if (y2 > 50 || y2 < 0)
//		yinc2 = -yinc2;
//	if (x3 > 50 || x3 < 0)
//		xinc3 = -xinc3;
//	if (y3 > 50 || y3 < 0)
//		yinc3 = -yinc3;
//
//	glBegin(GL_POLYGON);
//	glColor3f((GLfloat)x1 / 50, 0, (GLfloat)y1 / 50); // set color
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glVertex2f(x3, y3);
//
//	glEnd();
//	glFlush();
//}
//
//void timer(int t)
//{
//	glutPostRedisplay(); // redraw gralatitudecs (rather than calling display() itself)
//						 //OS에게 display해 달라고 호출을 넘겨주는 거임!
//	glutTimerFunc(delay, timer, t); // set timer function again //재귀호출!
//}






//Prog07: First 3D Program
/*
#include "stdafx.h"
#include <GL\glut.h>

void init();
void display();

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog07: First 3D Program");
	glutDisplayFunc(display);

	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(0.0, 50.0, 0.0, 50.0, 50.0, -50.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(15, 15, 35); 
	glVertex3f(35, 15, 35); 
	glVertex3f(35, 35, 35); 
	glVertex3f(15, 35, 35);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(15, 15, 35); 
	glVertex3f(35, 15, 35); 
	glVertex3f(40, 20, 15); 
	glVertex3f(20, 20, 15);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(20, 20, 15); 
	glVertex3f(40, 20, 15); 
	glVertex3f(40, 40, 15); 
	glVertex3f(20, 40, 15);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(20, 40, 15); 
	glVertex3f(40, 40, 15); 
	glVertex3f(35, 35, 35); 
	glVertex3f(15, 35, 35);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(20, 40, 15); 
	glVertex3f(20, 20, 15);
	glVertex3f(15, 15, 35);
	glVertex3f(15, 35, 35); 
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(40, 20, 15); 
	glVertex3f(40, 40, 15); 
	glVertex3f(35, 35, 35);
	glVertex3f(35, 15, 35);
	glEnd();

	glFlush();
}
*/





//Prog08: Hidden Surface Removal
/*
#include "stdafx.h"
#include <GL\glut.h>

void init();
void display();

int main(int argc, char* argv[])
{
glutInit(&argc, (char**)argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // add display mode to enable depth test
glutInitWindowSize(500, 500);
glutCreateWindow("Prog08: Hidden Surface Removal");
glutDisplayFunc(display);

init();
glutMainLoop();
return 0;
}

void init()
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glOrtho(0.0, 50.0, 0.0, 50.0, -50.0, 50.0);
glEnable(GL_DEPTH_TEST); // enable depth test
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // add GL_DEPTH_BUFFER_BIT

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f(15, 15, 35);
glVertex3f(35, 15, 35);
glVertex3f(35, 35, 35);
glVertex3f(15, 35, 35);
glEnd();

glColor3f(0.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f(15, 15, 35);
glVertex3f(35, 15, 35);
glVertex3f(40, 20, 15);
glVertex3f(20, 20, 15);
glEnd();

glColor3f(0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f(20, 20, 15);
glVertex3f(40, 20, 15);
glVertex3f(40, 40, 15);
glVertex3f(20, 40, 15);
glEnd();

glColor3f(1.0, 1.0, 0.0);
glBegin(GL_POLYGON);
glVertex3f(20, 40, 15);
glVertex3f(40, 40, 15);
glVertex3f(35, 35, 35);
glVertex3f(15, 35, 35);
glEnd();

glColor3f(0.0, 1.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f(20, 40, 15);
glVertex3f(20, 20, 15);
glVertex3f(15, 15, 35);
glVertex3f(15, 35, 35);
glEnd();

glColor3f(1.0, 0.0, 1.0);
glBegin(GL_POLYGON);
glVertex3f(40, 20, 15);
glVertex3f(40, 40, 15);
glVertex3f(35, 35, 35);
glVertex3f(35, 15, 35);
glEnd();

glFlush();
}
*/





//Prog09: Sphere

#include "stdafx.h"
#include <GL\glut.h>
#include<math.h>

void init();
void display();

int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // add display mode to enable depth test
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog09: Sphere");
	glutDisplayFunc(display);

	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glEnable(GL_DEPTH_TEST); // enable depth test
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // add GL_DEPTH_BUFFER_BIT
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	float latitude, longitude;
	float latituder, latituder20, longituder; //라디안 값으로 바꿀때 사용하는 거임!
	float M_PI = atan(1.0) * 4;
	float c = M_PI / 180.0;
	float x, y, z;

	glClear(GL_COLOR_BUFFER_BIT);

	for (latitude = -80.0; latitude <= 80.0; latitude += 20.0)
	{
		latituder = c*latitude;
		latituder20 = c*(latitude + 20);

		glBegin(GL_QUAD_STRIP);
		for (longitude = -180.0; longitude <= 180.0; longitude += 20.0)
		{
			//glColor3f(fabs(longitude) / 180, 0.0, 0.0);
			glColor3f(0.0, 0.0, 1.0);

			longituder = c*longitude;
			x = sin(longituder)*cos(latituder);
			y = cos(longituder)*cos(latituder);
			z = sin(latituder);
			glVertex3f(x, y, z);

			x = sin(longituder)*cos(latituder20);
			y = cos(longituder)*cos(latituder20);
			z = sin(latituder);
			glVertex3f(x, y, z);
		}
		glEnd();
	}

	float c80 = c*90.0;

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, 1.0);
	z = sin(c80);

	for (longitude = -180.0; longitude <= 180.0; longitude += 20.0)
	{
		//glColor3f(fabs(longitude) / 180, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);

		longituder = c*longitude;
		x = sin(longituder)*cos(c80);
		y = cos(longituder)*cos(c80);
		glVertex3f(x, y, z);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, -1.0);
	z = -sin(c80);

	for (longitude = -180.0; longitude <= 180.0; longitude += 20.0)
	{
		//glColor3f(fabs(longitude) / 180, 0.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);

		longituder = c*longitude;
		x = sin(longituder)*cos(c80);
		y = cos(longituder)*cos(c80);
		glVertex3f(x, y, z);
	}


	glEnd();
	glFlush();
}