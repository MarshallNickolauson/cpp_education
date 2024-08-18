#include <iostream>

class Animal {
    public:
        bool alive = true;

    void eat() {
        std::cout << "This animal is eating\n";
    }
};

class Dog : public Animal {
    public:
    
    void bark() {
        std::cout << "Woof\n";
    }
};

class Cat : public Animal {
    public:

    void meow() {
        std::cout << "Meow\n";
    }
};

int main() {

    Dog dog;
    std::cout << dog.alive << '\n';
    dog.eat();
    dog.bark();

    Cat cat;
    std::cout << cat.alive << '\n';
    cat.meow();

    return 0;
}