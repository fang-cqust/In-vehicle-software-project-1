#include "DualCamera.h"

DualCamera::DualCamera() :
    model("RealSense D435i"),
    cameraType("D430"),
    resolutionWidth(1920),
    resolutionHeight(1080),
    rgbFrameRate(30),
    fovHorizontal(87),
    fovVertical(58),
    depthFrameRate(90) {}
