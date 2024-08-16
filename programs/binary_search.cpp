#include <iostream>
#include <ctime>
#include <chrono>

using std::cout;

void binary_search(long long low, long long high, long long numToGuess, int tries) { 
    cout << "Low: " << low << '\n';
    cout << "High: " << high << '\n';
    cout << "Number to Guess: " << numToGuess << '\n';
    cout << "Tries: " << tries << '\n';

    long long guess = low + (high - low) / 2;
    cout << "Guess: " << guess << '\n';
    if(guess < numToGuess) {
        binary_search(guess + 1, high, numToGuess, tries + 1);
    } else if (guess > numToGuess) {
        binary_search(low, guess - 1, numToGuess, tries + 1);
    } else {
        cout << "Guessed!" << '\n';
        cout << guess << '\n';
    }
}

int main() {

    /*
        Number to Guess: 5678944573567894
        Tries: 57
        Guess: 5678944573567894
        Guessed!
        5678944573567894
        Time taken: 0.0188366 seconds - BRO WHAT
    */

    long long numToGuess;
    long long range = 1000000000000000000LL;

    srand(time(NULL));
    // numToGuess = (rand() % range) + 1;
    numToGuess = 5678944573567894;

    auto start = std::chrono::high_resolution_clock::now();

    cout << "##### Random number set to: " << numToGuess << '\n';

    binary_search(0, range, numToGuess, 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    cout << "Time taken: " << duration.count() << " seconds\n";

    return 0;
}