#include <windows.h>
#include <GL/glut.h>

void init(void);
void sun(void);
void garbage(void);
void tree(void);
void cloud(void);
void terrace(void);
void prism(void);
void wall(void);
void base(void);
void display(void);
void awan(void);
void pohon(void);
void ranting(void);
void tanah(void);
void keyboard(unsigned char, int, int);
void mouse(int, int, int, int);
void motion(int, int);
void shape(int, int);
void Timer(int);

int specularLightstatus = 1;
bool ambientLightStatus = true; 
int y1 = 0;
int y2 = y1 + 50;
int y3 = y2 + 10;
int y4 = 20;
int y5 = y4 + 2;
int y6 = y3 + 5;
int cx, cy;

float zoom = 1.0f;
float direction = 0.0f;

int xx = 0, yy = 0, zz = 0, sudut = 0;
float x_pos = 0.0f;
float deltax = 0.05f;

bool mouseDown = false;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

int is_depth;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("TSM-Bandung");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(30, Timer, 1);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutReshapeFunc(shape);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glutMainLoop();
	return 0;
}

void init(void) {
	GLfloat LightPosition[] = { 10.0f, 10.0f, 20.0f, 0.0f };
	GLfloat LightAmbient[] = { 0.0f, 1.0f, 0.0f, 1.0f };
	GLfloat LightDiffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat LightSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat Shine[] = { 80 };
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Shine);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(255, 255, 255, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(1.0f);
	glLineWidth(3.0f);
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		mouseDown = true;

		xdiff = x - xrot;
		ydiff = y - yrot;
	}
	else
		mouseDown = false;

}

void motion(int x, int y) {
	if (mouseDown) {
		yrot = x - xdiff;
		xrot = y - ydiff;

		glutPostRedisplay();
	}
}

