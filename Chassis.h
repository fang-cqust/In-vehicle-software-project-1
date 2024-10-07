#ifndef CHASSIS_H
#define CHASSIS_H

#include <string>
#include <vector>

struct Chassis {
    std::string id;
    std::string model;
    float wheelBase;
    float trackWidth;
    float groundClearance;
    float turningRadius;
    std::string driveType;
    float maxRange;
    std::vector<std::string> tires;

    Chassis();
};

#endif // CHASSIS_H