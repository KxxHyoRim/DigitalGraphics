#include <gl/glut.h>

int shoulder = 0, elbow = 0, wrist = 0, leg = 0, neck = 0, position = 0;

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(20, 0.5, 1, 0);
	glTranslatef(0, 1.5, 0);
	glTranslatef(0, 0.0,(GLfloat)position);


	/* body & head */
	glPushMatrix();
		
		// body
		glTranslatef(0, -0.5, 0);
		glPushMatrix();
			glScalef(1.5, 1.75, 1.0);
			glColor3f(0.13, 0.61, 0.75);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		//head
		glTranslatef(0, 0.6, 0);
		glTranslatef(0.0, 0.25, 0.0);
		glRotatef((GLfloat)neck, 0.0, 0.0, 1.0);
		glTranslatef(0.0, 0.25, 0.0);
		glPushMatrix();
			glScalef(0.5, 0.5, 0.5);	// cube 길게
			glColor3f(0.95, 0.86, 0.82);			// sky blue
			glutSolidCube(1.0);			// 내부 채운 큐브
			glColor3f(0, 0, 0);			// black
			glutWireCube(1.0);
		glPopMatrix();
	glPopMatrix();

	/* right leg */
	glPushMatrix();
		// Right Thigh
		glTranslatef(0.25, -2.2, 0.0);
		glTranslatef(0.0, 0.85, 0.0);
		glRotatef((GLfloat)leg, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.85, 0.0);

		glPushMatrix();					
			glScalef(0.4, 1.7, 1.0);
			glColor3f(0.58, 0.69, 0.80);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		// Right Calf
		glTranslatef(0.0, -1.5, 0.0);

		glPushMatrix();					
			glScalef(0.4, 1.5, 1.0);
			glColor3f(0.66, 0.69, 0.80);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();
	glPopMatrix();

	/* Left Leg */
	glPushMatrix();

		// Left Thigh
		glTranslatef(-0.25, -2.2, 0.0);
		glTranslatef(0.0, 0.85, 0.0);
		glRotatef(-(GLfloat)leg, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -0.85, 0.0);
		glPushMatrix();
			glScalef(0.4, 1.7, 1.0);
			glColor3f(0.58, 0.69, 0.80);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		// Left Calf
		glTranslatef(0.0, -1.5, 0.0);
		glPushMatrix();
			glScalef(0.4, 1.5, 1.0);
			glColor3f(0.66, 0.69, 0.80);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();
	glPopMatrix();

	/* RIght Arm */
	glPushMatrix();
		// Right upper arm
		glTranslatef(1.4, 0.0, 0.0);
		glTranslatef(-1.0, 0.0, 0.0);
		glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
		glTranslatef(1.0, 0.0, 0.0);
		
		glPushMatrix();
			glScalef(1.3, 0.4, 1.0);
			glColor3f(0.58, 0.69, 0.80);
			glutSolidCube(1.0);	
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		// Right lower arm
		glTranslatef(0.1, 0.0, 0.0);
		glTranslatef(0.5, 0.0, 0.0);
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
		glTranslatef(0.5, 0.0, 0.0);	
		
		glPushMatrix();
			glScalef(1.0, 0.4, 1.0);	
			glColor3f(0.66, 0.85, 0.84);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		// Right hand
		glTranslatef(0.4, 0.0, 0.0);
		glTranslatef(0.1, 0.0, 0.0);
		glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
		glTranslatef(0.1, 0.0, 0.0);

		glPushMatrix();
		glScalef(0.2, 0.2, 1.0);
		glColor3f(0.95, 0.86, 0.82);
		glutSolidCube(1.0);
		glColor3f(0, 0, 0);
		glutWireCube(1.0);
		glPopMatrix();
	glPopMatrix();

	/* Left Arm */
	glPushMatrix();
		// Left upper arm
		glTranslatef(-1.4, 0.0, 0.0);
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
		glTranslatef(-1.0, 0.0, 0.0);

		glPushMatrix();
			glScalef(1.3, 0.4, 1.0);
			glColor3f(0.58, 0.69, 0.80);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		// Left lower arm
		glTranslatef(-0.1, 0.0, 0.0);
		glTranslatef(-0.5, 0.0, 0.0);
		glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
		glTranslatef(-0.5, 0.0, 0.0);

		glPushMatrix();
			glScalef(1.0, 0.4, 1.0);
			glColor3f(0.66, 0.85, 0.84);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

		// Left hand
		glTranslatef(-0.4, 0.0, 0.0);
		glTranslatef(-0.1, 0.0, 0.0);
		glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
		glTranslatef(-0.1, 0.0, 0.0);

		glPushMatrix();
			glScalef(0.2, 0.2, 1.0);
			glColor3f(0.95, 0.86, 0.82);
			glutSolidCube(1.0);
			glColor3f(0, 0, 0);
			glutWireCube(1.0);
		glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -5, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'w':
		wrist = (wrist + 5) % 360;
		glutPostRedisplay();
		break;
	case 'W':
		wrist = (wrist - 5) % 360;
		glutPostRedisplay();
		break;
	case 'l':
		leg = (leg + 5) % 360;
		glutPostRedisplay();
		break;
	case 'L':
		leg = (leg - 5) % 360;
		glutPostRedisplay();
		break;
	case 'n':
		neck = (neck + 5) % 360;
		glutPostRedisplay();
		break;
	case 'N':
		neck = (neck - 5) % 360;
		glutPostRedisplay();
		break;
	case 't':
		position = (position + 1);
		glutPostRedisplay();
		break;
	case 'T':
		position = (position - 1);
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rainbow man");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}
