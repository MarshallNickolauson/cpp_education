#include <iostream>

int main() {

    // break = break out of a loop
    // continue = skip current loop iteration

    for (int i = 1; i <= 20; i++) {
        if (i == 13) {
            continue; // skips 13, prints rest
        }
        std::cout << i << '\n';
    }

    return 0;
}