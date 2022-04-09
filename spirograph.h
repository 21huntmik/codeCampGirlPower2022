#ifndef _SPIROGRAPH_H_
#define _SPIROGRAPH_H_

void drawCircle(double x1, double y1, double radius);

void drawRectangle(double x1, double y1, double x2, double y2);

void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
	
void drawText(double x, double y, const char *string);

void spirographRecursive(int R, int rm, int t, int p, int i);

int recursiveLimit(int R, int r);

void display();

void keyboard(unsigned char c, int x, int y);

void reshape(int w, int h);

void mouse(int mouse_button, int state, int x, int y);

int main(int argc, char **argv);

#endif
