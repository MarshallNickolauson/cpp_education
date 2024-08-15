#include <iostream>

int main() {

    double temp;
    char unit;

    std::cout << "Temp Conversion Program\n";
    std::cout << "F = Fahrenheit\n";
    std::cout << "C = Celcius\n";
    std::cout << "What unit would you like to convert to? ";
    std::cin >> unit;

    if(unit == 'F' || unit == 'f') {
        std::cout << "Enter temp in Celcius: ";
        std::cin >> temp;

        temp = (1.8 * temp) + 32.0;
        std::cout << "Temp = " << temp << "F";
    }
    else if (unit == 'C' || unit == 'c') {
        std::cout << "Enter temp in Fahrenheit: ";
        std::cin >> temp;

        temp = (temp - 32) / 1.8;
        std::cout << "Temp = " << temp << "C";
    }
    else {
        std::cout << "Invalid\n";
    }

    return 0;
}