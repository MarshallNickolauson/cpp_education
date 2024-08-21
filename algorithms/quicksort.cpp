#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cstdlib>

// UNOPTIMIZED - Stack overflow past 9999 elements
// Quicksort for 9999 elements: 0.10278 seconds 

int partition(int array[], int start, int end);
void quicksort(int array[], int start, int end);

int main() {

    srand(time(NULL));

    int size = 9999;
    int array[size];

    // Fill the first half with random numbers
    for(int i = 0; i < size / 2; i++) {
        array[i] = (rand() % (size / 2)) + 1;
    }

    // Fill the second half with sequential numbers
    for(int i = size / 2; i < size; i++) {
        array[i] = i + 1;
    }

    auto start1 = std::chrono::high_resolution_clock::now();

    quicksort(array, 0, size - 1);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;

    std::cout << "Quicksort for " << size << " elements: " << duration1.count() << " seconds" << std::endl   ;

    return 0;
}

int partition(int array[], int start, int end) {
    int pivot = array[end];
    int x = start - 1;
    for(int i = start; i < end; i++) {
        if(array[i] < pivot) {
            x++;
            std::swap(array[i], array[x]);
        }
    }
    
    std::swap(array[x+1], array[end]);
    return x + 1;
}

void quicksort(int array[], int start, int end) {
    if(start < end) {
        int p = partition(array, start, end);
        quicksort(array, start, p - 1);
        quicksort(array, p + 1, end);
    }
}