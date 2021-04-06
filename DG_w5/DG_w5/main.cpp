#include <gl/glut.h>

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity;

	glColor3f(1.0, 0.0, 0.0);			//red
	glutSolidCube(0.3);

	glTranslatef(0.85, -0.85, 0.0);		//Skyblue
	glColor3f(0.0, 1.0, 1.0);
	glutSolidCube(0.3);

	glTranslatef(-0.85, 0.85, 0.0);


	glTranslatef(0.6, 0.0, 0.0);		//blue
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(0.3);

	glRotatef(-45.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.6, 0.0, 0.0);

	glRotatef(45.0, 0.0, 0.0, 1.0);		//green
	glTranslatef(0.6, 0.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCube(0.3);

	glTranslatef(-0.6, 0.0, 0.0);
	glRotatef(-45.0, 0.0, 0.0, 1.0);

	glRotatef(45.0, 0.0, 0.0, 1.0);		//grey
	glTranslatef(0.0, 0.6, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glutSolidCube(0.3);

	glTranslatef(0.0, -0.6, 0.0);
	glRotatef(-45.0, 0.0, 0.0, 1.0);

	glRotatef(45.0, 0.0, 0.0, 1.0);		//pink
	glTranslatef(-0.6, 0.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glutSolidCube(0.3);

	glTranslatef(0.6, 0.0, 0.0);
	glRotatef(-45.0, 0.0, 0.0, 1.0);

	glRotatef(45.0, 0.0, 0.0, 1.0);		// yellow
	glTranslatef(0.0, -0.6, 0.0);		
	glColor3f(1.0, 1.0, 0.0);		
	glutSolidCube(0.3);


	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutCreateWindow("Transformation");
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Background(white)
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}