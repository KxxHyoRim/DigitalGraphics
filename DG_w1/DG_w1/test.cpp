#include <gl/glut.h>

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	/* Star */
	glColor3f(0.32, 0.764, 0.875);	// skyblue
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.9f, 0.8f, 0.0f);
		glVertex3f(-0.5f, 0.8f, 0.0f);
		glVertex3f(-0.7f, 0.65f, 0.0f);

		glVertex3f(-0.7f, 0.93f, 0.0f);
		glVertex3f(-0.85f, 0.55f, 0.0f);
		glVertex3f(-0.63f, 0.7f, 0.0f);

		glVertex3f(-0.9f, 0.8f, 0.0f);
		glVertex3f(-0.67f, 0.8f, 0.0f);
		glVertex3f(-0.57f, 0.55f, 0.0f);
	glEnd();

	glColor3f(1, 1, 1);	// white line
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-0.9f, 0.8f, 0.0f);
		glVertex3f(-0.75f, 0.8f, 0.0f);
		glVertex3f(-0.7f, 0.93f, 0.0f);
		glVertex3f(-0.66f, 0.8f, 0.0f);
		glVertex3f(-0.5f, 0.8f, 0.0f);
		glVertex3f(-0.63f, 0.7f, 0.0f);
		glVertex3f(-0.57f, 0.55f, 0.0f);
		glVertex3f(-0.7f, 0.65f, 0.0f);
		glVertex3f(-0.85f, 0.55f, 0.0f);
		glVertex3f(-0.78f, 0.71f, 0.0f);
	glEnd();

	/* Pentagon */
	glColor3f(1, 0.2, 0.684);	// Pink
	glBegin(GL_POLYGON);
		glVertex3f(0.0f, 0.9f, 0.0f);
		glVertex3f(0.2f, 0.75f, 0.0f);
		glVertex3f(0.13f, 0.5f, 0.0f);
		glVertex3f(-0.13f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.75f, 0.0f);
	glEnd();
	
	glColor3f(1, 1, 1);	// white line
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.0f, 0.9f, 0.0f);
		glVertex3f(0.2f, 0.75f, 0.0f);
		glVertex3f(0.13f, 0.5f, 0.0f);
		glVertex3f(-0.13f, 0.5f, 0.0f);
		glVertex3f(-0.2f, 0.75f, 0.0f);
	glEnd();

	/* Triangle */
	glColor3f(1, 0.853, 0.0);	//Yellow
	glBegin(GL_TRIANGLES); 
		glVertex3f(0.5f, 0.5f, 0.0f);
		glVertex3f(0.7f, 0.83f, 0.0f);
		glVertex3f(0.9f, 0.5f, 0.0f);
	glEnd();

	glColor3f(1, 1, 1);	// white line
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.5f, 0.5f, 0.0f);
		glVertex3f(0.7f, 0.83f, 0.0f);
		glVertex3f(0.9f, 0.5f, 0.0f);
	glEnd();

	/* Two Parallel LInes */
	glColor3f(1, 1, 1);
	glLineWidth(7.0);
	glBegin(GL_LINES);
		glVertex3f(-0.9f, -0.6f, 0.0f);
		glVertex3f(-0.13f, -0.6f, 0.0f);
		glVertex3f(-0.9f, -0.9f, 0.0f);
		glVertex3f(-0.13f, -0.9f, 0.0f);
	glEnd();

	/* Line_Strip */
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.15f, -0.57f, 0.0f);
		glVertex3f(0.85f, -0.57f, 0.0f);
		glVertex3f(0.85f, -0.87f, 0.0f);
		glVertex3f(0.15f, -0.87f, 0.0f);
	glEnd();

	/* 김 */
	glColor3f(0, 0, 1);
	glBegin(GL_QUADS); //ㄱ
		glVertex3f(-0.2f, 0.2f, 0.0f);
		glVertex3f(0.0f, 0.2f, 0.0f);
		glVertex3f(0.0f, 0.15f, 0.0f);
		glVertex3f(-0.2f, 0.15f, 0.0f);

		glVertex3f(-0.05f, 0.15f, 0.0f);
		glVertex3f(0.0f, 0.15f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-0.05f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS); // ㅣ
		glVertex3f(0.1f, 0.3f, 0.0f);
		glVertex3f(0.15f, 0.3f, 0.0f);
		glVertex3f(0.15f, -0.05f, 0.0f);
		glVertex3f(0.1f, -0.05f, 0.0f);
	glEnd();

	// ㅁ: 큰 파란색 네모
	glBegin(GL_QUADS); 
		glVertex3f(-0.05f, -0.1f, 0.0f);
		glVertex3f(0.16f, -0.1f, 0.0f);
		glVertex3f(0.16f, -0.25f, 0.0f);
		glVertex3f(-0.05f, -0.25f, 0.0f);
	glEnd();

	// ㅁ : 파란샥 네모 안에 작은 검정색 네모
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS); 
		glVertex3f(0.0f, -0.15f, 0.0f);
		glVertex3f(0.11f, -0.15f, 0.0f);
		glVertex3f(0.11f, -0.2f, 0.0f);
		glVertex3f(0.0f, -0.2f, 0.0f);
	glEnd();

	
	// 김 : white line
	glColor3f(1, 1, 1);
	glLineWidth(2.0);
	glBegin(GL_LINE_LOOP);  // ㄱ
		glVertex3f(-0.2, 0.2, 0.0);
		glVertex3f(0.0, 0.2, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-0.05, 0.0, 0.0);
		glVertex3f(-0.05, 0.15, 0.0);
		glVertex3f(-0.2, 0.15, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);  // ㅣ
		glVertex3f(0.1f, 0.3f, 0.0f);
		glVertex3f(0.15f, 0.3f, 0.0f);
		glVertex3f(0.15f, -0.05f, 0.0f);
		glVertex3f(0.1f, -0.05f, 0.0f);
	glEnd();
	
	glBegin(GL_LINE_LOOP);  // ㅁ
		glVertex3f(-0.05f, -0.1f, 0.0f);
		glVertex3f(0.16f, -0.1f, 0.0f);
		glVertex3f(0.16f, -0.25f, 0.0f);
		glVertex3f(-0.05f, -0.25f, 0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);  // 작은 ㅁ
		glVertex3f(0.0f, -0.15f, 0.0f);
		glVertex3f(0.11f, -0.15f, 0.0f);
		glVertex3f(0.11f, -0.2f, 0.0f);
		glVertex3f(0.0f, -0.2f, 0.0f);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
	glutCreateWindow("Lecture");

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}