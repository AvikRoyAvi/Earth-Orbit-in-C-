#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-400.0, 400.0, -400.0, 4000, -400.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

float putaransatu, putarandua = 0;
typedef struct {
    float x, y;
}

point2D_t;

void drawDot(int x, int y) {
    glBegin(GL_POINT);
    glVertex2i(x, y);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    putaransatu += 0.2;
    putarandua += 2;

    glPushMatrix();

    glColor3ub(255, 255, 0);
    glRotated(putaransatu, 0, 0, 1);
    glutWireSphere(65.0, 30000, 3);

    glTranslatef(-55, -55, 0);

    glTranslatef(-45, -45, 0);

    glTranslatef(-80, -80, 0);

    glColor3f(0.2, 0.2, 07);
    glutWireSphere(45.0, 2500, 3);

    glColor3f(0, 0, 1);
    glBegin(GL_LINE_STRIP);

    for(float x = 0; x <= 6.28; x += 0.001) {
        glVertex2f(cos(x) * 60, sin(x) * 6);
    }
    glEnd();

    glColor3f(1, 1, 1);
    glRotated(putarandua, 0, 0, 1);
    glTranslatef(40, 40, 0);
    glutWireSphere(10.0, 100, 4);

    glPopMatrix();

    glPushMatrix();

    glColor3f(0, 1, 1);
    glBegin(GL_LINE_STRIP);

    for(float x = 0; x <= 6.28; x += 0.001) {
        glVertex2f(cos(x) * 250, sin(x) * 250);
    }
    glEnd();

    glPopMatrix();
    glFlush();
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 1920);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Planet");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
