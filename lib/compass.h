/**
 * Compass interface
 *
 * This file contains functions for reading the compass, obtaining the bot's
 * orientation.
 */

#include "types.h"

/// @brief Returns which direction the bot was facing at the time of the latest
/// measurement, and then removes that measurement from the compass.
///
/// @return 1 to 4 if the bot was facing north, east, south or west, or 0 if
/// the measurement is not ready yet.
uint32_t compass_dir();
