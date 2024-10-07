#include "SmartCar.h"

SmartCar::SmartCar(const std::string& id, const Student& student) :
    id(id),
    chassis(),
    agxModule(),
    dualCamera(),
    lidar(),
    gyroscope(),
    display(),
    batteryModule(),
    student(student) // 使用传入的学生对象
{
    // Initialize tires
    chassis.tires = { "公路轮", "麦克纳姆轮", "公路轮", "麦克纳姆轮" };
}