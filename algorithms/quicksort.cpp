#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <vector>

// Quicksort for 100001 elements: 0.0086013 seconds 

long long partition(std::vector<long long>& array, long long start, long long end);
void quicksort(std::vector<long long>& array, long long start, long long end);

int main() {

    srand(time(NULL));

    long long size = 100001;
    std::vector<long long> array(size);

    for(long long i = 0; i < size; i++) {
        array[i] = (rand() % (size)) + 1;
    }

    auto start1 = std::chrono::high_resolution_clock::now();

    quicksort(array, 0, size - 1);

    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration1 = end1 - start1;

    std::cout << "Quicksort for " << size << " elements: " << duration1.count() << " seconds" << std::endl   ;

    return 0;
}

long long partition(std::vector<long long>& array, long long start, long long end) {
    long long pivot = array[end];
    long long x = start - 1;
    for(long long i = start; i < end; i++) {
        if(array[i] < pivot) {
            x++;
            std::swap(array[i], array[x]);
        }
    }
    
    std::swap(array[x+1], array[end]);
    return x + 1;
}

void quicksort(std::vector<long long>& array, long long start, long long end) {
    if(start < end) {
        long long p = partition(array, start, end);
        quicksort(array, start, p - 1);
        quicksort(array, p + 1, end);
    }
}