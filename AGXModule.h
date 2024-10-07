#include <string>
#ifndef AGXMODULE_H
#define AGXMODULE_H

struct AGXModule {
    std::string model;
    int ai;
    int cudaCores;
    int tensorCores;
    int memory;
    int storage;

    AGXModule();
};

#endif // AGXMODULE_H