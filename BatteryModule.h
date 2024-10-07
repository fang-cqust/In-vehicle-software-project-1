#include <string>
#ifndef BATTERYMODULE_H
#define BATTERYMODULE_H

struct BatteryModule {
    std::string voltage;
    std::string capacity;
    std::string supplyVoltage;
    float chargeTime;

    BatteryModule();
};

#endif // BATTERYMODULE_H