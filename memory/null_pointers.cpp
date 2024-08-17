#include <iostream>

int main() {

    // Null Value = a special value that means something has no value.
    //              When a pointer is holding a null value,
    //              that pointer is not pointing to anything (null pointer)

    // nullptr = keyword that represets a null pointer literal

    // nullptrs are helpful when determining if an address
    // was successfully assigned to a pointer

    // int *pointer; // BAD PRACTICE

    // dereferencing a null pointer is NOT SAFE

    int *pointer = nullptr;
    int x = 123;
    pointer = &x;

    if(pointer == nullptr) {
        std::cout << "Address was not assigned!\n";
    } else {
        std::cout << "Address was assigned";
    }

    return 0;
}