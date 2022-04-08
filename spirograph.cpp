#include <cmath>
#include <iostream>
#include <cstring>
#include "glut.h"
#include "spirograph.h"
#include "slider.h"

//Global Variables
Slider outerCircleRadius(75, 47.5, 225, 77.5, 1, 1, 1, 0.2);
Slider innerCircleRadius(275, 47.5, 425, 77.5, 1, 1, 1, 0.1);
Slider penRadius(475, 47.5, 625, 77.5, 1, 1, 1, 0.3);

double screen_x = 700;
double screen_y = 500;

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

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	int R = outerCircleRadius.getValue();
	int r = innerCircleRadius.getValue();
	int A = penRadius.getValue();
	glColor3d(0.7, 0.6, 0.8);
	drawRectangle(700, 125, 0, 0); 
	outerCircleRadius.draw();
	innerCircleRadius.draw();
	penRadius.draw();
	glColor3d(0, 0, 0);
	int valOne = outerCircleRadius.getValue();
	std::string tmp = std::to_string(valOne);
	char const *valTwo = tmp.c_str();
	drawText(98, 85, "Outer Radius");
	drawText(142, 30,  valTwo);
	valOne = innerCircleRadius.getValue();
	tmp = std::to_string(valOne);
	char const *valThree = tmp.c_str();
	drawText(295, 85, "Inner Radius");
	drawText(345, 30, valThree);
	valOne = penRadius.getValue();
	tmp = std::to_string(valOne);
	char const *valFour = tmp.c_str();
	drawText(535, 85, "Pen");
	drawText(545, 30, valFour);
	glutSwapBuffers();
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
//glut.h graphics.cpp graphics.h slider.cpp slider.h
void mouse(int mouse_button, int state, int x, int y) {

	y = screen_y - y;
	double worldX = 100.0 * x / screen_x;
	double worldY = 100.0 * x / screen_y;

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

void motion(int x, int y) {
	y = screen_y - y;
	double worldX = 100.0 * x / screen_x;
	double worldY = 100.0 * y / screen_y;
	outerCircleRadius.updateVariables(worldX, worldY);
	innerCircleRadius.updateVariables(worldX, worldY);
	penRadius.updateVariables(worldX, worldY);
	glutPostRedisplay();
}

void initialize() {
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(50, 50);
	
	int fullscreen = 0;
	if (fullscreen) {
		glutGameModeString("800x600:32");
		glutEnterGameMode();
	} else {
		glutCreateWindow("Spirograph");
	}
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	
	glColor3d(0,0,0);
	glClearColor(1,1,1,0);
	initialize();
	
	glutMainLoop();
	
	return 0;
}
