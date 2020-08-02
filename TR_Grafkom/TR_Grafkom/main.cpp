#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include <math.h>

void display();
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void init();
void lighting();
void arrow_key(int, int , int );

int is_depth;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TR_GRAFKOM");
    init();
    lighting();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutSpecialFunc(arrow_key);
    glutIdleFunc(display);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20);
    glLineWidth(4);
    is_depth = 1;
    glLoadIdentity();
    gluLookAt(0.0f, 40.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

}
void lighting(void)
{
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat mat_specular[] = { 0.0, 1.0, 0.0, 0.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 0.0, 1.0, 0.0 };

    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
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
void display() {

    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();

    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
    glTranslatef(-0.003, 0.0, 0.0);
}
void ukuran(int lebar, int tinggi) {
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55.0, lebar / tinggi, 50.0, 2500.0);
    glTranslatef(-5.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}