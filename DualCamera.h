#include <string>
#ifndef DUALCAMERA_H
#define DUALCAMERA_H

struct DualCamera {
    std::string model;
    std::string cameraType;
    int resolutionWidth;
    int resolutionHeight;
    int rgbFrameRate;
    int fovHorizontal;
    int fovVertical;
    int depthFrameRate;

    DualCamera();
};

#endif // DUALCAMERA_H
