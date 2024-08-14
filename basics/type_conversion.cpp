#include <iostream>

int main() {
    // type conversion = convert a value of one data type to another
    // Implicit = automatic
    // Explicit = Precede value with new data type - (int) x

    // int x = 3.14; //implicitly made 3
    // double x = (int) 3.14; //explicity made 3
    // std::cout << x;

    // char x = 100;
    // std::cout << x;
    // OR
    // std::cout (char) 100;

    int correct = 8;
    int questions = 10;

    double score = correct / (double) questions * 100;

    std::cout << score << "%";

    return 0;
}