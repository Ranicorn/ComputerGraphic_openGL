// 20170314_컴퓨터그래픽스.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <GL\glut.h>

void init();
void display();

/*
//예제 1!

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500); //window 사이즈 정하기!
	glutCreateWindow("Prog01: first OpenGL program"); //설정한 사이즈 대로 window를 만드는 거임!
	glutDisplayFunc(display); //이 함수는 window안에 그래픽을 어느 함수에서 그리게 할건지 등록을 하는거임!
	
	init(); //기본 설정하는 함수임!
	glutMainLoop();//window와 사용자의 이벤트를 받기위한 loop를 도는 거임!
    
	return 0;
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경을 흰색으로 설정한 거임!
	glColor3f(1.0, 0.0, 0.0); //그래픽 색을 빨간색으로 설정한 거임!
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);//그릴 그래픽의 좌표값을 설정한거임!
	//->이건 window 사이즈랑은 상관이없음! 절대적인 좌표값임!
	//초기화 작업들
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); //buffer공간을 clearcolor인 흰색으로 설정하는거임!
	glBegin(GL_POINTS);//점을 찍겠다는 거임!
	
	for (double f = 10; f<40; f += 0.1)
	{//for문을 돌면서 그래픽 좌표안의 해당 좌표에 점을 찍는 거임!
		glVertex2f(f, 10); glVertex2f(f, 40);
		glVertex2f(10, f); glVertex2f(40, f);
	}
	//이 방법말고도 사각형을 한번에 그리는 방법이 있음!

	glEnd();
	glFlush();
}
*/

/*
//예제 2
void timer(int t);
static int delay = 1000; // milliseconds
int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog02: Random boxes");
	glutDisplayFunc(display);
	glutTimerFunc(delay, timer, 0); // set timer function which is called for each delay (ms)
	//timer만드는 func임! callback함수가 밑에 있는 timer라는 함수임!
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	srand(time(0)); // initialize seed for rand() (stdlib, time)
	//seed를 바꿔서 random하게 해주는 거임!
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glClear(GL_COLOR_BUFFER_BIT); // clear background here
}
void display()
{
	//glClear(GL_COLOR_BUFFER_BIT);//배경 초기화
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
	//OS에게 display해 달라고 호출을 넘겨주는 거임!
	glutTimerFunc(delay, timer, t); // set timer function again //재귀호출!
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
									//timer만드는 func임! callback함수가 밑에 있는 timer라는 함수임!
	init();
	glutMainLoop();
	return 0;
}

void init()
{
	srand(time(0)); // initialize seed for rand() (stdlib, time)
					//seed를 바꿔서 random하게 해주는 거임!
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
	//glClear(GL_COLOR_BUFFER_BIT);//배경 초기화
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
						 //OS에게 display해 달라고 호출을 넘겨주는 거임!
	glutTimerFunc(delay, timer, t); // set timer function again //재귀호출!
}