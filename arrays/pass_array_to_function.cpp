#include <iostream>

double getTotal(double prices[], int size);

int main() {

    double prices[] = {49.99, 15.05, 75.00, 9.99};
    int size = sizeof(prices)/sizeof(prices[0]);
    double total = getTotal(prices, size);

    std::cout << total;

    return 0;
}

// When an array is passed to a function, it decays into a pointer
// The function doesn't know the size of the array

double getTotal(double prices[], int size) {
    double sum = 0;
    
    for(int i = 0; i < size; i++) {
        sum += prices[i];
    }

    return sum;
}