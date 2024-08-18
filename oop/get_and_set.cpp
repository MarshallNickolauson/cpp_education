#include <iostream>

class Stove {
    private:
        int temperature = 0;

    public:
    
        Stove() {}

        Stove(int temperature) {
            setTemperature(temperature);
        }
        
        int getTemperature() {
            return temperature;
        }
        
        void setTemperature(int temperature) {
            if (temperature < 0) {
                this->temperature = 0;
            } else if (temperature >= 450) {
                this->temperature = 450;
            } else {
                this->temperature = temperature;
            }
        }
};

int main() {

    Stove stove(10);
    std::cout << stove.getTemperature();

    return 0;
}