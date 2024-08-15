#include <iostream>

int main() {

    int temp;
    std::cout << "Enter temp: ";
    std::cin >> temp;

    if(temp > 0 && temp < 60) {
        std::cout << "Temp is good"
    }

    //You know the rest:
    // &&
    // ||
    // !
    // ==

    return 0;
}