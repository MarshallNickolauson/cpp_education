#include <iostream>
#include <stack>
#include <string>

std::string reverse(const std::string &inputString) {
    std::stack<char> charStack;
    std::string result;

    for (char c : inputString) {
        charStack.push(c);
    }

    while (!charStack.empty()) {
        result += charStack.top();
        charStack.pop();
    }

    return result;
}

int main() {

    std::string original = "Marshall";
    std::string reversed = reverse(original);

    std::cout << "Original: " << original << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;

    return 0;
}