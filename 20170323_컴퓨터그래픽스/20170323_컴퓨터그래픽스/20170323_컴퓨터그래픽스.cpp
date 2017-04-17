// 20170323_컴퓨터그래픽스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
									//timer만드는 func임! callback함수가 밑에 있는 timer라는 함수임!
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
	glClear(GL_COLOR_BUFFER_BIT);//배경 초기화

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
						 //OS에게 display해 달라고 호출을 넘겨주는 거임!
	glutTimerFunc(delay, timer, t); // set timer function again //재귀호출!

	if (theta == 90)
		m = -m;
	if (theta == 0)
		if (m < 0)
			m = -m;

	theta += m;

	printf("Theta: %f\n", theta);
}
