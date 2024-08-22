#include <iostream>

using namespace std;

void mergeSort(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);

int main() {

    int array[] = {8, 5, 9, 3, 6, 2, 10, 1, 4, 7, 22, 35, 12};
    int size = sizeof(array)/sizeof(array[0]);

    mergeSort(array, 0, size - 1);

    for(int i : array) {
        cout << i << ' ';
    }
    cout << endl;
}

void mergeSort(int array[], int start, int end) {
    if(start < end) {
        int mid = (end - start) / 2 + start;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void merge(int array[], int start, int mid, int end) {
    //left and right sizes
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    //init left and right arrays
    int leftArray[leftSize], rightArray[rightSize];
    
    //populate arrays
    for(int i = 0; i < leftSize; i++) {
        leftArray[i] = array[start + i];
    }

    for(int i = 0; i < rightSize; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    //init merge pointers
    int i = start, l = 0, r = 0;

    //populate main array with left and right arrays (sorted)
    while(l < leftSize && r < rightSize) {
        if(leftArray[l] <= rightArray[r]) {
            array[i++] = leftArray[l++];
        } else {
            array[i++] = rightArray[r++];
        }
    }

    //add leftovers
    while(l < leftSize) {
        array[i++] = leftArray[l++];
    }

    while(r < rightSize) {
        array[i++] = rightArray[r++];
    }
}