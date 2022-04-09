#include <iostream>
#include "arrowButtons.h"

TriangleButton::TriangleButton(double x1, double y1, double x2, double y2, double x3, double y3, int value)
	: mX1(x1), mY1(y1), mX2(x2), mY2(y2), mX3(x3), mY3(y3), mValue(value) {
}

void TriangleButton::draw() {
	glColor3d(0.98, 0.1, 0.4);
	drawTriangle(mX1, mY1, mX2, mY2, mX3, mY3);
	glColor3d(0.1, 0.03, 0.6);
	drawTriangle(mX3 + 25, mY2, mX3 + 56.25, mY1, mX3 + 87.5, mY2);
}

int TriangleButton::getValue() {
	return mValue;
}

void TriangleButton::setValue(int value) {
	mValue = value;
}

void TriangleButton::updateValue(double x, double y) {
	//y2 is high point, x1 is left, y1 is bottom, x3 is right
	std::cout << "Starting" << std::endl;
	if (x >= mX1 && x <= mX3 && y >= mY1 && y <= mY2) {
		mValue += 1;
		std::cout << "+1" << std::endl;
	} else if(x >= mX3 + 25 && x <= mX3 + 87.5 && y <= mY2 && y >= mY1) {
		std::cout << mValue << std::endl;
		mValue -= 1;
		std::cout << mValue << std::endl;
		std::cout << "-1" << std::endl;
	}
}
