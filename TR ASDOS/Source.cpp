#include <iostream>
#include <GL/freeglut.h>

void mall() {

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("ini mall");
	glutDisplayFunc(mall);

	glutMainLoop();

	return 0;
}