#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;


void merge(int array[], int start, int mid, int end) {
    cout << "Merging: ";
    for (int i = start; i <= end; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = array[start + i];
    for (int i = 0; i < n2; i++)
        rightArray[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    cout << "Merged: ";
    for (int i = start; i <= end; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void mergeSort(int array[], int start, int end) {
    
    cout << "Splitting: ";

    for(int i = start; i <= end; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    
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
    
    mergeSort(array, start, end)
        if(start < end)
            midPoint = (end - start) / 2 + start
            mergeSort(array, start, midpoint)                 
            mergeSort(array midpoint + 1, end)               
            merge(array, start, midpoint, end)

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

    Splitting: 7 3 9 1 
    Splitting: 7 3
    Splitting: 7
    Splitting: 3
    Splitting: 7
    Splitting: 3
    Merging: 7 3
    Merged: 3 7
    Splitting: 9 1
    Splitting: 9
    Splitting: 1
    Splitting: 7
    Splitting: 3
    Splitting: 7
    Splitting: 7
    Splitting: 3
    Splitting: 7
    Splitting: 3
    Merging: 7 3
    Merged: 3 7
    Splitting: 9 1
    Splitting: 9
    Splitting: 1
    Merging: 9 1
    Merged: 1 9
    Merging: 3 7 1 9
    Merged: 1 3 7 9
    Sorted Array: 1 3 7 9

    */

    // int array[] = {7, 15, 14, 5, 9, 18, 3, 21, 12};
    int array[] = {7, 3, 9, 1};
    int size = sizeof(array)/sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;


    return 0;
}