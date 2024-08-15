#include <iostream>
// https://cplusplus.com/reference/string/string

int main() {

    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    name.length(); //returns int of number of chars
    name.empty(); //boolean
    name.clear(); //clears string
    name.append("@gmail.com"); //appends
    name.at(0); //returns char at given index (0-based)
    name.insert(0, "@"); //inserts at index
    name.find(" "); //finds index position of the first space
    name.erase(0, 3); //deletes between starting and ending index

    return 0;
}