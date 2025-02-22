#include "mem.h"
#include "battery.h"

/// @details
/// Since battery is not simulated at the moment, this function doesn't come
/// useful.
uint32_t battery_energy()
{
    return rdi(MEM_BATTERY, 0);
}