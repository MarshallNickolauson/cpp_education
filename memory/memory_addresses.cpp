#include <iostream>

int main() {

    // memory address = a location in memory where data is stored
    // can be accessed with '&' (address-of operator)

    std::string name = "Bob";
    int age = 21;
    bool student = true;

    std::cout << &name << '\n';
    std::cout << &age << '\n';
    std::cout << &student << '\n';

    // returns hexadecimal
    // you can convert to decimal

    return 0;
}