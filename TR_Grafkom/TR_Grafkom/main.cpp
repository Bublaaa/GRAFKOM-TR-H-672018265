#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include <vector>
#include <GL/freeglut.h>
#include <math.h>
#include<GLFW/glfw3.h>
#include<glm.hpp>
#include"objloader.h"

void init(void);
void display(void);
void ukuran(int, int);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void arrow_key(int, int, int);
int is_depth;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TR Grafkom");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_key);
	glutMouseFunc(mouse);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	is_depth = 1;
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
}
void ukuran(int lebar, int tinggi) {
	if (tinggi == 0) tinggi = 1;
	glLoadIdentity();
	gluPerspective(100.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -35.0, -150.0);

}
void display(void) {
	if (is_depth) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'w':
	case 'W':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case 'a':
	case 'A':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case 'd':
	case 'D':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 'q':
	case 'Q':
		glScalef(1.2, 1.2, 1.2);
		break;
	case 'e':
	case 'E':
		glScalef(0.8, 0.8, 0.8);
		break;
	case 'z':
	case 'Z':
		glRotatef(1.0, 0.0, 0.0, 2.0);
		break;
	case 'x':
	case 'X':
		glRotatef(1.0, 0.0, 0.0, -2.0);
		break;
	}

	display();
}
void arrow_key(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		glTranslatef(-2.0, 0.0, 0.0);
		break;
	case GLUT_KEY_RIGHT:
		glTranslatef(2.0, 0.0, 0.0);
		break;
	case GLUT_KEY_UP:
		glTranslatef(0.0, 2.0, 0.0);
		break;
	case GLUT_KEY_DOWN:
		glTranslatef(0.0, -2.0, 0.0);
		break;
	}
	display();
}
void mouse(int button, int a, int x, int y)
{
	switch (button)
	{
		if (a == GLUT_DOWN || a == GLUT_UP)
		{
	case GLUT_LEFT_BUTTON:
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case GLUT_RIGHT_BUTTON:
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 3:
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 4:
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
		}
	}
	display();
}