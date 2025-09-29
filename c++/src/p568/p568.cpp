// p568.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string press;
    string author;
public:
    Book(string title = "", string press = "", string author = "") {
        this->title = title;
        this->press = press;
        this->author = author;
    }
    friend ostream& operator<<(ostream& stream, Book b);
};

ostream& operator<<(ostream& stream, Book b) {
    stream << b.title << "," << b.press << "," << b.author;
    return stream;
}

int main()
{
    Book book("소유냐 존재냐", "한국출판사", "에리히프롬");
    cout << book;
}

