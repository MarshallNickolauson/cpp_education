#include <iostream>

int main() {
    // do while loop = do some block of code first,
    //                 THEN repeat again if condition is true

    int number;

    do {
        std::cout << "Enter positive number: ";
        std::cin >> number;
    } while(number < 0);

    return 0;
}