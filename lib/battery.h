/**
 * Battery interface
 *
 * This file contains functions for reading the battery level.
 *
 * Note that the battery level is not simulated at the moment, so this module
 * it's not functional at the moment.
 */

#ifndef BATTERY_H
#define BATTERY_H

#include "mem.h"

/// @brief Obtains the remaining battery energy.
/// @return The remaining battery energy.
uint32_t battery_energy();

#endif // BATTERY_H