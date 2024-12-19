#include<GL/glut.h>
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.5f,0.5f,0.5f);
 glBegin(GL_POLYGON);
 glVertex2i(40,40);
 glVertex2i(320,40);
 glVertex2i(40,40);
 glVertex2i(40,200);
 glVertex2i(40,200);
 glVertex2i(320,200);
 glVertex2i(320,200);
 glVertex2i(320,40);
 glEnd();
 glFlush();
}
void myinit()
{
 glClearColor(0.0,0.0,0.0,1.0);
 glColor3f(1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,400.0,0.0,400.0);
}
int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(100,100);
 glutCreateWindow("OPENGL PATTERN ");
 glutDisplayFunc(display);
 myinit();
 glutMainLoop();
 return 0;
}
