#include <iostream>

struct student {
    std::string name;
    double gpa;
    bool enrolled = true;
}; //MUST HAVE SEMI COLON AFTER

int main () {

    // struct - it's an object with attributes
    student student1;
    student1.name = "Matthew";
    student1.gpa = 3.2;

    std::cout << student1.name << " " << student1.gpa;


    return 0;
}