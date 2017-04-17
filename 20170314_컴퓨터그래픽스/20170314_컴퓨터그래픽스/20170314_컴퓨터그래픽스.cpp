// 20170314_��ǻ�ͱ׷��Ƚ�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <GL\glut.h>

void init();
void display();

/*
//���� 1!

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500); //window ������ ���ϱ�!
	glutCreateWindow("Prog01: first OpenGL program"); //������ ������ ��� window�� ����� ����!
	glutDisplayFunc(display); //�� �Լ��� window�ȿ� �׷����� ��� �Լ����� �׸��� �Ұ��� ����� �ϴ°���!
	
	init(); //�⺻ �����ϴ� �Լ���!
	glutMainLoop();//window�� ������� �̺�Ʈ�� �ޱ����� loop�� ���� ����!
    
	return 0;
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //����� ������� ������ ����!
	glColor3f(1.0, 0.0, 0.0); //�׷��� ���� ���������� ������ ����!
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);//�׸� �׷����� ��ǥ���� �����Ѱ���!
	//->�̰� window ��������� ����̾���! �������� ��ǥ����!
	//�ʱ�ȭ �۾���
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); //buffer������ clearcolor�� ������� �����ϴ°���!
	glBegin(GL_POINTS);//���� ��ڴٴ� ����!
	
	for (double f = 10; f<40; f += 0.1)
	{//for���� ���鼭 �׷��� ��ǥ���� �ش� ��ǥ�� ���� ��� ����!
		glVertex2f(f, 10); glVertex2f(f, 40);
		glVertex2f(10, f); glVertex2f(40, f);
	}
	//�� ������� �簢���� �ѹ��� �׸��� ����� ����!

	glEnd();
	glFlush();
}
*/

/*
//���� 2
void timer(int t);
static int delay = 1000; // milliseconds
int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog02: Random boxes");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0); // set timer function which is called for each delay (ms)
	//timer����� func��! callback�Լ��� �ؿ� �ִ� timer��� �Լ���!
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	srand(time(0)); // initialize seed for rand() (stdlib, time)
	//seed�� �ٲ㼭 random�ϰ� ���ִ� ����!
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
}
void display()
{
	//glClear(GL_COLOR_BUFFER_BIT);//��� �ʱ�ȭ
	int x1, y1, x2, y2, r, g, b;
	x1 = rand() % 50; y1 = rand() % 50; x2 = rand() % 50; y2 = rand() % 50; // get random position
	r = rand() % 256; g = rand() % 256; b = rand() % 256; // get random color
	glColor3f((GLfloat)r / 255, (GLfloat)g / 255, (GLfloat)b / 255); // set color
	glBegin(GL_POLYGON); // start to accept polygon
	glVertex2f(x1, y1); glVertex2f(x1, y2); // draw vertices
	glVertex2f(x2, y2); glVertex2f(x2, y1); // draw vertices
	glEnd(); // finish polygon
	glFlush();
}

void timer(int t)
{
	glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
	//OS���� display�� �޶�� ȣ���� �Ѱ��ִ� ����!
	glutTimerFunc(delay, timer, t); // set timer function again //���ȣ��!
}
*/

void timer(int t);
static int delay = 1; // milliseconds
static double x, y;
double xinc, yinc;
int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog03: Bouncing Pixel");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0); // set timer function which is called for each delay (ms)
									//timer����� func��! callback�Լ��� �ؿ� �ִ� timer��� �Լ���!
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	srand(time(0)); // initialize seed for rand() (stdlib, time)
					//seed�� �ٲ㼭 random�ϰ� ���ִ� ����!
	x = rand() % 50;
	y = rand() % 50;
	//xinc = ((rand() % 10) + 1) / 10.0 - 0.1;
	//yinc = ((rand() % 10) + 1) / 10.0 - 0.1;

	xinc = (rand() % 21 - 10) / 100.0;
	yinc = (rand() % 21 - 10) / 100.0;

	printf("( %lf, %lf )\n", x, y);
	printf("xinc: %lf, yinc: %lf\n", xinc, yinc);

	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
}
void display()
{
	//glClear(GL_COLOR_BUFFER_BIT);//��� �ʱ�ȭ
	x += xinc;
	y += yinc;

	printf("( %lf, %lf )\n", x, y);

	if (x > 50|| x < 0)
		xinc = -xinc;
	if (y > 50 || y < 0)
		yinc = -yinc;

	glBegin(GL_POINTS);
	glColor3f((GLfloat)x / 50, 0, (GLfloat)y / 50); // set color
	glVertex2f(x, y);
	
	glEnd();
	glFlush();
}

void timer(int t)
{
	glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
						 //OS���� display�� �޶�� ȣ���� �Ѱ��ִ� ����!
	glutTimerFunc(delay, timer, t); // set timer function again //���ȣ��!
}