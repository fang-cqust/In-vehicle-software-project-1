#include "Chassis.h"
#include <random>
#include <ctime>

Chassis::Chassis() :
    id("dp" + std::string(8, '0')), // Initialize with default id
    model("SCOUT MINI"),
    wheelBase(451),
    trackWidth(490),
    groundClearance(115),
    turningRadius(0),
    driveType("四轮四驱"),
    maxRange(10) {
    tires = { "公路轮", "麦克纳姆轮", "公路轮", "麦克纳姆轮" };

    // Randomize the chassis ID
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('A', 'Z');
    for (char& c : id) {
        if (c == '0') c = dis(gen);
    }
}