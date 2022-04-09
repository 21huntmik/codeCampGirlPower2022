#ifndef _SLIDER_H_
#define _SLIDER_H_


class Slider {
public:
	Slider(double left, double bottom, double right, double top, double red, double green, double blue, double value);
	void draw();
	double getValue();
	void setValue(double value);
	void updateVariables(double x, double y);
private:
	double mLeft, mBottom, mRight, mTop, mRed, mGreen, mBlue, mValue;
};

#endif
