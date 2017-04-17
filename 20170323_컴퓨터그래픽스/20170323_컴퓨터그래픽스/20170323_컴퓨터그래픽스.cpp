// 20170323_��ǻ�ͱ׷��Ƚ�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//


//Prog10: Image in 3D

#include "stdafx.h"
#include<stdlib.h>
#include <math.h>
#include <time.h>
#include <GL\glut.h>

#pragma warning(disable:4996)

void init();
void display();
void timer(int t);
static int delay = 100; // milliseconds
static float theta = 0;
static int m = 5;

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog10: Image in 3D");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0); // set timer function which is called for each delay (ms)
									//timer����� func��! callback�Լ��� �ؿ� �ִ� timer��� �Լ���!
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(0.0, 416.0, 0.0, 240.0, -500.0, 500.0);
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
	glPointSize(8);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//��� �ʱ�ȭ

	static unsigned char image[240][416];
	FILE* fr = fopen("testo.y", "rb");
	if (fr == NULL)
	{
		printf("Image couldn't open!!\n");
		exit(0);
	}

	fread(image, 416 * 240, sizeof(char), fr);
	fclose(fr);

	int x, y;
	float thetar;
	float c;

	thetar = theta * ((atan(1.0)*4.0) / 180.0);
	for (x = 0; x < 240; x++)
	{
		for (y = 0; y < 416; y++)
		{
			c = image[x][y] / 255.0;
			glBegin(GL_POINTS);
			
			glColor3f(c, c, c);
			//glVertex3f(x*cos(thetar), 239 - y, x*sin(thetar));
			//glVertex3f(y, 239-x, 0);
			glVertex3f(y*cos(thetar), 239 - x, x*sin(thetar));
		}
	}

	glEnd();
	glFlush();
}

void timer(int t)
{
	glutPostRedisplay(); // redraw gralatitudecs (rather than calling display() itself)
						 //OS���� display�� �޶�� ȣ���� �Ѱ��ִ� ����!
	glutTimerFunc(delay, timer, t); // set timer function again //���ȣ��!

	if (theta == 90)
		m = -m;
	if (theta == 0)
		if (m < 0)
			m = -m;

	theta += m;

	printf("Theta: %f\n", theta);
}
