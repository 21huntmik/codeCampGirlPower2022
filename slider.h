#ifndef _SLIDER_H_
#define _SLIDER_H_
#include "spirograph.h"

class Slider {
public:
	Slider(double left, double bottom, double right, double top, double red, double green, double blue, int value);
	void draw();
	int getValue();
	void setValue(int value);
	void updateVariables(double x, double y);
private:
	double mLeft, mBottom, mRight, mTop, mRed, mGreen, mBlue;
	int mValue;
};

#endif
