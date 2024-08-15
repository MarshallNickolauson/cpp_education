#include <iostream>
#include <cmath>

int main() {

    // hypotenuse = sqrt(a^2 + b^2)

    double a;
    double b;
    double c;

    std::cout << "Enter side a: ";
    std::cin >> a;

    std::cout << "Enter side b: ";
    std::cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));

    std::cout << "Side C: " << c;

    return 0;
}