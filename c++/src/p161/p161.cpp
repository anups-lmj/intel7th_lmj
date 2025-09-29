// p161.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "circle.h"

int main()
{
	//Circle circleArray[3];
	Circle circleArray[3] = { Circle(10),Circle(20),Circle(30) };
	int num[3] = { 10,20,30 };
	/*circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);*/
#if 0
	for (int i = 0; i < 3; i++)
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
#endif
	Circle* p;
	p = circleArray;
	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "의 면적은 " << p->getArea() << endl;
		p++;
	}
}

