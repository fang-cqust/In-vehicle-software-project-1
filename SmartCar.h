#ifndef SMARTCAR_H
#define SMARTCAR_H

#include "Chassis.h"
#include "AGXModule.h"
#include "DualCamera.h"
#include "Lidar.h"
#include "Gyroscope.h"
#include "Display.h"
#include "BatteryModule.h"
#include "Student.h"
#include <string>
#include <vector>

struct SmartCar {
    std::string id;
    Chassis chassis;
    AGXModule agxModule;
    DualCamera dualCamera;
    Lidar lidar;
    Gyroscope gyroscope;
    Display display;
    BatteryModule batteryModule;
    Student student;

    // ¹¹Ôìº¯Êý
    SmartCar(const std::string& id, const Student& student);
};

#endif // SMARTCAR_H