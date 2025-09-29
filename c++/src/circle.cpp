#include <iostream>
using namespace std;
#include "circle.h"

Circle::Circle() {
	radius = 1;
	cout << "������ radius : " << radius << endl;
}

Circle::Circle(const Circle& c)
{
	this->radius = c.radius;
	cout << "���� ������ ���� radius = " << radius << endl;
}

Circle::Circle(int radius) {
	this -> radius = radius;
	cout << "������ radius : " << radius << endl;
}

Circle::~Circle()
{
	cout << "�Ҹ��� radius : " << radius << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

