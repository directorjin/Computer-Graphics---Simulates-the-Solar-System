#include <stdlib.h>
#include <gl/glut.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <cmath> //power�� ��������.
#include <math.h>
#define Pi 3.141592
using namespace std;

 //������ 
double Earth = 0;
double Mars = 0;
double Moon = 0;
//��ü����
double AngleX = 0;
double AngleY = 0;

int Width = 800, Height = 800; //ũ�� ����


void SpecialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		AngleX = AngleX + 1;
	}

	if (key == GLUT_KEY_DOWN)
	{
		AngleX = AngleX - 1;
	}

	if (key == GLUT_KEY_RIGHT)
	{
		AngleY = AngleY + 1;
	}
		if (key == GLUT_KEY_LEFT)
		{
			AngleY = AngleY - 1;
		}
			
}

void Timer(int id)
{
	Earth = Earth + 0.5;
	Mars = Mars + 0.2;
	Moon = Moon + 0.7; //OPENGL�Ź����� ���� �ٽ� .
	
	// Do something

	glutPostRedisplay();
	glutTimerFunc(10, Timer, 0); // set next timer
}

void glutSolidSphere(int radius, int slices, int stacks)
{
	;
}


void SetUpViewTransform()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0); // 0���� �����ÿ��� �ٷ� �� �տ� �����Ƿ� ������ ���� -10���� ����������� (?)
	glRotatef(AngleX, 1.0, 0.0, 0.0);
	glRotatef(AngleY, 0.0, 1.0, 0.0);
}

void SetupViewVolume()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -100, 100);
}

void Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //��� 
	

	//glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glLoadIdentity();


	SetUpViewTransform();
	SetupViewVolume();
	glMatrixMode(GL_MODELVIEW);
	//ȸ����
	double q0 = 0.0;
	double x0 = 5 * cos(q0);
	double y0 = 5 * sin(q0);

	//LINE�� �ƴ� LINES
	glColor3f(0.7f, 0.7f, 0.7f);
	for (q0 = 0.0; q0 < 360; q0 = q0 + 18)
	{
		double x0 = 7 * cos(q0);
		double y0 = 7 * sin(q0);
		glBegin(GL_LINES);
		glVertex3f(x0, y0, 0);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();
	}
	glEnd();
	//ȸ���� ��
	//�¾����
	glPushMatrix();

	glTranslatef(0, 0, 0); 
	
	glColor3f(1.0f, 0, 0);

	glutSolidSphere(1.5f, 40, 40);

	
	//�¾� ��
	
	//����
	glPushMatrix();
	glColor3f(0, 0, 1.0f);
	glRotatef(Earth, 0.0, 0.0, 1.0); //��������
	glTranslatef(5.0f, 0, 0);
	

	glutSolidSphere(0.5f, 20, 20);

	//���� ��

	//�� ����
	glPushMatrix();

	glRotatef(Moon, 0.0, 0.0, 1.0);
	glTranslatef(1.0f, 0, 0);
	glColor3f(0, 1.0f, 0);
	glutSolidSphere(0.2f, 20, 20);
	
	glPopMatrix();
	glPopMatrix();
	// ��

	// ȭ�� ����
	glPushMatrix();
	glRotatef(Mars, 0.0, 0.0, 1.0);
	glTranslatef(7.0f, 0, 0);

	glColor3f(1.0f,0.0,1.0f);

	glutSolidSphere(0.3f, 20, 20);

	glPopMatrix();
	//ȭ�� ��

	//ȭ�� ���� �˵� 
	double q2 = 0.0;
	double x2 = 7 * cos(q2);
	double y2 = 7 * sin(q2);


	//���� ���� �˵� �׸��� ��


	glBegin(GL_LINES); //LINE�� �ƴ� LINES
	glColor3f(1.0f, 0, 1.0f);
	for (q2 = 0.0; q2 < 360; q2 = q2 + 0.05)
	{
		double x2 = 7 * cos(q2);
		double y2 = 7 * sin(q2);

		glVertex3f(x2, y2, 0);
	}
	glEnd();
	//ȭ�� ���� �˵� ��
	
	//���� ���� �˵�

	double q1 = 0.0;
	double x1 = 5 * cos(q1);
	double y1 = 5 * sin(q1);

	glBegin(GL_LINES); //LINE�� �ƴ� LINES
	glColor3f(0.0f, 0, 1.0f);
	for (q1 = 0.0; q1 < 360; q1 = q1 + 0.05)
	{
		double x1 = 5 * cos(q1);
		double y1 = 5 * sin(q1);

		glVertex3f(x1, y1, 0);
	}
	glEnd();
	//���� ���� �˵� �׸��� ��
	
	
	// darw
	
	
	glutSwapBuffers();

}


int main(int argc, char **argv)
{
	
	
	
	glutInit(&argc, argv);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutCreateWindow("����");

	glutDisplayFunc(Render);

	glutTimerFunc(1000, Timer, 0);
	glutSpecialFunc(SpecialKeyboard);



	glutMainLoop();
	
	return 0;
}
