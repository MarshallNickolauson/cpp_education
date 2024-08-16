#include <iostream>

void happyBirthday(std::string name, int age);

int main() {

    std::string name = "Bob";
    int age = 21;

    happyBirthday(name, age);

    return 0;
}

void happyBirthday(std::string nameArg, int ageArg) {
    std::cout << "Happy Birthday to " << nameArg << '\n';
    std::cout << "You are " << ageArg << '\n';
}