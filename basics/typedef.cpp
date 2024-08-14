#include <iostream>
#include <vector>

// typedef std::vector<std::pair<std::string, int>> pairlist_t
// typedef std::string text_t;
// typedef int number_t;
using text_t = std::string;
using number_t = int;

int main() {
    
    // typedef = reserved keyword used to create an additional name
    //           (alias) for another data type.
    //           New identifier for an existing type
    //           Helps with readability and reduces typos
    //           Use when there is a clear benefit
    //           Replaced with 'using' (works better w/ templates)

    // std::vector<std::pair<std::string, int>> pairlist;
    // pairlist_t pairlist;

    // std::string firstName = "First Name";
    text_t firstName = "First Name";
    std::cout << firstName;

    number_t age = 21;
    std::cout << age;

    return 0;
}