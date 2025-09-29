#pragma once
#include <iostream>
using namespace std;
class Point {
	int x, y;//ÇÑ Á¡(x,y) ÁÂÇ¥°ª
public:
	void set(int x, int y) { this->x = x;  this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};