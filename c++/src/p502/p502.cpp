// p502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";

    }
    cout << endl;

    v[0] = 10;
    int n = v[2];
    v.at(2) = 5;

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