void terrace() {
	//cover
	glColor3ub(0, 0, 0);

	glBegin(GL_LINE_LOOP);
	glVertex3d(88.75, y4, 36.52);
	glVertex3d(86.46, y4, 42.47);
	glVertex3d(55.02, y4, 32.16);
	glVertex3d(55.02, y4, 25.47);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(88.75, y5, 36.52);
	glVertex3d(86.46, y5, 42.47);
	glVertex3d(55.02, y5, 32.16);
	glVertex3d(55.02, y5, 25.47);
	glEnd();

	glBegin(GL_LINES);
	glVertex3d(55.02, y4, 32.16);
	glVertex3d(55.02, y5, 32.16);
	glEnd();

	glBegin(GL_LINES);
	glVertex3d(86.46, y5, 42.47);
	glVertex3d(86.46, y4, 42.47);
	glEnd();

	//pillar
	//01
	glBegin(GL_LINE_LOOP);
	glVertex3d(83.49, y1, 40.01);
	glVertex3d(83.49, y4, 40.01);
	glVertex3d(82.99, y4, 41.33);
	glVertex3d(82.99, y1, 41.33);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(82.99, y1, 41.33);
	glVertex3d(82.99, y4, 41.33);
	glVertex3d(83.98, y4, 41.65);
	glVertex3d(83.98, y1, 41.65);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(83.98, y1, 41.65);
	glVertex3d(83.98, y4, 41.65);
	glVertex3d(84.43, y4, 40.32);
	glVertex3d(84.43, y1, 40.32);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(83.49, y1, 40.01);
	glVertex3d(83.49, y4, 40.01);
	glVertex3d(84.43, y4, 40.32);
	glVertex3d(84.43, y1, 40.32);
	glEnd();

	//02
	glBegin(GL_LINE_LOOP);
	glVertex3d(74.76, y1, 37.15);
	glVertex3d(74.76, y4, 37.15);
	glVertex3d(74.26, y4, 38.47);
	glVertex3d(74.26, y1, 38.47);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(74.26, y1, 38.47);
	glVertex3d(74.26, y4, 38.47);
	glVertex3d(75.26, y4, 38.80);
	glVertex3d(75.26, y1, 38.80);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(75.26, y1, 38.80);
	glVertex3d(75.26, y4, 38.80);
	glVertex3d(75.76, y4, 37.48);
	glVertex3d(75.76, y1, 37.48);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(74.76, y1, 37.15);
	glVertex3d(74.76, y4, 37.15);
	glVertex3d(75.76, y4, 37.48);
	glVertex3d(75.76, y1, 37.48);
	glEnd();

	//03
	glBegin(GL_LINE_LOOP);
	glVertex3d(65.42, y1, 34.09);
	glVertex3d(65.42, y4, 34.09);
	glVertex3d(64.91, y4, 35.41);
	glVertex3d(64.91, y1, 35.41);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(64.91, y1, 35.41);
	glVertex3d(64.91, y4, 35.41);
	glVertex3d(65.91, y4, 35.73);
	glVertex3d(65.91, y1, 35.73);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(65.91, y1, 35.73);
	glVertex3d(65.91, y4, 35.73);
	glVertex3d(66.42, y4, 34.42);
	glVertex3d(66.42, y1, 34.42);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(65.42, y1, 34.09);
	glVertex3d(65.42, y4, 34.09);
	glVertex3d(66.42, y4, 34.42);
	glVertex3d(66.42, y1, 34.42);
	glEnd();

	//04
	glBegin(GL_LINE_LOOP);
	glVertex3d(56.73, y1, 31.24);
	glVertex3d(56.73, y4, 31.24);
	glVertex3d(56.22, y4, 32.56);
	glVertex3d(56.22, y1, 32.56);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(56.22, y1, 32.56);
	glVertex3d(56.22, y4, 32.56);
	glVertex3d(57.22, y4, 32.89);
	glVertex3d(57.22, y1, 32.89);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(57.22, y1, 32.89);
	glVertex3d(57.22, y4, 32.89);
	glVertex3d(57.73, y4, 31.57);
	glVertex3d(57.73, y1, 31.57);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(56.73, y1, 31.24);
	glVertex3d(56.73, y4, 31.24);
	glVertex3d(57.73, y4, 31.57);
	glVertex3d(57.73, y1, 31.57);
	glEnd();

	//cover
	glColor3ub(105, 105, 105);

	glBegin(GL_POLYGON);
	glVertex3d(88.75, y4, 36.52);
	glVertex3d(86.46, y4, 42.47);
	glVertex3d(55.02, y4, 32.16);
	glVertex3d(55.02, y4, 25.47);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(88.75, y5, 36.52);
	glVertex3d(86.46, y5, 42.47);
	glVertex3d(55.02, y5, 32.16);
	glVertex3d(55.02, y5, 25.47);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(88.75, y4, 36.52);
	glVertex3d(88.75, y5, 36.52);
	glVertex3d(86.46, y5, 42.47);
	glVertex3d(86.46, y4, 42.47);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(86.46, y4, 42.47);
	glVertex3d(86.46, y5, 42.47);
	glVertex3d(55.02, y5, 32.16);
	glVertex3d(55.02, y4, 32.16);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(55.02, y4, 32.16);
	glVertex3d(55.02, y5, 32.16);
	glVertex3d(55.02, y5, 25.47);
	glVertex3d(55.02, y4, 25.47);
	glEnd();

	//pillar
	//01
	glBegin(GL_POLYGON);
	glVertex3d(83.49, y1, 40.01);
	glVertex3d(83.49, y4, 40.01);
	glVertex3d(82.99, y4, 41.33);
	glVertex3d(82.99, y1, 41.33);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(82.99, y1, 41.33);
	glVertex3d(82.99, y4, 41.33);
	glVertex3d(83.98, y4, 41.65);
	glVertex3d(83.98, y1, 41.65);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(83.98, y1, 41.65);
	glVertex3d(83.98, y4, 41.65);
	glVertex3d(84.43, y4, 40.32);
	glVertex3d(84.43, y1, 40.32);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(83.49, y1, 40.01);
	glVertex3d(83.49, y4, 40.01);
	glVertex3d(84.43, y4, 40.32);
	glVertex3d(84.43, y1, 40.32);
	glEnd();

	//02
	glBegin(GL_POLYGON);
	glVertex3d(74.76, y1, 37.15);
	glVertex3d(74.76, y4, 37.15);
	glVertex3d(74.26, y4, 38.47);
	glVertex3d(74.26, y1, 38.47);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(74.26, y1, 38.47);
	glVertex3d(74.26, y4, 38.47);
	glVertex3d(75.26, y4, 38.80);
	glVertex3d(75.26, y1, 38.80);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(75.26, y1, 38.80);
	glVertex3d(75.26, y4, 38.80);
	glVertex3d(75.76, y4, 37.48);
	glVertex3d(75.76, y1, 37.48);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(74.76, y1, 37.15);
	glVertex3d(74.76, y4, 37.15);
	glVertex3d(75.76, y4, 37.48);
	glVertex3d(75.76, y1, 37.48);
	glEnd();

	//03
	glBegin(GL_POLYGON);
	glVertex3d(65.42, y1, 34.09);
	glVertex3d(65.42, y4, 34.09);
	glVertex3d(64.91, y4, 35.41);
	glVertex3d(64.91, y1, 35.41);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(64.91, y1, 35.41);
	glVertex3d(64.91, y4, 35.41);
	glVertex3d(65.91, y4, 35.73);
	glVertex3d(65.91, y1, 35.73);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(65.91, y1, 35.73);
	glVertex3d(65.91, y4, 35.73);
	glVertex3d(66.42, y4, 34.42);
	glVertex3d(66.42, y1, 34.42);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(65.42, y1, 34.09);
	glVertex3d(65.42, y4, 34.09);
	glVertex3d(66.42, y4, 34.42);
	glVertex3d(66.42, y1, 34.42);
	glEnd();

	//04
	glBegin(GL_POLYGON);
	glVertex3d(56.73, y1, 31.24);
	glVertex3d(56.73, y4, 31.24);
	glVertex3d(56.22, y4, 32.56);
	glVertex3d(56.22, y1, 32.56);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(56.22, y1, 32.56);
	glVertex3d(56.22, y4, 32.56);
	glVertex3d(57.22, y4, 32.89);
	glVertex3d(57.22, y1, 32.89);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(57.22, y1, 32.89);
	glVertex3d(57.22, y4, 32.89);
	glVertex3d(57.73, y4, 31.57);
	glVertex3d(57.73, y1, 31.57);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(56.73, y1, 31.24);
	glVertex3d(56.73, y4, 31.24);
	glVertex3d(57.73, y4, 31.57);
	glVertex3d(57.73, y1, 31.57);
	glEnd();
}

