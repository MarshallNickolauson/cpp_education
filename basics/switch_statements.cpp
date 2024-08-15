#include <iostream>

int main() {

    int month;
    std::cout << "Enter month number (1-3): ";
    std::cin >> month;

    switch(month) {
        case 1:
            std::cout << "January";
            break;
        case 2:
            std::cout << "February";
            break;
        case 3:
            std::cout << "March";
            break;
        default:
            std::cout << "Not valid.";
    }

    return 0;
}