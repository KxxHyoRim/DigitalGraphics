#include <gl/glut.h>


GLfloat blueAngle = 0.0f;

void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutCreateWindow("Transformation");

	glutDisplayFunc(display);
	glutIdleFunc(display);

	glutMainLoop();

	return 0;
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glColor3f(1.0f, 0.0f, 0.0f);   // red
	glutSolidSphere(0.1f, 100, 100);

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);   // blue
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.6f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 100, 100);

	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);   // green
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.3f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 100, 100);

	glColor3f(0.0f, 1.0f, 1.0f);   // skyblue
	glRotatef(blueAngle * 2, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.02f, 100, 100);

	glPopMatrix(); //blue status
	glColor3f(1.0f, 1.0f, 1.0f);   //white 
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.0f, 0.0f);		//芭府
	glutSolidSphere(0.025f, 100, 100);	//农扁

	glPopMatrix(); //red status
	glColor3f(1.0f, 1.0f, 0.0f);   //yellow 
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.3f, 0.0f, 0.0f);		//芭府
	glutSolidSphere(0.05f, 100, 100);	//农扁

	glColor3f(1.0f, 0.0f, 1.0f);   //yellow 
	glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.1f, 0.0f, 0.0f);		//芭府
	glutSolidSphere(0.025f, 100, 100);	//农扁


	blueAngle += 0.1f;
	glFlush();
}