void prism() {
	glColor3ub(220, 220, 220);
	glBegin(GL_TRIANGLES);
	glVertex3d(51.76, y2, 11.58);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(40.64, y2, 11.58);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3d(40.64, y2, 11.58);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(40.64, y2, 0.47);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3d(40.64, y2, 0.47);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(51.76, y2, 0.47);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3d(51.76, y2, 0.47);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(51.76, y2, 11.58);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3d(51.76, y2, 11.58);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(40.64, y2, 11.58);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(40.64, y2, 11.58);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(40.64, y2, 0.47);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(40.64, y2, 0.47);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(51.76, y2, 0.47);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(51.76, y2, 0.47);
	glVertex3d(46.20, y6, 5.43);
	glVertex3d(51.76, y2, 11.58);
	glEnd();
}

void wall() {
	glColor3ub(245, 222, 179);
	//left
	glBegin(GL_POLYGON);
	glVertex3d(-77.95, y2, 20.24);
	glVertex3d(-77.95, y1, 20.24);
	glVertex3d(-77.95, y1, -38.25);
	glVertex3d(-77.95, y2, -38.25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-77.95, y1, 20.24);
	glVertex3d(-77.95, y2, 20.24);
	glVertex3d(-60.64, y2, 36.13);
	glVertex3d(-60.64, y1, 36.13);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-60.64, y2, 36.13);
	glVertex3d(-60.64, y1, 36.13);
	glVertex3d(3.41, y1, 36.13);
	glVertex3d(3.41, y2, 36.13);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(3.41, y2, 36.13);
	glVertex3d(3.41, y1, 36.13);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(3.41, y2, 25.47);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(3.34, y2, -2.91);
	glVertex3d(3.34, y1, -2.91);
	glVertex3d(3.29, y1, -38.25);
	glVertex3d(3.29, y2, -38.25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(3.29, y2, -38.25);
	glVertex3d(3.29, y1, -38.25);
	glVertex3d(-77.95, y1, -38.25);
	glVertex3d(-77.95, y2, -38.25);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3d(-77.95, y2, 20.24);
	glVertex3d(-77.95, y1, 20.24);
	glVertex3d(-77.95, y1, -38.25);
	glVertex3d(-77.95, y2, -38.25);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(-77.95, y1, 20.24);
	glVertex3d(-77.95, y2, 20.24);
	glVertex3d(-60.64, y2, 36.13);
	glVertex3d(-60.64, y1, 36.13);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(-60.64, y2, 36.13);
	glVertex3d(-60.64, y1, 36.13);
	glVertex3d(3.41, y1, 36.13);
	glVertex3d(3.41, y2, 36.13);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(3.41, y2, 36.13);
	glVertex3d(3.41, y1, 36.13);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(3.41, y2, 25.47);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(3.34, y2, -2.91);
	glVertex3d(3.34, y1, -2.91);
	glVertex3d(3.29, y1, -38.25);
	glVertex3d(3.29, y2, -38.25);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(3.29, y2, -38.25);
	glVertex3d(3.29, y1, -38.25);
	glVertex3d(-77.95, y1, -38.25);
	glVertex3d(-77.95, y2, -38.25);
	glEnd();

	glColor3ub(222, 184, 135);
	//center
	glBegin(GL_POLYGON);
	glVertex3d(3.41, y2, 25.47);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(44.70, y1, 25.47);
	glVertex3d(44.70, y2, 25.47);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(44.70, y2, 25.47);
	glVertex3d(44.70, y1, 25.47);
	glVertex3d(44.70, y1, 16.61);
	glVertex3d(44.70, y2, 16.61);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(44.70, y2, 16.61);
	glVertex3d(44.70, y1, 16.61);
	glVertex3d(55.02, y1, 16.61);
	glVertex3d(55.02, y2, 16.61);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(55.02, y2, -4.20);
	glVertex3d(55.02, y1, -4.20);
	glVertex3d(44.96, y1, -4.20);
	glVertex3d(44.96, y2, -4.20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(44.96, y2, -4.20);
	glVertex3d(44.96, y1, -4.20);
	glVertex3d(44.96, y1, -5.78);
	glVertex3d(44.96, y2, -5.78);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(44.96, y2, -5.78);
	glVertex3d(44.96, y1, -5.78);
	glVertex3d(40.80, y1, -5.78);
	glVertex3d(40.80, y2, -5.78);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(40.80, y2, -5.78);
	glVertex3d(40.80, y1, -5.78);
	glVertex3d(40.80, y1, -8.66);
	glVertex3d(40.80, y2, -8.66);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(40.80, y2, -8.66);
	glVertex3d(40.80, y1, -8.66);
	glVertex3d(17.48, y1, -8.66);
	glVertex3d(17.48, y2, -8.66);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(17.48, y2, -8.66);
	glVertex3d(17.48, y1, -8.66);
	glVertex3d(17.48, y1, -2.91);
	glVertex3d(17.48, y2, -2.91);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(17.48, y2, -2.91);
	glVertex3d(17.48, y1, -2.91);
	glVertex3d(3.34, y1, -2.91);
	glVertex3d(3.34, y2, -2.91);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3d(3.41, y2, 25.47);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(44.70, y1, 25.47);
	glVertex3d(44.70, y2, 25.47);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(44.70, y2, 25.47);
	glVertex3d(44.70, y1, 25.47);
	glVertex3d(44.70, y1, 16.61);
	glVertex3d(44.70, y2, 16.61);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(44.70, y2, 16.61);
	glVertex3d(44.70, y1, 16.61);
	glVertex3d(55.02, y1, 16.61);
	glVertex3d(55.02, y2, 16.61);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(55.02, y2, -4.20);
	glVertex3d(55.02, y1, -4.20);
	glVertex3d(44.96, y1, -4.20);
	glVertex3d(44.96, y2, -4.20);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(44.96, y2, -4.20);
	glVertex3d(44.96, y1, -4.20);
	glVertex3d(44.96, y1, -5.78);
	glVertex3d(44.96, y2, -5.78);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(44.96, y2, -5.78);
	glVertex3d(44.96, y1, -5.78);
	glVertex3d(40.80, y1, -5.78);
	glVertex3d(40.80, y2, -5.78);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(40.80, y2, -5.78);
	glVertex3d(40.80, y1, -5.78);
	glVertex3d(40.80, y1, -8.66);
	glVertex3d(40.80, y2, -8.66);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(40.80, y2, -8.66);
	glVertex3d(40.80, y1, -8.66);
	glVertex3d(17.48, y1, -8.66);
	glVertex3d(17.48, y2, -8.66);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(17.48, y2, -8.66);
	glVertex3d(17.48, y1, -8.66);
	glVertex3d(17.48, y1, -2.91);
	glVertex3d(17.48, y2, -2.91);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(17.48, y2, -2.91);
	glVertex3d(17.48, y1, -2.91);
	glVertex3d(3.34, y1, -2.91);
	glVertex3d(3.34, y2, -2.91);
	glEnd();

	glColor3ub(65, 105, 225);
	//right
	glBegin(GL_POLYGON);
	glVertex3d(55.02, y3, 25.47);
	glVertex3d(55.02, y1, 25.47);
	glVertex3d(88.75, y1, 36.52);
	glVertex3d(88.75, y3, 36.52);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(88.75, y3, 36.52);
	glVertex3d(88.75, y1, 36.52);
	glVertex3d(99.41, y1, 8.77);
	glVertex3d(99.41, y3, 8.77);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(99.41, y3, 8.77);
	glVertex3d(99.41, y1, 8.77);
	glVertex3d(55.02, y1, -5.78);
	glVertex3d(55.02, y3, -5.78);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(55.02, y3, -5.78);
	glVertex3d(55.02, y1, -5.78);
	glVertex3d(55.02, y1, 25.47);
	glVertex3d(55.02, y3, 25.47);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex3d(55.02, y3, 25.47);
	glVertex3d(55.02, y1, 25.47);
	glVertex3d(88.75, y1, 36.52);
	glVertex3d(88.75, y3, 36.52);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(88.75, y3, 36.52);
	glVertex3d(88.75, y1, 36.52);
	glVertex3d(99.41, y1, 8.77);
	glVertex3d(99.41, y3, 8.77);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(99.41, y3, 8.77);
	glVertex3d(99.41, y1, 8.77);
	glVertex3d(55.02, y1, -5.78);
	glVertex3d(55.02, y3, -5.78);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3d(55.02, y3, -5.78);
	glVertex3d(55.02, y1, -5.78);
	glVertex3d(55.02, y1, 25.47);
	glVertex3d(55.02, y3, 25.47);
	glEnd();
}

void pohon() {
	//batang
	GLUquadricObj* pObj;
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);

	glPushMatrix();
	glColor3ub(104, 70, 14);
	glRotatef(270, 1, 0, 0);
	gluCylinder(pObj, 4, 0.7, 30, 25, 25);
	glPopMatrix();
}

