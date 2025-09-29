// p140.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "adder.h"
#include "calc.h"
using namespace std;

int main()
{
	Calculator calc; // calc 객체 생성
	calc.run(); // 계산기 시작
}

