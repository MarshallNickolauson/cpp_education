#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    // Bubble sort - O(N^2) time

    /*
    
        Basic Bubble Sort for 100001 elements: 11.0239 seconds: 1410165408 checks
        Improved Bubble Sort for 100001 elements: 17.5521 seconds: 705082704 checks
        Most efficient Bubble Sort for 100001 elements: 0.0003694 seconds: 99999 checks
    
    */

    int size = 100001;
    int array1[size];
    int array2[size];
    int array3[size];
    int checks1 = 0;
    int checks2 = 0;
    int checks3 = 0;

    srand(time(NULL));

    for(int i = 0; i < size / 2; i++) {
        array1[i] = (rand() % size / 2) + 1;
        array1[i + (size / 2) + 1] = i + (size / 2) + 1;
        array2[i] = (rand() % size / 2) + 1;
        array2[i + (size / 2) + 1] = i + (size / 2) + 1;
        array3[i] = (rand() % size / 2) + 1;
        array3[i + (size / 2) + 1] = i + (size / 2) + 1;
    }

    //////////////// Most Basic Bubble Sort //////////////////////

    auto start1 = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            checks1++;
            if(array1[j] > array1[j + 1]) {
                std::swap(array1[j], array1[j+1]);
            }
        }
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;
    cout << "Basic Bubble Sort for " << size << " elements: " << duration1.count() << " seconds: " << checks1 << " checks\n";

    //////////////// Improved Bubble Sort //////////////////////

    auto start2 = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            checks2++;
            if(array2[j] > array2[j + 1]) {
                std::swap(array1[j], array1[j+1]);
            }
        }
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration2 = end2 - start2;
    cout << "Improved Bubble Sort for " << size << " elements: " << duration2.count() << " seconds: " << checks2 << " checks\n";

    //////////////// Most Efficient Bubble Sort //////////////////////

    auto start3 = std::chrono::high_resolution_clock::now();

    int i = 0;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        i++;
        for(int j = 0; j < size - i - 1; j++) {
            checks3++;
            if(array3[j] > array3[j + 1]) {
                std::swap(array1[j], array1[j+1]);
            }
        }
    }

    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration3 = end3 - start3;
    cout << "Most efficient Bubble Sort for " << size << " elements: " << duration3.count() << " seconds: " << checks3 << " checks\n";

    // for(int i : array) {
    //     cout << i << ' ';
    // }

    return 0;
}