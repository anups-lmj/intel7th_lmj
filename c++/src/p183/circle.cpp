#include "circle.h"
using namespace std;

double Circle::getArea() {
	return 3.14*radius*radius;
}
Circle::Circle() {
	radius = 1;
	cout << "持失切 radius : " << radius << endl;
}
Circle::Circle(int radius) {
	this ->radius = radius;
	//radois = radius;
	cout << "持失切 radius : " << radius << endl;
}

Circle::~Circle()
{
	cout << "社瑚切 radius : " << radius << endl;
}
