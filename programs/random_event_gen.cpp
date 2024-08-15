#include <iostream>
#include <ctime>

int main() {

    //useful for games to trigger events randomly

    srand(time(0));
    int randNum = (rand() % 5) + 1;

    switch(randNum) {
        case 1: std::cout << "You win a bumper sticker!"; break;
        case 2: std::cout << "You win a bumper!"; break;
        case 3: std::cout << "You win a!"; break;
        case 4: std::cout << "You win!"; break;
        case 5: std::cout << "You!"; break;
    }

    return 0;
}