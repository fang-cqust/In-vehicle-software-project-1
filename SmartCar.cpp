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
    student(student) // ʹ�ô����ѧ������
{
    // Initialize tires
    chassis.tires = { "��·��", "�����ķ��", "��·��", "�����ķ��" };
}