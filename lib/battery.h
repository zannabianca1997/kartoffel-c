#ifndef BATTERY_H
#define BATTERY_H

#include "lib.h"

// Returns the remaining battery energy
// not simulated at the moment
inline static uint32_t battery_energy() {
    return rdi(MEM_BATTERY, 0);
}

#endif // BATTERY_H
