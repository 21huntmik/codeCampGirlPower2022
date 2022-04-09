#include <cmath>
#include <iostream>
#include <cstring>
#include "glut.h"
#include "spirograph.h"
#include "arrowButtons.h"

//Global Variables
int colorMode; //one as default, white background. On key stroke, change to 0 (black) for DISCOOOOOO
int colorNum;

double colors[3][3][3] = { /*3 normal mode colors*/ {{0.7, 0.6, 0.8 /*purple*/}, {0.98, 0.1, 0.4 /*pink*/}, {0.1, 0.03, 0.6 /*blue*/}}, /*3 disco colors*/ {{0.98, 0.012, 0.6 /*pink*/}, {0.77, 0.012, 0.988 /*purple*/}, {0.012, 0.941, 0.988 /*blue*/}}, /*3 more disco colors*/ {{0.255, 0.988, 0.012 /*green*/}, {0.973, 0.988, 0.012 /*yellow*/}, {0.067, 0.012, 0.988 /*blue2*/}}};

TriangleButton outerUp(75, 48, 106.25, 95, 137.5, 48, 145);

TriangleButton innerUp(275, 48, 306.25, 95, 337.5, 48, 177);

TriangleButton penUp(475, 48, 506.25, 95, 537.5, 48, 221);

int outerValue = (int)outerUp.getValue();
int innerValue = (int)innerUp.getValue();
int penValue = (int)penUp.getValue();

double screen_x = 700;
double screen_y = 700;

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

void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
	glBegin(GL_TRIANGLES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glVertex2d(x3, y3);
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
	if (i <= 50000) {
		double x1 = (R + r) * cos(t) + p * cos((R*t+r*t)/r) + 350;
		double y1 = (R + r) * sin(t) + p * sin((R*t+r*t)/r) + 425;
		if(colorMode == 1) {
			glColor3d(colors[0][0][0], colors[0][0][1], colors[0][0][2]);
		} else if(colorMode == 0) {	
			if(colorNum == 1) {
				glColor3d(colors[1][2][0], colors[1][2][1], colors[1][2][2]);
				colorNum = 2;
			} else if(colorNum == 2) {
				glColor3d(colors[1][1][0], colors[1][1][1], colors[1][1][2]);
				colorNum = 1;
			}
		}				
		drawCircle(x1, y1, 1);
		double x2 = (R + r) * cos(t) + (p + (p/2)) * cos(((R*t+r*t)/r)) + 350;
		double y2 = (R + r) * sin(t) + (p + (p/2)) * sin(((R*t+r*t)/r)) + 425;
		if(colorMode == 1) {
			glColor3d(colors[0][1][0], colors[0][1][1], colors[0][1][2]);
		} else if(colorMode == 0) {
			if(colorNum == 1) {
				glColor3d(colors[1][0][0], colors[1][0][1], colors[1][0][2]);
				colorNum = 2;
			} else if(colorNum == 2) {
				glColor3d(colors[2][0][0], colors[2][0][1], colors[2][0][2]);
				colorNum = 1;
			}
		}
		drawCircle(x2, y2, 1);
		double x3 = (R +r) * cos(t) + (p - (p/2)) * cos(((R*t+r*t)/r)) + 350;
		double y3 = (R +r) * sin(t) + (p - (p/2)) * sin(((R*t+r*t)/r)) + 425;
		if(colorMode == 1) {
			glColor3d(colors[0][2][0], colors[0][2][1], colors[0][2][2]);
		} else if(colorMode == 0) {
			if(colorNum == 1) {
				glColor3d(colors[2][1][0], colors[2][1][1], colors[2][1][2]);
				colorNum = 2;
			} else if(colorNum == 2) {
				glColor3d(colors[2][2][0], colors[2][2][1], colors[2][2][2]);
				colorNum = 1;
			}
		}
		drawCircle(x3, y3, 1);
		t += 1;
		i += 1;
		spirographRecursive(R, r, t, p, i);
	} else {
		return;
	}
}

int recursiveLimit(int R, int r) {
	int leastCommonMultiplooth = 0;
	int max = (R > r) ? R : r;

	do {
		if (max % R == 0 && max % r == 0) {
			leastCommonMultiplooth = max;
			break;
		} else {
			max += 1;
		}
	} while (true);

	int limit = (2*3.1419) * (leastCommonMultiplooth / R);
	return limit;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	int rLimit = recursiveLimit(outerValue, innerValue);
	spirographRecursive(outerValue, innerValue, 0, penValue, 0);
	glColor3d(0.7, 0.6, 0.8);
	drawRectangle(700, 150, 0, 0);
	outerUp.draw();
	innerUp.draw();
	penUp.draw();
	glColor3d(0, 0, 0);
	drawText(98, 108, "Outer Radius");
	std::string tmp = std::to_string(outerValue);
	char const *outer = tmp.c_str();
	drawText(142, 30,  outer);
	drawText(295, 108, "Inner Radius");
	tmp = std::to_string(innerValue);
	char const *inner = tmp.c_str();
	drawText(345, 30, inner);
	drawText(535, 108, "Pen");
	tmp = std::to_string(penValue);
	char const *pen = tmp.c_str();
	drawText(545, 30, pen);
	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char c, int x, int y) {
	switch (c) {
		case 27: //esc key
			exit(0);
			break;
			
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
	y = screen_y - y;

	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		outerUp.updateValue(x, y);
		innerUp.updateValue(x, y);
		penUp.updateValue(x,y);
		outerValue = outerUp.getValue();
		innerValue = innerUp.getValue();
		penValue = penUp.getValue();
		glutPostRedisplay();
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
	
	}
	if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if(colorMode == 1) {
			colorMode = 0;
			colorNum = 1;
			glClearColor(0, 0, 0, 0);
			
		} else {
			colorMode = 1;
			glClearColor(1, 1, 1, 0);
		}
	}
	if (mouse_button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
	
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("Spiro-Spot");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	colorMode = 1;
	
		glColor3d(0,0,0);
	glClearColor(colorMode, colorMode, colorMode, 0);

	glutMainLoop();
	
	engine->drop();

	return 0;
}
