#include <iostream>

namespace first {
    int x = 1;
}

namespace second {
    int x = 2;
}

int main() {

    //solution for preventing name conflicts

    // using namespace first;

    // // int x = 0;

    // std::cout << x;
    // std::cout << first::x;
    // std::cout << second::x;

    using std::cout;
    using std::string;

    string name = "Myself";
    cout << "Hello " << name;

    return 0;
}