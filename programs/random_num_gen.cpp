#include <iostream>
#include <ctime>

int main() {
    // psuedo-random = NOT truly random (but close)

    srand(time(NULL)); // random seed (seed is current time)

    //random number between 1 and 6

    int num1 = (rand() % 6) + 1;
    int num2 = (rand() % 6) + 1;
    int num3 = (rand() % 6) + 1;
    
    
    std::cout << num1 << '\n';
    std::cout << num2 << '\n';
    std::cout << num3 << '\n';

    return 0;
}