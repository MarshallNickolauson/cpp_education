#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;


void merge(int array[], int start, int mid, int end) {
    // cout << "Merging: ";
    // for (int i = start; i <= end; i++) {
    //     cout << array[i] << " ";
    // }
    // cout << endl;

    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArray[leftSize], rightArray[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[start + i];
    }
        
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = start, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] <= rightArray[r]) {
            array[i] = leftArray[l];
            l++;
        } else {
            array[i] = rightArray[r];
            r++;
        }
        i++;
    }

    while (l < leftSize) {
        array[i] = leftArray[l];
        l++;
        i++;
    }

    while (r < rightSize) {
        array[i] = rightArray[r];
        r++;
        i++;
    }

    // cout << "Merged: ";
    // for (int i = start; i <= end; i++) {
    //     cout << array[i] << " ";
    // }
    // cout << endl;
}

void mergeSort(int array[], int start, int end) {
    
    // cout << "Splitting: ";

    // for(int i = start; i <= end; i++) {
    //     std::cout << array[i] << ' ';
    // }
    // std::cout << std::endl;
    
    if (start < end) {
        int midPoint = (end - start) / 2 + start;
        mergeSort(array, start, midPoint);
        mergeSort(array, midPoint + 1, end);
        merge(array, start, midPoint, end);
    }
}

int main() {

    // Merge Sort
    // 1. Split the array in the middle
    // 2. Recursively sort each part separately
    // 3. Merge the two sorted parts together

    /*

    Merge Sort for 100000 elements: 0.011116

    Visualization of Merge Sort with Depth-First Approach:

            [7, 3, 9, 1]
               /   \
            /          \
        [7, 3]         [9, 1]         <-- Split the array in half
        /   \           /   \
      [7]   [3]       [9]   [1]       <-- Further split until single-element subarrays
        \   /           \   /
        [3, 7]         [1, 9]         <-- Merge sorted subarrays
             \          /
            [1, 3, 7, 9]             <-- Final merge for the sorted array

    Left Array     : 8 | 2 : Right Array
    Building Array : 2
    Final Array    : 2 8

    Left Array     : 5 | 3 : Right Array
    Building Array : 3
    Final Array    : 3 5

    Left Array     : 2 8 | 3 5 : Right Array
    Building Array : 2
    Building Array : 2 3
    Building Array : 2 3 5
    Final Array    : 2 3 5 8

    Left Array     : 4 | 7 : Right Array
    Building Array : 4
    Final Array    : 4 7

    Left Array     : 6 | 1 : Right Array
    Building Array : 1
    Final Array    : 1 6

    Left Array     : 4 7 | 1 6 : Right Array
    Building Array : 1
    Building Array : 1 4
    Building Array : 1 4 6
    Final Array    : 1 4 6 7

    Left Array     : 2 3 5 8 | 1 4 6 7 : Right Array
    Building Array : 1
    Building Array : 1 2
    Building Array : 1 2 3
    Building Array : 1 2 3 4
    Building Array : 1 2 3 4 5
    Building Array : 1 2 3 4 5 6
    Building Array : 1 2 3 4 5 6 7
    Final Array    : 1 2 3 4 5 6 7 8

    Sorted Array: 1 2 3 4 5 6 7 8

    */

    // int array[] = {7, 15, 14, 5, 9, 18, 3, 21, 12};
    // int array[] = {7, 3, 9, 1};
    // int size = sizeof(array)/sizeof(array[0]);

    int size = 100000;
    int array[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = ((rand() % size) + 1);
    }

    auto start = std::chrono::high_resolution_clock::now();

    mergeSort(array, 0, size - 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Merge Sort for " << size << " elements: " << duration.count() << endl;

    // cout << "Sorted Array: ";
    // for (int i = 0; i < size; i++) {
    //     cout << array[i] << " ";
    // }
    // cout << endl;

    return 0;
}