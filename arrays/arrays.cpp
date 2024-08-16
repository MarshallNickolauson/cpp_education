#include <iostream>

int main() {
    // array = a data structure that can hold multiple values
    //         values are accessed by an index number
    //         "A variable that holds multiple values"
    
    // CAN ONLY CONTAIN VALUES OF THE SAME DATA TYPE
    // MUST SET ARRAY SIZE IF YOU ASSIGN VALUES LATER

    std::string cars[3];

    cars[0] = "Camero";
    
    std::cout << cars[0];

    return 0;
}