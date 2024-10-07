#include "AGXModule.h"

AGXModule::AGXModule() :
    model("AGX Xavier"),
    ai(32),
    cudaCores(512),
    tensorCores(64),
    memory(32),
    storage(32) {}