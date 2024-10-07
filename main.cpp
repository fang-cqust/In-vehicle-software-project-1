#include "CarManager.h"
#include <iostream>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    CarManager manager;
    manager.saveToFile("smartcars.txt");
    manager.loadFromFile("smartcars.txt");
    manager.displayCars();
    return 0;
}