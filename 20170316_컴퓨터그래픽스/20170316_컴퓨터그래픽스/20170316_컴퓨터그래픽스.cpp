// 20170316_��ǻ�ͱ׷��Ƚ�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <GL\glut.h>

void init();
void display();
int num = 5;

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog04: Recursive Triangles");
	glutDisplayFunc(display);

	init();
	glutMainLoop();
	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
}
void display()
{
	//glClear(GL_COLOR_BUFFER_BIT);//��� �ʱ�ȭ

	GLfloat v[3][2] = { (0,0), (25, 50), (50,0) };

	triangle(1, v);

	glEnd();
	glFlush();
}

void triangle(int count, GLfloat* v)
{
	if (count == num)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 1.0); // set color
	}
	else
	{
		triangle(count++,)
	}
}