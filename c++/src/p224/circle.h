#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle();
	Circle(const Circle& c);
	Circle(int r);
	~Circle();
	void setRadius(int radius)  { this -> radius = radius; } 
	double getArea(); 
	int getRadius() { return radius; }
}; 