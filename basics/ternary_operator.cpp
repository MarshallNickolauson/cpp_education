#include <iostream>

int main() {

    // ternary operator ?: = replacement to if/else statment
    // condition ? expression1 : expression 2;

    int grade = 75;
    
    grade >= 60 ? std::cout << "passed" : std::cout << "failed";

    //OR

    std::cout << (grade >= 60 ? "PASSED" : "FAILED");

    return 0;
}