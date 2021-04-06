#include <gl/glut.h>
#define MAX 300.0

bool click	 = false;
bool drag	 = false;

GLfloat blueAngle = 0.0f;
GLfloat x1, y1, x2, y2;


/* Function Declaration for Main() */
void display(void);
void mouseButton(int button, int state, int x, int y);
void mouseDrag(int x, int y);


int main(int argc, char** argv)
{
	x1 = y1 = x2 = y2 = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutCreateWindow("Advanced Solar System");
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);	// Background(white)


	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseDrag);
	glutMainLoop();

	return 0;
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON 	&& state == GLUT_DOWN)	{
		x1 = x;
		y1 = y;
		click = true;
		drag = false;
		glutPostRedisplay();
	}
}

void mouseDrag(int x, int y){
	x2 = x;
	y2 = y;
	drag = true;
	click = false;
	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (click)
		glTranslatef(2 * x1 / MAX - 1, 2 * (MAX - y1) / MAX - 1, 0);

	if (drag)
		glTranslatef(2 * x2 / MAX - 1, 2 * (MAX - y2) / MAX - 1, 0);

	/* Red */
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(0.1f, 100, 100);

	/* Blue :: axis around Red */
	glPushMatrix();							// push (RED)
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.6f, 0.0f, 0.0f);			// distance
	glutSolidSphere(0.05f, 100, 100);		// size

	/* Green :: axis around Blue */
	glPushMatrix();							// push (BLUE)
	glColor3f(0.0f, 1.0f, 0.0f);
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.3f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 100, 100);

	/* Skyblue :: axis around Green */
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(blueAngle * 2, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.02f, 100, 100);

	/* Black :: axis around Blue */
	glPopMatrix();							// pop (BLUE)
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(blueAngle * -2, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.0f, 0.0f);		
	glutSolidSphere(0.025f, 100, 100);

	/* Yellow :: axis around Red */
	glPopMatrix();							// pop (RED)
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(blueAngle * -0.7, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.3f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 100, 100);	

	/* Pink :: axis around Yello */
	glColor3f(1.0f, 0.0f, 1.0f);
	glRotatef(blueAngle * 3, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.025f, 100, 100);

	/* Rotation Speed Control */
	blueAngle += 0.25f;

	glFlush();
}