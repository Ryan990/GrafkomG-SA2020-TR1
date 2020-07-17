#include <stdlib.h>
#include <GL/glut.h>
static float ypoz = 0, zpoz = 0, xpoz = 0, a = 0, b = 0, c = -10;
void mall(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int
	z1, float z2, float z3) {
	glColor3f(0, 0, 0); //sisi depan
	glVertex3d(x1, y1, z2);
	glVertex3d(x2, y2, z2);
	glVertex3d(x3, y3, z2);
	glVertex3d(x4, y4, z2);
	glColor3f(0, 0, 0);//right
	glVertex3d(x2, y2, z2);
	glVertex3d(x2, y2, z1);
	glVertex3d(x3, y3, z1);
	glVertex3d(x3, y3, z2);
	glColor3f(0, 0, 0);//back
	glVertex3d(x1, y1, z1);
	glVertex3d(x2, y2, z1);
	glVertex3d(x3, y3, z1);
	glVertex3d(x4, y4, z1);
	glColor3f(0, 0, 0);//left
	glVertex3d(x1, y1, z2);
	glVertex3d(x1, y1, z1);
	glVertex3d(x4, y4, z1);
	glVertex3d(x4, y4, z2);
	glColor3f(0, 0, 0);//bottom
	glVertex3d(x1, y1, z2);
	glVertex3d(x2, y2, z2);
	glVertex3d(x2, y2, z1);
	glVertex3d(x1, y1, z1);
	glColor3f(0, 0, 0);//top
	glVertex3d(x3, y3, z2);
	glVertex3d(x4, y4, z2);
	glVertex3d(x4, y4, z1);
	glVertex3d(x3, y3, z1);
	glEnd();
}



void init(void)
{
	glClearColor(1, 1, 1, 1);
	glOrtho(-12, 12, -6, 6, -35, 35);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, 2.2, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(a, b, c); 
	glRotatef(xpoz, 1, 0, 0);
	glRotatef(ypoz, 0, 1, 0);
	glRotatef(zpoz, 0, 0, 1);
	glBegin(GL_QUADS);
	mall(-8, -2, 8, -2, 8, 2, -8, 2, -5, 3, 0);
	glutSwapBuffers(); 
	
		
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {

	case 'x':
		xpoz = xpoz + 5;
		if (xpoz > 360) xpoz = 0;
		glutPostRedisplay();
		break;
	case 'y':
		ypoz = ypoz + 5;
		if (ypoz > 360) ypoz = 0;
		glutPostRedisplay();
		break;
	case 'z':
		zpoz = zpoz + 1;
		if (zpoz > 360) zpoz = 0;

		glutPostRedisplay();
		break;
	case 'w':
		b = b + 1;
		glutPostRedisplay();
		break;
	case 's':
		b = b - 1;
		glutPostRedisplay();
		break;
	case 'a':
		a = a + 1;
		glutPostRedisplay();
		break;
	case 'd':
		a = a - 1;
		glutPostRedisplay();
		break;
	case 'q':
		c = c + 1;
		glutPostRedisplay();
		break;
	case 'e':
		c = c - 1;
		glutPostRedisplay();
		break;

	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TSM Bandung");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}