#pragma once
#include <iostream>
#include <string>
#include "point.h"

class ColorPoint :public Point { //2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ���� ColorPoint, Point�� ��� ����
	string color;
public:
	void setColor(string color);
	void showColorPoint();//Point�� showPoint() ȣ��
};
