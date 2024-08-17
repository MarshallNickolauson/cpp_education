#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    // Bubble sort - O(N^2) time

    int arraySize = 10000;
    double array[arraySize];
    srand(time(NULL));

    for(int i = 0; i < arraySize; i++) {
        array[i] = (rand() % arraySize) + 1;
    }

    auto start1 = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < arraySize; i++) {
        for(int j = 0; j < arraySize - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;

    cout << "Bubble Sort for " << arraySize << " elements: " << duration1.count() << " seconds\n";

    // for(double i : array) {
    //     cout << i << ' ';
    // }

    return 0;
}