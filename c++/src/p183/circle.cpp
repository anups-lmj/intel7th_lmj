#include "circle.h"
using namespace std;

double Circle::getArea() {
	return 3.14*radius*radius;
}
Circle::Circle() {
	radius = 1;
	cout << "������ radius : " << radius << endl;
}
Circle::Circle(int radius) {
	this ->radius = radius;
	//radois = radius;
	cout << "������ radius : " << radius << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� radius : " << radius << endl;
}
