#include "circle.h"
using namespace std;

double Circle::getArea() {
	return 3.14*radius*radius;
}
Circle::Circle() {
	radius = 1;
	cout << "������ radius : " << radius << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "������ radius : " << radius << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� radius : " << radius << endl;
}
