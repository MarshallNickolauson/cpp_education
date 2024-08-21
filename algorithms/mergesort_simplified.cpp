#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

void mergeSort(std::vector<long long> &array, long long start, long long end);
void merge(std::vector<long long> &array, long long start, long long mid, long long end);

int main() {

    // Merge Sort Algorithm for 1_000_000 random numbers: 0.315168 seconds
    // Remember, Bubble Sort at 1_000_000 random numbers would take about 2 minutes :)

    srand(time(NULL));
    long long size = 1000000;
    std::vector<long long> array(size);

    for(long long i = 0; i < size; i++) {
        array[i] = (rand() % size) + 1;
    }

    auto start = std::chrono::high_resolution_clock::now();

    mergeSort(array, 0, size - 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "Merge Sort for " << size << " elements: " << duration.count() << " seconds" << endl;

    // cout << "Sorted Array:" << endl;
    // for(int i = 0; i < size; i++) {
    //     cout << array[i] << ' ';
    // }
    // cout << endl;

    return 0;
}

void mergeSort(std::vector<long long> &array, long long start, long long end) {
    if(start < end) {
        long long mid = start + (end - start) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void merge(std::vector<long long> &array, long long start, long long mid, long long end) {
    long long leftArraySize = mid - start + 1;
    long long rightArraySize = end - mid;

    std::vector<long long> leftArray(leftArraySize);
    std::vector<long long> rightArray(rightArraySize);

    for(long long i = 0; i < leftArraySize; i++)
        leftArray[i] = array[start + i];

    for(long long i = 0; i < rightArraySize; i++)
        rightArray[i] = array[mid + 1 + i];

    long long i = start, l = 0, r = 0;

    while(l < leftArraySize && r < rightArraySize) {
        if(leftArray[l] <= rightArray[r]) {
            array[i++] = leftArray[l++];
        } else {
            array[i++] = rightArray[r++];
        }
    }

    while(l < leftArraySize) {
        array[i++] = leftArray[l++];
    }

    while(r < rightArraySize) {
        array[i++] = rightArray[r++];
    }
}