#include "spirograph.h"
#include "glut.h"

class TriangleButton {
public:
	TriangleButton(double x1, double y1, double x2, double y2, double x3, double y3, int value);

	void draw();

	int getValue();
	
	void setValue(int value);
		
	void updateValue(double x, double y);

private:
	double mX1, mY1, mX2, mY2, mX3, mY3;
	int mValue;
};
