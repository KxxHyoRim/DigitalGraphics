#include <math.h>
#include <gl/glut.h>
#define PI 3.141592

void init();
void display();
void drawBox();
void keyboard(unsigned char, int, int);
void xyzRotate(char);


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("General Rotation");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();

	return 0;
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);			// background : white
	glMatrixMode(GL_PROJECTION);				// camera setup
	glLoadIdentity();							// camera setup
	glOrtho(-2.0, 2.0, -2.0, 2.0, -5, 50.0);	// camera setup

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glViewport(0, 0, 500, 500);		// camera setup
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(45.0, 1.0, 1.0, 1.0);
	glScalef(0.1, 0.2, 0.1);
	drawBox();

	glPopMatrix();

	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'x':
		xyzRotate('x');
		glutPostRedisplay();
		break;
	case 'y':
		xyzRotate('y');
		glutPostRedisplay();
		break;
	case 'z':
		xyzRotate('z');
		glutPostRedisplay();
		break;

	case 'u' :
		glTranslatef(0, 0.6, 0);
		xyzRotate('u');
		glTranslatef(0, -0.6, 0);
		glutPostRedisplay();
		break;

	case 'v':
		glTranslatef(0, 0, 0.6);
		xyzRotate('v');
		glTranslatef(0, 0, -0.6);
		glutPostRedisplay();
		break;

	case 'w':
		glTranslatef(0.6, 0, 0);
		xyzRotate('w');
		glTranslatef(-0.6, 0, 0);
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}
}

void xyzRotate(char mode) {
	GLfloat t[4][4];
	switch (mode) {
	case 'u':
	case 'x':
		t[0][0] = 1;				t[0][1] = 0;				t[0][2] = 0;				t[0][3] = 0;
		t[1][0] = 0;				t[1][1] = cos(PI / 10);		t[1][2] = -sin(PI / 10);	t[1][3] = 0;
		t[2][0] = 0;				t[2][1] = sin(PI / 10);		t[2][2] = cos(PI / 10);		t[2][3] = 0;
		t[3][0] = 0;				t[3][1] = 0;				t[3][2] = 0;				t[3][3] = 1;
		break;

	case 'v':
	case 'y':
		t[0][0] = cos(PI / 10);		t[0][1] = 0;				t[0][2] = sin(PI / 10);		t[0][3] = 0;
		t[1][0] = 0;				t[1][1] = 1;				t[1][2] = 0;				t[1][3] = 0;
		t[2][0] = -sin(PI / 10);	t[2][1] = 0;				t[2][2] = cos(PI / 10);		t[2][3] = 0;
		t[3][0] = 0;				t[3][1] = 0;				t[3][2] = 0;				t[3][3] = 1;
		break;

	case 'w':
	case 'z':
		t[0][0] = cos(PI / 10);		t[0][1] = -sin(PI / 10);	t[0][2] = 0;				t[0][3] = 0;
		t[1][0] = sin(PI / 10);		t[1][1] = cos(PI / 10);		t[1][2] = 0;				t[1][3] = 0;
		t[2][0] = 0;				t[2][1] = 0;				t[2][2] = 1;				t[2][3] = 0;
		t[3][0] = 0;				t[3][1] = 0;				t[3][2] = 0;				t[3][3] = 1;
		break;

	default:
		t[0][0] = 1;				t[0][1] = 0;				t[0][2] = 0;				t[0][2] = 0;
		t[1][0] = 0;				t[1][1] = cos(PI / 10);		t[1][2] = -sin(PI / 10);	t[1][2] = 0;
		t[2][0] = 0;				t[2][1] = sin(PI / 10);		t[2][2] = cos(PI / 10);		t[2][2] = 0;
		t[3][0] = 0;				t[3][1] = 0;				t[3][2] = 0;				t[3][2] = 1;
		break;
	}

	glMultMatrixf((const GLfloat*)t);
}


void drawBox() {
	/* Red Rectangle */
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glEnd();

	/* Green Rectangle */
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glEnd();

	/* Blue Lines */
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glEnd();
}
