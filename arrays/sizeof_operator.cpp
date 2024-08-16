#include <iostream>

int main() {

    // sizeof() = determines the size in BYTES of a:
    //            variable, data type, class, object, etc.

    std::string name = "Bob";
    double gpa = 2.5;
    char grade = 'A';
    bool student = true;
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    std::string students[] = {"Sponge", "Pat", "Squid", "Sandy", "Me"};

    std::cout << sizeof(name) << " bytes\n";
    std::cout << sizeof(gpa) << " bytes\n";
    std::cout << sizeof(grade) << " bytes\n";
    std::cout << sizeof(student) << " bytes\n";
    std::cout << sizeof(grades)/sizeof(grades[0]) << " bytes\n";

    for(int i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        std::cout << students[i] << '\n';
    }

    return 0;
}