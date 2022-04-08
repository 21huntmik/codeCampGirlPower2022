#ifndef _SPIROGRAPH_H_
#define _SPIROGRAPH_H_

void drawCircle(double x1, double y1, double radius);

void drawRectangle(double x1, double y1, double x2, double y2);
	
void drawText(double x, double y, const char *string);

void display();

void keyboard(unsigned char c, int x, int y);

void reshape(int w, int h);

void mouse(int mouse_button, int state, int x, int y);

void initialize();

int main(int argc, char **argv);

#endif
