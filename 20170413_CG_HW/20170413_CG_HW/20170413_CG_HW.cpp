// 20170413_CG_HW.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

//Prog20_1: TeaPot_FPS

#include "stdafx.h"
#include <math.h>
#include <gl/glut.h>

#define WALK 0.005
#define TURN 0.01

int width = 500, height = 500;

static GLfloat theta = 0.0; // variable for rotation
static GLfloat scale = 0.7;
static int axis = 0;

static GLfloat eyeX = 2;
static GLfloat eyeY = 2;
static GLfloat eyeZ = 2;

static GLfloat centerX = 0;
static GLfloat centerY = 0;
static GLfloat centerZ = 0;

static GLfloat upX = 0;
static GLfloat upY = 1;
static GLfloat upZ = 0;

static GLfloat vX = 0;
static GLfloat vY = 0;
static GLfloat vZ = 0;

static int Mx = 0, My = 0;

void init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.3, 0.3, 0.7);
	glMatrixMode(GL_PROJECTION); // change to projection view
	glLoadIdentity(); // load identity matrix
	glFrustum(-2.0, 2.0, -2.0, 2.0, 2.0, 20.0);
	glMatrixMode(GL_MODELVIEW); // restore to model view
	glLoadIdentity(); // load identity matrix
}

void mouse_handler(int x, int y)
{
	vX = centerX - eyeX;
	vZ = centerZ - eyeZ;

	if (x - Mx > 0)
	{
		centerX = eyeX + cos(TURN)*vX - sin(TURN)*vZ;
		centerZ = eyeZ + sin(TURN)*vX + cos(TURN)*vZ;
	}
	else
	{
		centerX = eyeX + cos(-TURN)*vX - sin(-TURN)*vZ;
		centerZ = eyeZ + sin(-TURN)*vX + cos(-TURN)*vZ;
	}

	Mx = x;
	My = y;
	glutPostRedisplay();
}

void keyboard_handler(unsigned char key, int x, int y)
{
	vX = centerX - eyeX;
	vZ = centerZ - eyeZ;

	if (key == 'w')
	{
		eyeX += vX*WALK;
		eyeZ += vZ*WALK;
		centerX += vX*WALK;
		centerZ += vZ*WALK;
		printf("W\n");
	}
	if (key == 's')
	{
		eyeX -= vX*WALK;
		eyeZ -= vZ*WALK;
		centerX -= vX*WALK;
		centerZ -= vZ*WALK;
		printf("S\n");
	}

	if (key == 'a')
	{
		eyeX += vX*WALK;
		eyeZ -= vX*WALK;
		centerX += vX*WALK;
		centerZ -= vX*WALK;

		printf("A\n");
	}
	if (key == 'd')
	{
		eyeX -= vX*WALK;
		eyeZ += vX*WALK;
		centerX -= vX*WALK;
		centerZ += vX*WALK;

		printf("D\n");
	}
	if (key == 'D') //default view
	{
		eyeX = 2;
		eyeY = 2;
		eyeZ = 2;

		centerX = 0;
		centerY = 0;
		centerZ = 0;

		upX = 0;
		upY = 1;
		upZ = 0;
	}

	glutPostRedisplay();
}

void MyDisplay()
{
	init();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
		glutWireTeapot(1.0);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE| GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Prog20_1: TeaPot_FPS");
	glutKeyboardFunc(keyboard_handler); // add keyboard handler
	glutMotionFunc(mouse_handler);
	//glutPassiveMotionFunc(mouse_handler);
	init();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}