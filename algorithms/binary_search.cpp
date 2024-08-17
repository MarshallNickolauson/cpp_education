#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using std::cout;

void binary_search(long long low, long long high, long long numToGuess, int tries) { 
    long long guess = low + (high - low) / 2;

    if(guess < numToGuess) {
        binary_search(guess + 1, high, numToGuess, tries + 1);
    } else if (guess > numToGuess) {
        binary_search(low, guess - 1, numToGuess, tries + 1);
    } else {
        cout << "Guessed in " << tries << " tries" << '\n';
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

        Random number set to: 5678944573567894
        Guessed in 57 tries
        Binary Search: 0.0002766 seconds
        Estimated Linear Search: 1865767.8328279415 seconds
        Estimated Linear Search: 31096.1305471324 minutes
        Estimated Linear Search: 518.2688424522 hours
        Estimated Linear Search: 21.5945351022 days
    */

    long long numToGuess;
    long long range = 1000000000000000000LL;

    srand(time(NULL));
    // numToGuess = (rand() % range) + 1;
    numToGuess = 5678944573567894;

    auto start1 = std::chrono::high_resolution_clock::now();

    cout << "Random number set to: " << numToGuess << '\n';

    binary_search(0, range, numToGuess, 1);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;

    cout << "Binary Search: " << duration1.count() << " seconds\n";

    //////////////////////////////////////////////////////////////////

    auto start2 = std::chrono::high_resolution_clock::now();

    int counter;
    long long placeholderNumber = 1000000000;
    for(int i = 0; i <= placeholderNumber; i++) {
        counter++;
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;

    //long long estimatedRealTime = numToGuess / ?? to get the time of duration2 and divide it against the number to guess with the placeholderNumber

    double estimatedRealTime = (duration2.count() * static_cast<double>(numToGuess)) / static_cast<double>(placeholderNumber);

    cout << std::fixed << std::setprecision(10);
    cout << "Estimated Linear Search: " << estimatedRealTime << " seconds\n";
    cout << "Estimated Linear Search: " << (estimatedRealTime / 60) << " minutes\n";
    cout << "Estimated Linear Search: " << (estimatedRealTime / 60 / 60) << " hours\n";
    cout << "Estimated Linear Search: " << (estimatedRealTime / 60 / 60 / 24) << " days\n";

    return 0;
}

