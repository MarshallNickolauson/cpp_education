#include <iostream>

int main() {

    // dynamic memory = Memory that is allocated after the program is already compiled and running.
    // use the 'new' operator to allocate memory in the heap rather than the stack

    // Useful when we don't know how much memory we will need.
    // Makes programs more flexible, especially when accepting user input.

    int *pNum = nullptr;

    pNum = new int; // always delete this pointer later after it's no longer used

    *pNum = 21;

    std::cout << "Address: " << pNum << '\n'; // In the heap
    std::cout << "Value: " << *pNum << '\n';

    delete pNum; // must free up memory at this heap address, or else you'll cause a memory leak

    ///////////////////////////////////////////////////////////////

    char *pGrades = nullptr;
    int size;

    std::cout << "How many grades to enter in?: ";
    std::cin >> size;

    pGrades = new char[size];

    for(int i = 0; i < size; i++) {
        std::cout << "Enter grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for(int i = 0; i < size; i++) {
        std::cout << pGrades[i] << " ";
    }

    delete[] pGrades; // NOTICE THE BRACKETS

    return 0;
}