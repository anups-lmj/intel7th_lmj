// p178.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "circle.h"
int main()
{
    Circle* p, * q;
    p = new Circle;
    q = new Circle(10);
    if (!q)
    {
        cout << "메모리 부족" << endl;
    }
    cout << p->getArea() << endl << q->getArea() << endl;

    int* pArray = new int[10];
    memset(pArray, 0, sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        cout << "i : " << i << " " << pArray[i] << endl;

    delete p;
    delete q;
    delete [] pArray;
}

