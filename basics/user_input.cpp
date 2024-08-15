#include <iostream>

// cout << (insersion operator)
// cin >> (extraction operator)

int main() {

    std::string name;
    int age;

    std::cout << "What's your age? ";
    std::cin >> age; // character in without spaces

    std::cout << "What's your name? ";
    std::getline(std::cin >> std::ws, name); // character line with spaces

    std::cout << "Hello " << name << '\n'; 
    std::cout << "You are " << age << " years old";

    return 0;
}