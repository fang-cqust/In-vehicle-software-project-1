#include <string>
#ifndef GYROSCOPE_H
#define GYROSCOPE_H

struct Gyroscope {
    std::string model;
    std::string manufacturer;

    Gyroscope();
};

#endif // GYROSCOPE_H