// p106.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include "rectangle.h"
using namespace std;


Rectangle rect0;
int main()
{
    Rectangle rect1(1,1);
    Rectangle rect2(3,5);
    int width;
    int height;
    cout << "사각형의 면적은 " << rect2.getArea() << endl;
    cout << "사각형의 폭과 높이를 입력하세요 >> " << endl;
    cin >> width >> height;
    rect2.setter(width, height);
    cout << "사각형의 면적은 " << rect2.getArea() << endl;
}