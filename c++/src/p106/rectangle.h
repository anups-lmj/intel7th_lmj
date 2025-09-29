#pragma once
class Rectangle {
private:
    int width = 0;
    int height = 0;
public:
    Rectangle();
    Rectangle(int w, int h);
    int getArea();
    void setter(int w, int h);
    ~Rectangle();
};