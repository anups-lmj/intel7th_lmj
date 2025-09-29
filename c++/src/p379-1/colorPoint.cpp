#include "colorPoint.h"
#include <iostream>

void setColor(string color) {
	this->color = color;
}
void ColorPoint::showColorPoint()
{
	cout << color << ":";
	showPoint();
}