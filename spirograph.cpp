#include <cmath>
#include <iostream>
#include <cstring>
#include "glut.h"
#include "spirograph.h"

//Global Variables
//Slider outerCircleRadius(75, 47.5, 225, 77.5, 1, 1, 1, 0.2);
//Slider innerCircleRadius(275, 47.5, 425, 77.5, 1, 1, 1, 1);
//Slider penRadius(475, 47.5, 625, 77.5, 1, 1, 1, 0.3);

double screen_x = 800;
double screen_y = 800;

void drawCircle(double x1, double y1, double radius) {
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++) {
		double theta = double(i/32.0 * 2.0 * 3.1415926);
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}

void drawRectangle(double x1, double y1, double x2, double y2) { 
	glBegin(GL_QUADS);
	glVertex2d(x1, y1);
	glVertex2d(x2, y1);
	glVertex2d(x2, y2);
	glVertex2d(x1, y2);
	glEnd();
}

void drawText(double x, double y, const char *string) {
	void *font = GLUT_BITMAP_9_BY_15;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	int len, i;
	glRasterPos2d(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
	glDisable(GL_BLEND);
}

void spirographRecursive(int R, int r, int t, int p, int i) {
	if (i < 50000) {
		int x1 = (R - r) * cos(t) + p * cos(((R-r)/r) * t) + 400;
		int y1 = (R - r) * sin(t) - p * sin(((R-r)/r) * t) + 400;
		glColor3d(0.7, 0.6, 0.8);
		drawCircle(x1, y1, 2);
		int x2 = (R - r) * cos(t) + (p + (p/2)) * cos(((R-r)/r) * t) + 400;
		int y2 = (R - r) * sin(t) + (p + (p/2)) * sin(((R-r)/r) * t) + 400;
		glColor3d(0.98, 0.1, 0.4);
		drawCircle(x2, y2, 2);
		int x3 = (R -r) * cos(t) + (p - (p/2)) * cos(((R-r)/r) * t) + 400;
		int y3 = (R -r) * sin(t) + (p - (p/2)) * sin(((R-r)/r) * t) + 400;
		glColor3d(0.1, 0.03, 0.6);
		drawCircle(x3, y3, 2);
		t += 1;
		i += 1;
		spirographRecursive(R, r, t, p, i);
	} else {
		return;
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	spirographRecursive(200, 41, 0, 23, 0);
	glColor3d(0.7, 0.6, 0.8);
	drawRectangle(800, 150, 0, 0); 
	glColor3d(0, 0, 0);
	drawText(98, 85, "Outer Radius");
	drawText(142, 30,  "0");
//	drawText(295, 85, "Inner Radius");
//	drawText(345, 30, 0);
//	drawText(535, 85, "Pen");
//	drawText(545, 30, 0);
	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char c, int x, int y) {
	switch (c) {
		case 27: //esc key
			exit(0);
			break;
		//case 'key here':
		default:
			return;
	}
	
	glutPostRedisplay();
}

void reshape(int w, int h) {
	screen_x = w;
	screen_y = h;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int mouse_button, int state, int x, int y) {
	x = double(x);
	y = double(y);

	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
	
	}
	if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	
	}
	if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
	
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(10, 10);
	
	glutCreateWindow("Spirograph");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	
	glColor3d(0,0,0);
	glClearColor(1,1,1,0);

	glutMainLoop();
	
	return 0;
}
