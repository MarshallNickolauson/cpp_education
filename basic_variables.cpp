#include <iostream>

int main() {

    //integer
    int age = 21;
    int year = 2023;
    int days = 7.5;

    //double (number with decimal)
    double price = 10.99;
    double gpa = 2.54557;
    double temperature = 25.1;

    //single character
    char grade = 'A';
    char initial = 'C';
    char currency = '$';

    //boolean
    bool isStudent = true;
    bool isTeacher = false;
    bool isPowered = true;

    //string
    std::string name = "First Name";
    std::string day = "Friday";
    std::string food = "Pizza";
    std::string address = "123 Fake Street";

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << " years old.";

    return 0;
}