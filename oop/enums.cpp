#include <iostream>

enum Day {sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thursday = 4, friday = 5, saturday = 6};

int main() {

    // enums = enumerations = a user-defined data type that consists
    //                        of paired name-integer constants.
    //                        GREAT if you have a set of potential options

    Day today = sunday;

    switch(today) {
        case sunday:
            std::cout << "It is Sunday!";
            break;
        case 1:
            std::cout << "It is monday!";
            break;
        default:
            std::cout << "Hi";
            break;
    }

    return 0;
}