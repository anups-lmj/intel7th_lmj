#include <iostream>
#include "rectangle.h"
using namespace std;

//Rectangle::Rectangle(){
////    width = 0;
////    height = 0;
//}
Rectangle::Rectangle() :width(0), height(0) {
    //width = 0;
    //height = 0;
    cout << "������ (int, int) width: " << width << endl;
}
//Rectangle::Rectangle():Rectangle(0,0) {
////    width = 0;
////    height = 0;
//}

Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}
Rectangle::~Rectangle() {
    cout << "�Ҹ��� ����" << "width : " << width << " height : " << height << endl;
}
void Rectangle::setter(int w, int h) {
    width = w;
    height = h;
}
int Rectangle::getArea()
{
    return width * height;
}