// 335.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public:
    Power(int kick = 0, int punch = 0) {
        this->kick = kick;
        this->punch = punch;
    }
    void show();
    Power(const Power& Power);
    Power operator+(Power op2);
    Power operator+(int op2);
    bool operator==(Power& op2);
    Power& operator+=(Power op2);
    Power& operator++ ();
};
void Power::show() {
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power Power::operator+(Power op2) {
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}
Power Power::operator+(int op2) {
    Power tmp;
    tmp.kick = this->kick + op2;
    tmp.punch = this->punch + op2;
    return tmp;
}

bool Power::operator==(Power& op2)
{
    if ((this->kick == op2.kick) && (this->punch == op2.punch))
        return true;
    else 
        return false;
}

Power& Power::operator+=(Power op2)
{
    this->kick = this->kick + op2.kick;
    this->punch = this->punch + op2.punch;
    return *this;
    // TODO: 여기에 return 문을 삽입합니다.
}

Power& Power::operator++() {
    kick++;
    punch++;
    return *this;
}

Power::Power(const Power& Power) {
    this->kick = Power.kick;
    this->punch = Power.punch;
    cout << "복사 생성자 호출, " << "kick: " << this->kick << " punch: " << this->punch << endl;
}

int main()
{
    /*Power a(3, 5), b(4, 6), c;
    c = a + b;
    a.show();
    b.show();
    c.show();

    c = c + 2;
    c.show();

    if (a == b)
        cout << "두 파워가 같다." << endl;
    else
        cout << "두 파워가 다르다." << endl;

    a.show();
    b.show();
    c = a += b;
    a.show();
    c.show();*/

    Power a(3, 5), b;
    a.show();
    b.show();
    b = ++a;
    a.show();
    b.show();


    return 0;
}

