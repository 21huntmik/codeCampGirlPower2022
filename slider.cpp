#include <iostream>
#include "glut.h"
#include "slider.h"
#include "spirograph.h"

Slider::Slider(double left, double bottom, double right, double top, double red, double green, double blue, double value)
	: mLeft(left), mBottom(bottom), mRight(right), mTop(top), mRed(red), mGreen(green), mBlue(blue), mValue(value) {
}

void Slider::draw() {
	glColor3d(mRed, mGreen, mBlue);
	drawRectangle(mLeft, mBottom, mRight, mTop);
	glColor3d(0.98, 0.1, 0.4);
	double x = mLeft + (mRight - mLeft) * mValue;
	drawRectangle(x - 3, mBottom - 1, x + 3, mTop + 1);
}

double Slider::getValue() {
	return mValue;
}
void Slider::setValue(double value) {
	mValue = value;
}

void Slider::updateVariables(double x, double y) {
	std::cout << "It is at least getting to the function" << std::endl;
	std::cout << "X & Y " << x << ", " << y << std::endl;
	if (x >= mLeft && x <= mRight && y >= mBottom && y <= mTop) {
		double newValue = (x - mLeft) / 150;
		setValue(newValue);
		std::cout << "working" << std::endl;
		std::cout << getValue() << std::endl;
	}
}
