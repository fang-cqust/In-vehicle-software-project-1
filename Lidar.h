#include <string>
#ifndef LIDAR_H
#define LIDAR_H

struct Lidar {
    std::string model;
    int channelCount;
    float range;
    float powerConsumption;

    Lidar();
};

#endif // LIDAR_H