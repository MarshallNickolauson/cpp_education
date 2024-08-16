#include <iostream>
#include <ctime>

using std::cout;

int main() {

    int num;
    int guess;
    int tries;

    int range = 1000;

    srand(time(NULL));
    num = (rand() % range) + 1;

    cout << "##### Random number set to: " << num << '\n';

    guess = (rand() % range) + 1;
    if (guess > num) {
        cout << "Guess was " << guess << ". Go lower.";
    } else if (guess < num) {
        cout << "Guess was " << guess << ". Go higher.";
    } else {
        cout << "Guessed it right!";
    }

    // The above works. Finish when you learn about functions so you can call it recursively.

    return 0;
}