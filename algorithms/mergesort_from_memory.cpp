#include <iostream>

void mergesort(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);

using namespace std;

int main() {

    int array[] = {10, 12, 4, 7, 2, 4, 9, 17, 3, 55, 2, 8, 72};
    int size = sizeof(array)/sizeof(array[0]);

    mergesort(array, 0, size - 1);

    for(int i : array) {
        cout << i << ' ';
    }

    return 0;
}

void mergesort(int array[], int start, int end) {
    if(start < end) {
        int mid = (end - start) / 2 + start;
        mergesort(array, start, mid);
        mergesort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void merge(int array[], int start, int mid, int end) {
    //left and right array sizes
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    //left and right array init
    int leftArray[leftSize], rightArray[rightSize];

    //populate arrays
    for(int i = 0; i < leftSize; i++) {
        leftArray[i] = array[start + i];
    }

    for(int i = 0; i < rightSize; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    //init pointers
    int i = start, l = 0, r = 0;

    //sort and merge with the pointers
    while(l < leftSize && r < rightSize) {
        if(leftArray[l] <= rightArray[r]) {
            array[i++] = leftArray[l++];
        } else {
            array[i++] = rightArray[r++];
        }
    }

    while(l < leftSize) {
        array[i++] = leftArray[l++];
    }

    while(r < rightSize) {
        array[i++] = rightArray[r++];
    }

}