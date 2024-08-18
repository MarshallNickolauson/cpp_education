#include <iostream>

class Student {
    public:
        std::string name;
        int age;
        double gpa;

    Student(std::string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    // OR //
    // Student(std::string x, int y, double z) {
    //     name = x;
    //     age = y;
    //     gpa = z;
    // }
};

int main() {

    // constructor = special method in a class that is automatically called when an object is instantiated
    //               useful for assigning values to attributes as arguements

    Student student1("Spongebob", 25, 3.2);

    std::cout << student1.name << "\n";
    std::cout << student1.age << "\n";
    std::cout << student1.gpa << "\n";

    return 0;
}