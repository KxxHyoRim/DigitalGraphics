#include <gl/glut.h>

bool drawing = true;
GLfloat x1, y1, x2, y2;
#define MAX 300.0

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON
		&& state == GLUT_DOWN)
	{
		x1 = x;
		y1 = y;
	}
}

void mouseDrag(int x, int y)
{
	x2 = x;
	y2 = y;
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT
		| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (drawing) {
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(2 * x1 / MAX - 1, 2 * (MAX - y1) / MAX - 1, 0);
		glVertex3f(2 * x2 / MAX - 1, 2 * (MAX - y1) / MAX - 1, 0);
		glVertex3f(2 * x2 / MAX - 1, 2 * (MAX - y2) / MAX - 1, 0);
		glVertex3f(2 * x1 / MAX - 1, 2 * (MAX - y2) / MAX - 1, 0);
		glEnd();
	}
	glFlush();
}

int main(int argc, char** argv)
{
	x1 = y1 = x2 = y2 = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA
		| GLUT_DEPTH | GLUT_SINGLE);
	glutCreateWindow("Transformation");
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Background Color

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseDrag);
	glutMainLoop();

	return 0;
}

