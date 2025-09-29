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
    cout << "积己磊 (int, int) width: " << width << endl;
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
    cout << "家戈磊 角青" << "width : " << width << " height : " << height << endl;
}
void Rectangle::setter(int w, int h) {
    width = w;
    height = h;
}
int Rectangle::getArea()
{
    return width * height;
}