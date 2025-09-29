
#include <iostream>
#include <string>
using namespace std;

class Animal {
    string name;
    int age;
public:
    Animal();
    Animal(string name, int age);
    Animal(const Animal& animal) {
        this->name = animal.name;
        this->age = animal.age;
    }
    virtual ~Animal();
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setAge(int age) { this->age = age; }
    int getAge() { return age; }
    friend void runnig(Animal& Animal);
    virtual void crying() = 0;
};
Animal::Animal() {
    name = "";
    this->age = 0;
}
Animal::Animal(string name, int age) {
    this->name = name;
    this->age = age;
}
Animal::~Animal() {
    cout << "Animal 소멸" << endl;
}
class Dog : public Animal {
    string bark;
public:
    Dog();
    virtual ~Dog();
    Dog(string name, int age, string bark) :Animal(name, age) {
        this->bark = bark;
    }
    Dog(const Dog& dog);
    string getBark() { return bark; }
    void crying()
    {
        cout << getName() << "는 " << bark << endl;
    }

};
Dog::Dog(){}
Dog::Dog(const Dog& dog) : Animal(dog)
{
    this->bark = dog.bark;
}
Dog::~Dog() {
    cout << "Dog 소멸" << endl;
}
class Cat : public Animal {
    string bark;
public:
    Cat();
    ~Cat();
    Cat(string name, int age, string bark) :Animal(name, age) {
        this->bark = bark;
    }
    Cat(const Cat& cat) : Animal(cat){
        this->bark = bark;
    }
    string getBark() { return bark; }
    void crying()
    {
        cout << "고양이는 " << bark << endl;
    }

};
Cat::Cat(){}

Cat::~Cat() {
    cout <<  "Cat 소멸" << endl;
}
void runnig(Animal& Animal) {
    cout << Animal.name << "가 달린다" << endl;
}
void run(Animal* pAnimal) {
    runnig(*pAnimal);
    pAnimal->crying();
}
int main()
{
    
    cout << "--추상클래스와 파생 클래스 구현--\n";
    Dog* dog = new Dog("강아지", 4, "멍멍");
    Cat* cat = new Cat("고양이", 2, "야옹");

    cout << "--매개 변수의 다형성 구현--\n";
    run(dog);
    run(cat);

    cout << "\n--복사생성자 직접 구현--\n";
    Dog copyDog(*dog);
    cout << copyDog.getName() << endl;
    cout << copyDog.getAge() << endl;
    cout << copyDog.getBark() << endl;

    cout << "\n--소멸자 실행--\n";
    delete dog;
    delete cat;
    return 0;
}

