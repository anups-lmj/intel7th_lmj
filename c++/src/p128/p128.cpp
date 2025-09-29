// p128.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Circle {
private:
    int radius;
public:
    Circle();
    Circle(int r);
    double getArea();
    int getRadius();
    void setRadius(int);
};

Circle::Circle() {
    radius = 1;
}

Circle::Circle(int r) {
    radius = r;
}

int Circle::getRadius() {
    return radius;
}

void Circle::setRadius(int r) {
    radius = r;
}

int main()
{
    Circle waffle(5);
    //waffle.radius = 5;
    //cout << "waffle.radius : " << waffle.radius << endl;
    waffle.setRadius(10);
    cout << "waffle.radius : " << waffle.getRadius() << endl;
}

