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

    int swapCounter = 0;

    int *p_temp = nullptr;
    p_temp = new int;

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

    delete p_temp;
    delete[] p_array;

    // for(int i = 0; i < size; i++) {
    //     cout << p_array[i] << ' ';
    // }
    // cout << '\n';

    cout << swapCounter << " swaps" << endl;

    return 0;
}