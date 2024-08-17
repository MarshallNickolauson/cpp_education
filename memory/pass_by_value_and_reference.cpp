#include <iostream>

void swapByValue(std::string x, std::string y);
void swapByReference(std::string &x, std::string &y);

int main() {

    std::string x = "Kool-Aid";
    std::string y = "Water";
    std::string temp;

    swapByValue(x, y); // this is "pass by value", where the values are being copied to the function
    swapByReference(x, y); // this is "pass by reference", where the values of the memory addresses get swapped

    std::cout << "X: " << x << "\n";
    std::cout << "Y: " << y << "\n";

    return 0;
}

void swapByReference(std::string &x, std::string &y) {
    std::string temp = x;
    x = y;
    y = temp;
}

void swapByValue(std::string x, std::string y) {
    std::string temp = x;
    x = y;
    y = temp;
}