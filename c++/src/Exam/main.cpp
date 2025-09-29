#include <iostream>
#include <string>
#include <vector>

// 기본 클래스: Animal
class Animal {
public:
    // 가상 함수로 선언하여 동적 바인딩(dynamic binding)을 가능하게 함
    virtual void speak() const {
        std::cout << "동물이 소리를 냅니다." << std::endl;
    }
    // 가상 소멸자: 파생 클래스의 소멸자가 올바르게 호출되도록 보장
    virtual ~Animal() {} 
};

// 파생 클래스: Dog
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "멍멍!" << std::endl;
    }
    void wagTail() const {
        std::cout << "개가 꼬리를 흔듭니다." << std::endl;
    }
};

// 파생 클래스: Cat
class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "야옹~" << std::endl;
    }
    void purr() const {
        std::cout << "고양이가 가르랑거립니다." << std::endl;
    }
};

int main() {
    // 1. 업캐스팅 (Upcasting)
    // 파생 클래스(Dog, Cat)의 객체를 기본 클래스(Animal)의 포인터로 가리키는 것
    // 이는 'is-a' 관계 (개는 동물이다)를 잘 보여줌
    std::cout << "--- 업캐스팅 예제 ---" << std::endl;
    Animal* pDog = new Dog();
    Animal* pCat = new Cat();

    pDog->speak(); // "멍멍!" 출력 (가상 함수 덕분에 Dog의 speak()가 호출됨)
    pCat->speak(); // "야옹~" 출력 (가상 함수 덕분에 Cat의 speak()가 호출됨)

    // 2. 다운캐스팅 (Downcasting)
    // 기본 클래스의 포인터를 다시 파생 클래스의 포인터로 변환하는 것
    // 다운캐스팅은 항상 안전하지 않으므로, dynamic_cast를 사용하는 것이 좋음
    std::cout << "\n--- 다운캐스팅 예제 ---" << std::endl;
    
    // Animal 포인터 벡터 생성 및 업캐스팅 활용
    std::vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Dog());

    for (Animal* animal : animals) {
        animal->speak(); // 각 동물의 speak() 호출

        // dynamic_cast를 사용한 안전한 다운캐스팅
        // animal이 실제로 Dog 객체를 가리키는지 확인
        Dog* dog = dynamic_cast<Dog*>(animal);
        if (dog != nullptr) {
            // 다운캐스팅 성공: Dog 클래스 고유의 멤버 함수 호출 가능
            dog->wagTail();
        }

        // animal이 실제로 Cat 객체를 가리키는지 확인
        Cat* cat = dynamic_cast<Cat*>(animal);
        if (cat != nullptr) {
            // 다운캐스팅 성공: Cat 클래스 고유의 멤버 함수 호출 가능
            cat->purr();
        }
        std::cout << std::endl;
    }

    // 메모리 해제
    delete pDog;
    delete pCat;
    for (Animal* animal : animals) {
        delete animal;
    }
    animals.clear();

    return 0;
}