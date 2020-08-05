#include <stdlib.h>
#include <GL/freeglut.h>
#include <iostream>
#include "nfgloader.h"
#include "tgaloader.h"

float x_rot = 0.0, y_rot = 0.0, z_rot = 0.0,
zoom = 1.0,
x_pos = 0.0, y_pos = -1.0, z_pos = 0.0;
bool pause = false;
//int is_depth;
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    //is_depth = 1;
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    GLfloat diffuse[] = { 2.0, 2.0, 2.0, 2.0 };
    GLfloat shininess[] = { 50.0 };
    GLfloat position[] = { 1.0, -1.0, -1.0, 0.0 };
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    return;
}
void kamera() {
    glLoadIdentity();
    glPushMatrix();

    //zoom kamera
    glScalef(zoom, zoom, zoom);

    //posisi kamera
    glTranslatef(x_pos, y_pos, z_pos);

    //rotate kamera
    glRotatef(y_rot, 1.0, 0.0, 0.0);
    glRotatef(x_rot, 0.0, 1.0, 0.0);
    glRotatef(z_rot, 0.0, 0.0, 1.0);
}
void display(void) {
    float x1, x2, x3, y1, y2, y3, z1, z2, z3, u1, u2, u3, v1, v2, v3;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    kamera();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 718; i++)
    {   //titik pertama
        x1 = vertex[index[i].dex1].x;
        x2 = vertex[index[i].dex2].x;
        x3 = vertex[index[i].dex3].x;
        //titik kedua
        y1 = vertex[index[i].dex1].y;
        y2 = vertex[index[i].dex2].y;
        y3 = vertex[index[i].dex3].y;
        //titik ketiga
        z1 = vertex[index[i].dex1].z;
        z2 = vertex[index[i].dex2].z;
        z3 = vertex[index[i].dex3].z;
        //titik u
        u1 = vertex[index[i].dex1].u;
        u2 = vertex[index[i].dex2].u;
        u3 = vertex[index[i].dex3].u;
        //titik u
        v1 = vertex[index[i].dex1].v;
        v2 = vertex[index[i].dex2].v;
        v3 = vertex[index[i].dex3].v;

        glBegin(GL_POLYGON);
        glTexCoord2f(u1, v1);
        glVertex3f(x1, y1, z1);
        glTexCoord2f(u2, v2);
        glVertex3f(x2, y2, z2);
        glTexCoord2f(u3, v3);
        glVertex3f(x3, y3, z3);
        glEnd();
    }
   
    glutSwapBuffers();
}
void ukuran(int lebar, int tinggi) {
    glLoadIdentity();
    glViewport(0, 0, lebar, tinggi);
    //gluPerspective(100.0, lebar / tinggi, 80.0, 500.0);
    //glTranslatef(0.0, -35.0, -250.0);
}
void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 20, timer, 0);
    if (pause == false) {
        x_rot -= 4;
    }
    else if (pause == true) {
        x_rot = x_rot;
    }
}
void keyboard(unsigned char key, int x, int y) {
    if (key == ' ' && pause == false) {
        pause = true;
    }
    else if (key == ' ' && pause == true) {
        pause = false;
    }
    else if (key == 'z') {
        zoom += 0.1;
    }
    else if (key == 'x') {
        zoom -= 0.1;
    }
    else if (pause == true) {
        //sumbu y
        if (key == 'w') {
            y_rot += 3;
        }
        else if (key == 's') {
            y_rot -= 3;
        }
        //sumbu x
        else if (key == 'a') {
            x_rot += 3;
        }
        else if (key == 'd') {
            x_rot -= 3;
        }
        //sumbu z
        else if (key == 'q') {
            z_rot += 3;
        }
        else if (key == 'e') {
            z_rot -= 3;
        }
        else {}
    }
    else
        display();
}
void arrow_key(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        x_pos -= 0.1;
        break;
    case GLUT_KEY_RIGHT:
        x_pos += 0.1;
        break;
    case GLUT_KEY_UP:
        y_pos += 0.1;
        break;
    case GLUT_KEY_DOWN:
        y_pos -= 0.1;
        break;
    }
    display();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("TR_Grafkom");

    load("Woman1.nfg");
    loadtga("Woman1.tga");
    glutDisplayFunc(display);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow_key);
    glutTimerFunc(0, timer, 0);
    glutSwapBuffers();
    init();
    glutMainLoop();
}
