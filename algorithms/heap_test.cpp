#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {

    // CAUTION**********************
    // Uses 16GB of RAM ******************************************
    
    long long size = 10000000000;
    
    long long *p_numbers = nullptr;

    p_numbers = new long long[size];

    for(int i = 0; i < size; i++) {
        p_numbers[i] = i;
    }

    cout << "Array filled" << endl;

    delete[] p_numbers;
    
    return 0;
}