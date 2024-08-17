#include <iostream>

int main() {
     
    // pointers = variable that stores a memory address of another variable
    //            sometimes it's easier to work with an address

    // & = address-of operator
    // * = dereference operator

    std::string name = "Bro";
    std::string *pName = &name;
    std::cout << pName << '\n'; // 0x24b1ff9f0
    std::cout << *pName << '\n'; // Bro

    int age = 21;
    int *pAge = &age;
    std::cout << pAge << '\n'; // 0x24b1ff9f0
    std::cout << *pAge << '\n'; // Bro

    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    std::string *pFreePizzas = freePizzas; // an array is already an address
    std::cout << pFreePizzas << '\n'; // 0x24b1ff9f0
    std::cout << *pFreePizzas << '\n'; // pizza1

    return 0;
}