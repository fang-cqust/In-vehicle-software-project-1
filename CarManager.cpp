#include "CarManager.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <set>

using namespace std;

CarManager::CarManager() : currentCarIndex(0) {
    createSmartCars();
    students = createStudents();
    assignStudents();
}

void CarManager::createSmartCars() {
    vector<string> carIds = {
        "cqusn1A2b3C4d5E",
        "cqusn6F7g8H9i0J1K",
        "cqusn2L3m4N5o6P7Q",
        "cqusn8R9s0T1u2V3W",
        "cqusn0D1e2F3g4H5i",
        "cqusn6J7k8L9m0N1o",
        "cqusn2P3q4R5s6T7u",
        "cqusn8V9w0X1y2Z3a",
        "cqusn4B5c6D7e8F9g0H",
        "cqusn5G6h7J8k9L0m1N"
    };
    for (const auto& carId : carIds) {
        cars.emplace_back(SmartCar(carId, Student("", ""))); // 使用默认学生信息
    }
}

vector<Student> CarManager::createStudents() {
    vector<Student> students;
    vector<string> names = {
        "张伟", "李娜", "王芳", "赵雷", "刘洋",
        "陈静", "杨明", "周敏", "吴强", "郑洁"
    };
    vector<string> ids = {
        "1234567", "7654321", "3579246", "8527364", "4793625",
        "9631742", "2856413", "6385271", "5914728", "7429653"
    };
    for (size_t i = 0; i < names.size(); ++i) {
        students.emplace_back(Student(ids[i], names[i]));
    }
    return students;
}

void CarManager::assignStudents() {
    for (size_t i = 0; i < cars.size(); ++i) {
        cars[i].student = students[i];
    }
}

string CarManager::generateRandomID(const string& prefix, int length) {
    static const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string id;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, characters.size() - 1);
    for (int i = 0; i < length; ++i) {
        id += characters[distrib(gen)];
    }
    return prefix + id;
}

void CarManager::saveToFile(const string& filename) {
    ofstream file(filename);
    for (const auto& car : cars) {
        file << "Car ID: " << car.id << endl;
        file << "Chassis：" << endl;
        file << "\t" << "Chassis ID: " << car.chassis.id << endl;
        file << "\t" << "Chassis model: " << car.chassis.model << endl;
        file << "\t" << "Chassis wheelBase: " << car.chassis.wheelBase << endl;
        file << "\t" << "Chassis trackWidth: " << car.chassis.trackWidth << endl;
        file << "\t" << "Chassis groundClearance: " << car.chassis.groundClearance << endl;
        file << "\t" << "Chassis turningRadius: " << car.chassis.turningRadius << endl;
        file << "\t" << "Chassis driveType: " << car.chassis.driveType << endl;
        file << "\t" << "Chassis maxRange: " << car.chassis.maxRange << endl;
        file << "AGX 套件：" << endl;
        file << "\t" << "AGX Model: " << car.agxModule.model << endl;
        file << "\t" << "AGX AI: " << car.agxModule.ai << endl;
        file << "\t" << "AGX CUDA: " << car.agxModule.cudaCores << endl;
        file << "\t" << "AGX tensorCores: " << car.agxModule.tensorCores << endl;
        file << "\t" << "AGX memory: " << car.agxModule.memory << endl;
        file << "\t" << "AGX storage: " << car.agxModule.storage << endl;
        file << "DualCamera：" << endl;
        file << "\t" << "Camera Model: " << car.dualCamera.model << endl;
        file << "\t" << "Camera cameraType: " << car.dualCamera.cameraType << endl;
        file << "\t" << "Camera resolutionWidth: " << car.dualCamera.resolutionWidth << endl;
        file << "\t" << "Camera resolutionHeight: " << car.dualCamera.resolutionHeight << endl;
        file << "\t" << "Camera rgbFrameRate: " << car.dualCamera.rgbFrameRate << endl;
        file << "\t" << "Camera fovHorizontal: " << car.dualCamera.fovHorizontal << endl;
        file << "\t" << "Camera depthFrameRate: " << car.dualCamera.depthFrameRate << endl; \
        file << "\t" << "Camera fovVertical: " << car.dualCamera.fovVertical << endl;
        file << "Lidar Model: " << endl;
        file << "\t" << "Lidar Model: " << car.lidar.model << endl;
        file << "\t" << "Lidar channelCount: " << car.lidar.channelCount << endl;
        file << "\t" << "Lidar range: " << car.lidar.range << endl;
        file << "\t" << "Lidar powerConsumption: " << car.lidar.powerConsumption << endl;
        file << "Gyroscope: " << endl;
        file << "Gyroscope Model: " << car.gyroscope.model << endl;
        file << "Gyroscope manufacturer: " << car.gyroscope.manufacturer << endl;
        file << "Display: " << car.display.size << endl;
        file << "\t" << "Display Size: " << car.display.size << endl;
        file << "\t" << "Display model: " << car.display.size << endl;
        file << "\t" << "Battery:" << endl;
        file << "\t" << "Battery Voltage: " << car.batteryModule.voltage << endl;
        file << "\t" << "Battery capacity: " << car.batteryModule.capacity << endl;
        file << "\t" << "Battery supplyVoltage: " << car.batteryModule.supplyVoltage << endl;
        file << "\t" << "Battery chargeTime: " << car.batteryModule.chargeTime << endl;
        file << "Student Name: " << car.student.name << endl;
        file << "--------------------------" << endl;
    }
    file.close();
}

void CarManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    string carId;
    while (file >> carId) {
        cars.emplace_back(SmartCar(carId, Student("", ""))); // 使用默认学生信息
    }
    file.close();
}

void CarManager::displayCars() {
    if (cars.empty()) {
        cout << "No cars to display." << endl;
        return;
    }

    char command;
    bool exitLoop = false;
    currentCarIndex = 0;
    bool allCarsDisplayed = false;

    int count = 0;
    while (!exitLoop && count < 10) {
        if (currentCarIndex >= cars.size()) {
            if (!allCarsDisplayed) {
                cout << "All cars have been displayed." << endl;
                allCarsDisplayed = true;
            }
            else {
                cout << "Vehicle allocation information has been fully displayed." << endl;
                cout << "Please enter 'p' to view a car's information or 'q' to quit: ";
            }
        }
        else {
            displayCar(cars[currentCarIndex]);
            if (currentCarIndex == cars.size() - 1) {
                allCarsDisplayed = true;
            }
        }

        cout << "Press 'n' for next car, 'p' for previous car, or 'q' to quit: ";
        cin >> command;
        cin.ignore(); 

        switch (command) {
        case 'n':
            if (allCarsDisplayed) {
                cout << "All cars have been displayed. Please enter 'p' or 'q'." << endl;
            }
            else if (currentCarIndex < cars.size() - 1) {
                currentCarIndex++;
                count++;
            }
            else {
                cout << "Already at the last car." << endl;
            }
            break;
        case 'p':
            if (currentCarIndex > 0) {
                currentCarIndex--;
            }
            else {
                cout << "Already at the first car." << endl;
            }
            break;
        case 'q':
            exitLoop = true;
            break;
        default:
            cout << "Invalid command." << endl;
            break;
        }
    }

    cout << "All cars have been displayed. Please enter 'p' or 'q'." << endl;
}


    void CarManager::displayCar(const SmartCar & car) {
        cout << "Car ID: " << car.id << endl;
        cout << "Chassis：" << endl;
        cout << "\t" << "Chassis ID: " << car.chassis.id << endl;
        cout << "\t" << "Chassis model: " << car.chassis.model << endl;
        cout << "\t" << "Chassis wheelBase: " << car.chassis.wheelBase << endl;
        cout << "\t" << "Chassis trackWidth: " << car.chassis.trackWidth << endl;
        cout << "\t" << "Chassis groundClearance: " << car.chassis.groundClearance << endl;
        cout << "\t" << "Chassis turningRadius: " << car.chassis.turningRadius << endl;
        cout << "\t" << "Chassis driveType: " << car.chassis.driveType << endl;
        cout << "\t" << "Chassis maxRange: " << car.chassis.maxRange << endl;
        cout << "AGX 套件：" << endl;
        cout << "\t" << "AGX Model: " << car.agxModule.model << endl;
        cout << "\t" << "AGX AI: " << car.agxModule.ai << endl;
        cout << "\t" << "AGX CUDA: " << car.agxModule.cudaCores << endl;
        cout << "\t" << "AGX tensorCores: " << car.agxModule.tensorCores << endl;
        cout << "\t" << "AGX memory: " << car.agxModule.memory << endl;
        cout << "\t" << "AGX storage: " << car.agxModule.storage << endl;
        cout << "DualCamera：" << endl;
        cout << "\t" << "Camera Model: " << car.dualCamera.model << endl;
        cout << "\t" << "Camera cameraType: " << car.dualCamera.cameraType << endl;
        cout << "\t" << "Camera resolutionWidth: " << car.dualCamera.resolutionWidth << endl;
        cout << "\t" << "Camera resolutionHeight: " << car.dualCamera.resolutionHeight << endl;
        cout << "\t" << "Camera rgbFrameRate: " << car.dualCamera.rgbFrameRate << endl;
        cout << "\t" << "Camera fovHorizontal: " << car.dualCamera.fovHorizontal << endl;
        cout << "\t" << "Camera depthFrameRate: " << car.dualCamera.depthFrameRate << endl; \
        cout << "\t" << "Camera fovVertical: " << car.dualCamera.fovVertical << endl;
        cout << "Lidar Model: " << endl;
        cout << "\t" << "Lidar Model: " << car.lidar.model << endl;
        cout << "\t" << "Lidar channelCount: " << car.lidar.channelCount << endl;
        cout << "\t" << "Lidar range: " << car.lidar.range << endl;
        cout << "\t" << "Lidar powerConsumption: " << car.lidar.powerConsumption << endl;
        cout << "Gyroscope: " << endl;
        cout << "Gyroscope Model: " << car.gyroscope.model << endl;
        cout << "Gyroscope manufacturer: " << car.gyroscope.manufacturer << endl;
        cout << "Display: " << car.display.size << endl;
        cout << "\t" << "Display Size: " << car.display.size << endl;
        cout << "\t" << "Display model: " << car.display.size << endl;
        cout << "\t" << "Battery:" << endl;
        cout << "\t" << "Battery Voltage: " << car.batteryModule.voltage << endl;
        cout << "\t" << "Battery capacity: " << car.batteryModule.capacity << endl;
        cout << "\t" << "Battery supplyVoltage: " << car.batteryModule.supplyVoltage << endl;
        cout << "\t" << "Battery chargeTime: " << car.batteryModule.chargeTime << endl;
        cout << "Student ID: " << car.student.studentId << endl;
        cout << "Student Name: " << car.student.name << endl;
        cout << "--------------------------" << endl;
    }