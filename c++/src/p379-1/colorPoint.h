#pragma once
#include <iostream>
#include <string>
#include "point.h"

class ColorPoint :public Point { //2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint, Point를 상속 받음
	string color;
public:
	void setColor(string color);
	void showColorPoint();//Point의 showPoint() 호출
};
