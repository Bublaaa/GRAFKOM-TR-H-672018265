#include <stdlib.h>
#include <GL/freeglut.h>
#include <iostream>
#include "nfgloader.h"

float rotasi = 0.0, zoom = 1.0, x_pos = 0.0, y_pos = -1.0, z_pos = 0.0;
bool pause = false;
//int is_depth;
float angle = 0.0f, rx=0.0f;
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    //is_depth = 1;
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
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
    glRotatef(0, 1.0, 0.0, 0.0);//vertikal
    glRotatef(rotasi, 0.0, 1.0, 0.0);//horizontal
}
void woman(void) {
    float x1, x2, x3, y1, y2, y3, z1, z2, z3;
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

        glBegin(GL_LINE_LOOP);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);
        glEnd();
    }
}
    
    void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //kamera();
	glPushMatrix();
	glTranslatef(0,-0.9,0);
	glRotatef(angle,rx,angle, 0);
	woman();
	glPopMatrix();
    glutSwapBuffers();
	glutPostRedisplay();
}

void ukuran(int lebar, int tinggi) {
    glLoadIdentity();
    glViewport(0, 0, lebar, tinggi);
    //gluPerspective(100.0, lebar / tinggi, 80.0, 500.0);
    //glTranslatef(0.0, -35.0, -250.0);
}
//void timer(int) {
//    glutPostRedisplay();
//    glutTimerFunc(1000 / 20, timer, 0);
//    if (pause == false) {
//        rotasi -= 4;
 //   }
  //  else if (pause == true) {
 //       rotasi = rotasi;
 //   }
//}
void timer(int){
glutPostRedisplay();
glutTimerFunc(1000 / 20, timer, 0);
angle +=5.0f;
}

void dumpInfo(void)
{
   printf ("Vendor: %s\n", glGetString (GL_VENDOR));
   printf ("Renderer: %s\n", glGetString (GL_RENDERER));
   printf ("Version: %s\n", glGetString (GL_VERSION));
}

void myKeyboard(unsigned char key, int x, int y){  //dihapus kalau tak digunakan
if(key=='x'){
rx +=30;
}
else if(key=='w'){
rx -=30;
}
else if(key=='s'){
rx =0;
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
    else
    display();
}
//void arrow_key(int key, int x, int y) {
//    switch (key) {
//    case GLUT_KEY_LEFT:
//        x_pos -= 0.1;
//        break;
//    case GLUT_KEY_RIGHT:
//        x_pos += 0.1;
//        break;
//    case GLUT_KEY_UP:
//        y_pos += 0.1;
//        break;
//    case GLUT_KEY_DOWN:
//        y_pos -= 0.1;
//        break;
//    }
//    display();
//}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("TR_Grafkom");

    load("Woman1.nfg");
    glutDisplayFunc(display);
    glutReshapeFunc(ukuran);
    glutKeyboardFunc(myKeyboard);
   // glutSpecialFunc(arrow_key);
    glutTimerFunc(0, timer, 0);
    glutSwapBuffers();
    dumpInfo();
    init();
    glutMainLoop();
}
