#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    /*
    
    Bubble Sort idea:
    1. If array[0] > array [1], swap
    2. If array [1] > array [2], swap
    3. Repeat until no swaps
    4. Repeat at beginning
    
    */

    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array)/sizeof(array[0]);

    // Swap logic
    // if(array[0] > array[0 + 1]) {
    //     int temp = array[0+1];
    //     array[0+1] = array[0];
    //     array[0] = temp;
    // }

    // Single element bubble sort
    // for(int j = 0; j < size - 1; j++) {
    //     if(array[j] > array[j + 1]) {
    //         int temp = array[j+1];
    //         array[j+1] = array[j];
    //         array[j] = temp;
    //     }
    // }

    // Repeat over entire array
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int i : array) {
        cout << i << ' ';
    }

    return 0;
}