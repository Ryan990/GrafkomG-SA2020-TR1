#include <windows.h>
#include <GL/glut.h>

int y1 = 0;
int y2 = y1 + 50;
int y3 = y2 + 10;
int y4 = 20;
int y5 = y4 + 2;
int y6 = y3 + 5;

void init(void);
void terrace(void);
void prism(void);
void wall(void);
void base(void);
void display(void);
void keyboard(unsigned char, int, int);
void shape(int, int);
void Timer(int);
int xx = 0, yy = 0, zz = 0, sudut = 0;
float x_pos = 0.0f;
float deltax = 0.05f;

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
	glClearColor(255, 255, 255, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(1.0f);
	glLineWidth(3.0f);
}

void terrace(){
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

void display(void) {
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	
	base();
	prism();
	wall();
	terrace();

	glPushMatrix(); // matahari
	glEnable(GL_COLOR_MATERIAL);
	glTranslatef(-150 + x_pos ,160 ,10);
	glRotatef(sudut, xx, yy, zz);
	glColor3f(1, 1, 0);
	glutSolidSphere(2, 20, 20);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();


	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '3':
		glTranslatef(3.0, 0.0, 0.0);
		break;
	case '1':
		glTranslatef(-3.0, 0.0, 0.0);
		break;

	case 's':
	case 'S':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case 'x':
	case 'X':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 'd':
	case 'D':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 'c':
	case 'C':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case 'a':
	case 'A':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case 'z':
	case 'Z':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;


	case 'q':
	case 'Q':
		glScalef(0.8, 0.8, 0.8f);
		break;
	case 'e':
	case 'E':
		glScalef(1.2, 1.2, 1.2f);
		break;
	}
	display();
}


void shape(int width, int height) {
	if (height == 0) height = 1;

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
