// p224.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "circle.h"

//void increase(Circle c)
//{
//    int r = c.getRadius();
//    c.setRadius(r + 1);
//}

void increase(Circle *p)
{
    int r = (*p).getRadius();
    (*p).setRadius(r + 1);
}

void increase(Circle& p)
{
    int r = p.getRadius();
    p.setRadius(r + 1);
}
void readRadius(Circle& d)
{
    int r;
    cout << "정수 값으로 반지름을 입력하세요 >> ";
    cin >>  r;
    d.setRadius(r);
}
Circle getCircle() {
    Circle tmp(30);
    return tmp;
}
int main()
{
//    Circle waffle(30);
////    increase(waffle);
//    increase(&waffle);

   /* Circle c;
    cout << c.getArea() << endl;
    c = getCircle();
    cout << c.getArea() << endl;*/
    /*Circle circle;
    Circle& refc = circle;
    refc.setRadius(10);
    cout << refc.getArea() << " " << circle.getArea() << endl;

    cout << &circle << endl;
    cout << &refc << endl;
*/

   /* Circle waffle(30);
    increase(waffle);
    cout << waffle.getRadius() << endl;*/

    /*Circle donut;
    readRadius(donut);
    cout << "donut의 면적= " << donut.getArea() << endl;*/

    Circle src(30);
    Circle dest(src);

    src = dest;
    cout << "원본의 면적 = " << src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;

}
