#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    /*
    The selection sort algorithm sorts an array by repeatedly finding the minimum element 
    (considering ascending order) from unsorted part and putting it at the beginning. 
    The algorithm maintains two subarrays in a given array.

    - The subarray which is already sorted. 
    - Remaining subarray which is unsorted.

    In every iteration of selection sort, the minimum element (considering ascending order) 
    from the unsorted subarray is picked and moved to the sorted subarray.
    */

    // so even using heaps it doesn't take up THAT much memory

    int size = 100000;
    int *p_array = nullptr;
    p_array = new int[size];

    srand(time(NULL));

    for(int i = 0; i < size; i++) {
        p_array[i] = (rand() % size) + 1;
    }

    long long swapCounter = 0;

    int *p_temp = nullptr;
    p_temp = new int;

    auto start1 = std::chrono::high_resolution_clock::now();

    /*

    Swapping every single one:
        int size = 100000;
        2497835211 swaps
        15.5282 seconds

    */
    // for(int i = 0; i < size - 1; i++) {
    //     int min_index = i;
    //     for (int j = i+1; j < size; j++) {
    //         if (p_array[j] < p_array[min_index]) {
    //             *p_temp = p_array[i];
    //             p_array[i] = p_array[min_index];
    //             p_array[min_index] = *p_temp;
    //             swapCounter++;
    //         }
    //     }
    // }

    /*

    Swapping only minimum index:
        int size = 100000;
        99999 swaps
        3.48438 seconds

    */

    for(int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if (p_array[j] < p_array[min_index]) {
                min_index = j;
            }
        }

        *p_temp = p_array[i];
        p_array[i] = p_array[min_index];
        p_array[min_index] = *p_temp;
        swapCounter++;
    }

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;

    delete p_temp;
    delete[] p_array;

    cout << swapCounter << " swaps" << endl;
    cout << duration1.count() << " seconds" << endl;

    return 0;
}