void ranting() {
	GLUquadricObj* pObj;
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
	glPushMatrix();
	glColor3ub(104, 70, 14);
	glTranslatef(0, 27, 0);
	glRotatef(330, 1, 0, 0);
	gluCylinder(pObj, 0.6, 0.1, 15, 25, 25);
	glPopMatrix();

	//daun
	glPushMatrix();
	glColor3ub(18, 118, 13);
	glScaled(5, 5, 5);
	glTranslatef(0, 7, 3);
	glutSolidDodecahedron();
	glPopMatrix();
}

void awan() {
	glPushMatrix();
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glColor3ub(153, 223, 255);
	glutSolidSphere(10, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(10, 0, 1);
	glutSolidSphere(5, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2, 6, -2);
	glutSolidSphere(7, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10, -3, 0);
	glutSolidSphere(7, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(6, -2, 2);
	glutSolidSphere(7, 50, 50);
	glPopMatrix();
}

void base() {
	glColor3ub(255, 250, 240);

	glBegin(GL_POLYGON);
	glVertex3d(-77.95, y1, 20.24);
	glVertex3d(-60.64, y1, 36.13);
	glVertex3d(3.41, y1, 36.13);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(3.34, y1, -2.91);
	glVertex3d(3.29, y1, -38.25);
	glVertex3d(-77.95, y1, -38.25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(17.48, y1, 25.47);
	glVertex3d(17.48, y1, -2.91);
	glVertex3d(3.34, y1, -2.91);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(17.48, y1, 25.47);
	glVertex3d(44.70, y1, 25.47);
	glVertex3d(44.70, y1, 16.61);
	glVertex3d(44.96, y1, -4.20);
	glVertex3d(44.96, y1, -5.78);
	glVertex3d(40.80, y1, -5.78);
	glVertex3d(40.80, y1, -8.66);
	glVertex3d(17.48, y1, -8.66);
	glVertex3d(17.48, y1, -2.91);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(44.70, y1, 16.61);
	glVertex3d(55.02, y1, 16.61);
	glVertex3d(55.02, y1, -4.20);
	glVertex3d(44.96, y1, -4.20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(55.02, y1, 25.47);
	glVertex3d(88.75, y1, 36.52);
	glVertex3d(99.41, y1, 8.77);
	glVertex3d(55.02, y1, -5.78);
	glEnd();

	glColor3ub(135, 206, 250);
	glBegin(GL_POLYGON);
	glVertex3d(-77.95, y2, 20.24);
	glVertex3d(-60.64, y2, 36.13);
	glVertex3d(3.41, y2, 36.13);
	glVertex3d(3.41, y2, 25.47);
	glVertex3d(3.34, y2, -2.91);
	glVertex3d(3.29, y2, -38.25);
	glVertex3d(-77.95, y2, -38.25);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(3.41, y2, 25.47);
	glVertex3d(17.48, y2, 25.47);
	glVertex3d(17.48, y2, -2.91);
	glVertex3d(3.34, y2, -2.91);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(17.48, y2, 25.47);
	glVertex3d(44.70, y2, 25.47);
	glVertex3d(44.70, y2, 16.61);
	glVertex3d(44.96, y2, -4.20);
	glVertex3d(44.96, y2, -5.78);
	glVertex3d(40.80, y2, -5.78);
	glVertex3d(40.80, y2, -8.66);
	glVertex3d(17.48, y2, -8.66);
	glVertex3d(17.48, y2, -2.91);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(44.70, y2, 16.61);
	glVertex3d(55.02, y2, 16.61);
	glVertex3d(55.02, y2, -4.20);
	glVertex3d(44.96, y2, -4.20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(55.02, y3, 25.47);
	glVertex3d(88.75, y3, 36.52);
	glVertex3d(99.41, y3, 8.77);
	glVertex3d(55.02, y3, -5.78);
	glEnd();
}

void sun() {
	glPushMatrix(); // matahari
	glEnable(GL_COLOR_MATERIAL);
	glTranslatef(-150 + x_pos, 160, 10);
	glRotatef(sudut, xx, yy, zz);
	glColor3f(1, 1, 0);
	glutSolidSphere(2, 20, 20);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
}

void garbage() {
	glBegin(GL_LINES); // garis hitam bak sampah
	glColor3d(0, 0, 0);
	glVertex3d(7.20, y1, 34.13);
	glVertex3d(7.20, y1 + 8, 34.13);
	glVertex3d(3.41, y1, 34.13);
	glVertex3d(3.41, y1 + 8, 34.13);
	glVertex3d(3.41, y1, 34.13);
	glVertex3d(7.20, y1, 34.13);
	glVertex3d(7.20, y1 + 8, 34.13);
	glVertex3d(3.41, y1 + 8, 34.13);
	glVertex3d(7.20, y1, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(7.20, y1, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(3.41, y1, 34.13);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(3.41, y1 + 8, 34.13);
	glVertex3d(7.20, y1, 34.13);
	glVertex3d(7.20, y1, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 34.13);
	glEnd();

	glBegin(GL_POLYGON); // badan bak sampah
	glColor3d(0, 0.5, 0);
	glVertex3d(3.41, y1, 34.13);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(7.20, y1, 25.47);
	glVertex3d(7.20, y1, 34.13);// bawah bak sampah

	glVertex3d(3.41, y1, 34.13);
	glVertex3d(3.41, y1, 25.47);
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(3.41, y1 + 8, 34.13); // tembok

	glVertex3d(3.41, y1, 34.13);
	glVertex3d(7.20, y1, 34.13);
	glVertex3d(7.20, y1 + 8, 34.13);
	glVertex3d(3.41, y1 + 8, 34.13);// depan bak sampah

	glVertex3d(7.20, y1, 34.13); // tembok
	glVertex3d(7.20, y1, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 34.13);

	glVertex3d(3.41, y1, 25.47); // belakang
	glVertex3d(7.20, y1, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(3.41, y1 + 8, 25.47);

	glVertex3d(3.41, y1 + 8, 34.13); // atas
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 34.13);
	glEnd();

	////// TUTUP BAK SAMPAH
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(3.41, y1 + 8, 34.13);
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 34.13);

	glVertex3d(3.41, y1 + 8, 34.13);
	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(3.41, y1 + 8.5, 25.47);
	glVertex3d(3.41, y1 + 8.5, 34.13);

	glVertex3d(3.41, y1 + 8, 34.13);
	glVertex3d(7.20, y1 + 8, 34.13);
	glVertex3d(7.20, y1 + 8.5, 34.13);
	glVertex3d(3.41, y1 + 8.5, 34.13);

	glVertex3d(7.20, y1 + 8, 34.13);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8.5, 25.47);
	glVertex3d(7.20, y1 + 8.5, 34.13);

	glVertex3d(3.41, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8, 25.47);
	glVertex3d(7.20, y1 + 8.5, 25.47);
	glVertex3d(3.41, y1 + 8.5, 25.47);

	glVertex3d(3.41, y1 + 8.5, 34.13);
	glVertex3d(3.41, y1 + 8.5, 25.47);
	glVertex3d(7.20, y1 + 8.5, 25.47);
	glVertex3d(7.20, y1 + 8.5, 34.13);
	glEnd();

	glBegin(GL_POLYGON); // Motif bak sampah
	glColor3d(0, 0.5, 0);
	glVertex3d(3.61, y1 + 8.5, 34.13); // atas
	glVertex3d(3.61, y1 + 8.5, 30.77);
	glVertex3d(7.00, y1 + 8.5, 30.77);
	glVertex3d(7.00, y1 + 8.5, 34.13);

	glVertex3d(3.61, y1 + 8.5, 34.13);
	glVertex3d(3.61, y1 + 8.5, 30.77);
	glVertex3d(3.61, y1 + 8.7, 30.77);
	glVertex3d(3.61, y1 + 8.7, 34.13);

	glVertex3d(3.61, y1 + 8.5, 34.13);
	glVertex3d(7.00, y1 + 8.5, 34.13);
	glVertex3d(7.00, y1 + 8.7, 34.13);
	glVertex3d(3.61, y1 + 8.7, 34.13);

	glVertex3d(7.00, y1 + 8.5, 34.13);
	glVertex3d(7.00, y1 + 8.5, 30.77);
	glVertex3d(7.00, y1 + 8.7, 30.77);
	glVertex3d(7.00, y1 + 8.7, 34.13);

	glVertex3d(3.61, y1 + 8.5, 30.77);
	glVertex3d(7.00, y1 + 8.5, 30.77);
	glVertex3d(7.00, y1 + 8.7, 30.77);
	glVertex3d(3.61, y1 + 8.7, 30.77);

	glVertex3d(3.61, y1 + 8.7, 34.13);
	glVertex3d(3.61, y1 + 8.7, 30.77);
	glVertex3d(7.00, y1 + 8.7, 30.77);
	glVertex3d(7.00, y1 + 8.7, 34.13);
	glEnd();

	glBegin(GL_POLYGON); // Motif bak sampah
	glColor3d(0, 0.5, 0);
	glVertex3d(3.61, y1 + 8.5, 28.77); // atas
	glVertex3d(3.61, y1 + 8.5, 26.00);
	glVertex3d(7.00, y1 + 8.5, 26.00);
	glVertex3d(7.00, y1 + 8.5, 28.77);

	glVertex3d(3.61, y1 + 8.5, 28.77);
	glVertex3d(3.61, y1 + 8.5, 26.00);
	glVertex3d(3.61, y1 + 8.7, 26.00);
	glVertex3d(3.61, y1 + 8.7, 28.77);

	glVertex3d(3.61, y1 + 8.5, 28.77);
	glVertex3d(7.00, y1 + 8.5, 28.77);
	glVertex3d(7.00, y1 + 8.7, 28.77);
	glVertex3d(3.61, y1 + 8.7, 28.77);

	glVertex3d(7.00, y1 + 8.5, 28.77);
	glVertex3d(7.00, y1 + 8.5, 26.00);
	glVertex3d(7.00, y1 + 8.7, 26.00);
	glVertex3d(7.00, y1 + 8.7, 28.77);

	glVertex3d(3.61, y1 + 8.5, 26.00);
	glVertex3d(7.00, y1 + 8.5, 26.00);
	glVertex3d(7.00, y1 + 8.7, 26.00);
	glVertex3d(3.61, y1 + 8.7, 26.00);

	glVertex3d(3.61, y1 + 8.7, 28.77);
	glVertex3d(3.61, y1 + 8.7, 26.00);
	glVertex3d(7.00, y1 + 8.7, 26.00);
	glVertex3d(7.00, y1 + 8.7, 28.77);
	glEnd();
}

void tree() {
	//pohon1
	glPushMatrix();
	glTranslatef(-50, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon2
	glPushMatrix();
	glTranslatef(-80, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon3
	glPushMatrix();
	glTranslatef(-20, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon4
	glPushMatrix();
	glTranslatef(10, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon5
	glPushMatrix();
	glTranslatef(40, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon6
	glPushMatrix();
	glTranslatef(70, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon7
	glPushMatrix();
	glTranslatef(100, 0, 50);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(90, 0, 1, 0);
	pohon();
	//ranting1
	ranting();
	//ranting2
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);
	glTranslatef(0, 25, 25);
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	//ranting3
	glPushMatrix();
	glScalef(1.8, 1.8, 1.8);
	glTranslatef(0, -6, 21.5);
	glRotatef(-55, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();
}

void cloud() {
	//awan
	glPushMatrix();
	glTranslatef(-130 + x_pos, 140, 35);
	glScalef(0.2, 0.2, 1.0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-105 + x_pos, 160, 30);
	glScalef(0.2, 0.2, 1.0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-150 + x_pos, 136, 25);
	glScalef(0.2, 0.2, 1.0);
	awan();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-160 + x_pos, 145, 45);
	glScalef(0.2, 0.2, 1.0);
	awan();
	glPopMatrix();
}

void tanah() {
	glBegin(GL_POLYGON); // Rumput hijau depan
	glColor3f(0, 1, 0);
	glVertex3d(-120, y1, 90);
	glVertex3d(-120, y1, 150);
	glVertex3d(140, y1, 150);
	glVertex3d(140, y1, 90);
	glEnd();

	glBegin(GL_POLYGON); // Rumput hijau belakang
	glColor3f(0, 1, 0);
	glVertex3d(-120, y1, 70);
	glVertex3d(-120, y1, -150);
	glVertex3d(140, y1, -150);
	glVertex3d(140, y1, 70);
	glEnd();

	glBegin(GL_POLYGON); // jalan raya 1
	glColor3f(0, 0, 0);
	glVertex3d(-120, y1, 72);
	glVertex3d(-120, y1, 79);
	glVertex3d(140, y1, 79);
	glVertex3d(140, y1, 72);
	glEnd();

	glBegin(GL_POLYGON); // jalan raya 2
	glColor3f(0, 0, 0);
	glVertex3d(-120, y1, 81);
	glVertex3d(-120, y1, 88);
	glVertex3d(140, y1, 88);
	glVertex3d(140, y1, 81);
	glEnd();

	glBegin(GL_POLYGON); // garis jalan raya
	glColor3f(0, 0, 0);
	glVertex3d(-115, y1, 79);
	glVertex3d(-115, y1, 81);
	glVertex3d(-110, y1, 81);
	glVertex3d(-110, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-105, y1, 79);
	glVertex3d(-105, y1, 81);
	glVertex3d(-100, y1, 81);
	glVertex3d(-100, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-95, y1, 79);
	glVertex3d(-95, y1, 81);
	glVertex3d(-90, y1, 81);
	glVertex3d(-90, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-85, y1, 79);
	glVertex3d(-85, y1, 81);
	glVertex3d(-80, y1, 81);
	glVertex3d(-80, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-75, y1, 79);
	glVertex3d(-75, y1, 81);
	glVertex3d(-70, y1, 81);
	glVertex3d(-70, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-65, y1, 79);
	glVertex3d(-65, y1, 81);
	glVertex3d(-60, y1, 81);
	glVertex3d(-60, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-55, y1, 79);
	glVertex3d(-55, y1, 81);
	glVertex3d(-50, y1, 81);
	glVertex3d(-50, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-45, y1, 79);
	glVertex3d(-45, y1, 81);
	glVertex3d(-40, y1, 81);
	glVertex3d(-40, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-35, y1, 79);
	glVertex3d(-35, y1, 81);
	glVertex3d(-30, y1, 81);
	glVertex3d(-30, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-25, y1, 79);
	glVertex3d(-25, y1, 81);
	glVertex3d(-20, y1, 81);
	glVertex3d(-20, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-15, y1, 79);
	glVertex3d(-15, y1, 81);
	glVertex3d(-10, y1, 81);
	glVertex3d(-10, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(-5, y1, 79);
	glVertex3d(-5, y1, 81);
	glVertex3d(-0, y1, 81);
	glVertex3d(-0, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(5, y1, 79);
	glVertex3d(5, y1, 81);
	glVertex3d(10, y1, 81);
	glVertex3d(10, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(15, y1, 79);
	glVertex3d(15, y1, 81);
	glVertex3d(20, y1, 81);
	glVertex3d(20, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(25, y1, 79);
	glVertex3d(25, y1, 81);
	glVertex3d(30, y1, 81);
	glVertex3d(30, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(35, y1, 79);
	glVertex3d(35, y1, 81);
	glVertex3d(40, y1, 81);
	glVertex3d(40, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(45, y1, 79);
	glVertex3d(45, y1, 81);
	glVertex3d(50, y1, 81);
	glVertex3d(50, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(55, y1, 79);
	glVertex3d(55, y1, 81);
	glVertex3d(60, y1, 81);
	glVertex3d(60, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(55, y1, 79);
	glVertex3d(55, y1, 81);
	glVertex3d(60, y1, 81);
	glVertex3d(60, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(65, y1, 79);
	glVertex3d(65, y1, 81);
	glVertex3d(70, y1, 81);
	glVertex3d(70, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(75, y1, 79);
	glVertex3d(75, y1, 81);
	glVertex3d(80, y1, 81);
	glVertex3d(80, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(85, y1, 79);
	glVertex3d(85, y1, 81);
	glVertex3d(90, y1, 81);
	glVertex3d(90, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(95, y1, 79);
	glVertex3d(95, y1, 81);
	glVertex3d(100, y1, 81);
	glVertex3d(100, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(105, y1, 79);
	glVertex3d(105, y1, 81);
	glVertex3d(110, y1, 81);
	glVertex3d(110, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(115, y1, 79);
	glVertex3d(115, y1, 81);
	glVertex3d(120, y1, 81);
	glVertex3d(120, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(125, y1, 79);
	glVertex3d(125, y1, 81);
	glVertex3d(130, y1, 81);
	glVertex3d(130, y1, 79);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(135, y1, 79);
	glVertex3d(135, y1, 81);
	glVertex3d(140, y1, 81);
	glVertex3d(140, y1, 79);
	glEnd();
}

void display(void) {
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glTranslatef(direction, 0.0f, 0.0f);
	glScalef(zoom, zoom, zoom);

	base();
	prism();
	wall();
	terrace();
	sun();
	garbage();
	tree();
	cloud();
	tanah();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '3':
		direction += 3.0f;
		break;
	case '1':
		direction -= 3.0f;
		break;

	case 'q':
	case 'Q':
		zoom += 0.2f;
		break;
	case 'e':
	case 'E':
		zoom -= 0.2f;
		break;
	case 'O':
	case 'o':
		if (specularLightstatus == 1)
		{
			glDisable(GL_LIGHTING);
			glutPostRedisplay();
			specularLightstatus = 0;
		}
		else
		{
			glEnable(GL_LIGHTING);
			glutPostRedisplay();
			specularLightstatus = 1;
		}
		break;
	case 'p':
	case     'P':
		if (ambientLightStatus == true)
		{
			glDisable(GL_LIGHT0);
			glutPostRedisplay();
			ambientLightStatus = false;
		}
		else
		{
			glEnable(GL_LIGHT0);
			glutPostRedisplay();
			ambientLightStatus = true;
		}
		break;
	}
	display();
}

void shape(int width, int height) {
	if (height == 0) height = 1;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, width / height, 5.0, 1000.0);
	glTranslatef(0.0, -5.0, -400.0);
	glMatrixMode(GL_MODELVIEW);
}

void Timer(int) {
	glutPostRedisplay();
	glutTimerFunc(30, Timer, 1);

	x_pos += deltax;
}