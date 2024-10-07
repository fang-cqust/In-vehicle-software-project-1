#ifndef CARMANAGER_H
#define CARMANAGER_H

#include "SmartCar.h"
#include <vector>
#include <string>

struct CarManager {
    std::vector<SmartCar> cars;
    std::vector<Student> students;
    int currentCarIndex;

    CarManager();
    void createSmartCars();
    std::vector<Student> createStudents(); 
    void assignStudents();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void displayCars();
    void displayCar(const SmartCar& car);
    std::string generateRandomID(const std::string& prefix, int length);
};

#endif // CARMANAGER_H