#include "glut.h"
#include "slider.h"

Slider::Slider(double left, double bottom, double right, double top, double red, double green, double blue, int value)
	: mLeft(left), mBottom(bottom), mRight(right), mTop(top), mRed(red), mGreen(green), mBlue(blue), mValue(value) {
}

void Slider::draw() {
	glColor3d(mRed, mGreen, mBlue);
	drawRectangle(mLeft, mBottom, mRight, mTop);
	glColor3d(0.98, 0.1, 0.4);
	double x = mLeft + (mRight - mLeft) * mValue;
	drawRectangle(x - 5, mBottom - 5, x + 5, mTop + 5);
}

int Slider::getValue() {
	return mValue;
}
void Slider::setValue(int value) {
	mValue = value;
}

void Slider::updateVariables(double x, double y) {
	if (x >= mLeft && x<=mRight && y>=mBottom && y <= mTop) {
		mValue = (x - mLeft) / (mRight - mLeft);
	}
}
