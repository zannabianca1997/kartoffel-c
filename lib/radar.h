/**
 * Radar interface
 *
 * This file contains functions for reading the radar.
 *
 * One can use the `radar_scan_*()` functions to launch a scan, and then use
 * `radar_scan_*_at()` functions to read the tile data. Moreover, one can use
 * `radar_scan_*_bot_at()` functions to read the id of eventual bots.
 *
 * Note that for performance reasons, those functions doesn't copy the scanned
 * area into your bot's RAM - rather, the data is kept inside the radar's
 * memory and transparently accessed each time you call `radar_scan_*_at()`
 * etc.
 *
 * In practice, this means that consecutive scans "overwrite" previous scans'
 * results, and only one of the `RadarScan*` structs must be kept in memory at
 * any given time.
 *
 * If you want full control over the scans, you can use the `radar_scan()` and
 * `radar_read()` functions directly by defining the `RADAR_H_LOW_LEVEL` macro
 * before including this file.
 */

#ifndef RADAR_H
#define RADAR_H

#include "types.h"

/// @brief Returns whether the radar is ready and `radar_scan()` can be invoked.
/// @return 1 if the radar is ready, 0 otherwise.
uint8_t is_radar_ready();

/// @brief Waits for the radar to become ready.
static inline void radar_wait()
{
    while (!is_radar_ready())
    {
        // Empty loop
    }
}

#ifdef RADAR_H_LOW_LEVEL

/// @brief Scans a square around the bot (Low-level function).
/// @param radius The radius of the scan.
void radar_scan(uint8_t radius);

/// @brief Reads data from the radar scan (Low-level function).
/// @param radius The radius of the scan.
/// @param dx The offset in the bot's direction.
/// @param dy The offset perpendicular to the bot's direction.
/// @param z What part of the data to read.
/// @return The scanned data.
uint32_t radar_read(uint8_t radius, int8_t dx, int8_t dy, uint8_t z);

#endif // RADAR_H_LOW_LEVEL

/// @brief Represents a 3x3 radar scan.
typedef struct RadarScan3x3 RadarScan3x3;

/// @brief Scans a 3x3 square around the bot.
/// @return The radar scan struct.
RadarScan3x3 *radar_scan_3x3();

/// @brief Returns the tile at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The tile at given coordinates.
uint8_t radar_scan_3x3_at(const RadarScan3x3 *scan, int8_t dx, int8_t dy);

/// @brief Returns the bot id at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The bot id at given coordinates, or 0 if there's no bot there.
uint64_t radar_scan_3x3_bot_at(const RadarScan3x3 *scan, int8_t dx, int8_t dy);

/// @brief Represents a 5x5 radar scan.
typedef struct RadarScan5x5 RadarScan5x5;

/// @brief Scans a 5x5 square around the bot.
/// @return The radar scan struct.
RadarScan5x5 *radar_scan_5x5();

/// @brief Returns the tile at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The tile at given coordinates.
uint8_t radar_scan_5x5_at(const RadarScan5x5 *scan, int8_t dx, int8_t dy);

/// @brief Returns the bot id at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The bot id at given coordinates, or 0 if there's no bot there.
uint64_t radar_scan_5x5_bot_at(const RadarScan5x5 *scan, int8_t dx, int8_t dy);

/// @brief Represents a 7x7 radar scan.
typedef struct RadarScan7x7 RadarScan7x7;

/// @brief Scans a 7x7 square around the bot.
/// @return The radar scan struct.
RadarScan7x7 *radar_scan_7x7();

/// @brief Returns the tile at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The tile at given coordinates.
uint8_t radar_scan_7x7_at(const RadarScan7x7 *scan, int8_t dx, int8_t dy);

/// @brief Returns the bot id at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The bot id at given coordinates, or 0 if there's no bot there.
uint64_t radar_scan_7x7_bot_at(const RadarScan7x7 *scan, int8_t dx, int8_t dy);

/// @brief Represents a 9x9 radar scan.
typedef struct RadarScan9x9 RadarScan9x9;

/// @brief Scans a 9x9 square around the bot.
/// @return The radar scan struct.
RadarScan9x9 *radar_scan_9x9();

/// @brief Returns the tile at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The tile at given coordinates.
uint8_t radar_scan_9x9_at(const RadarScan9x9 *scan, int8_t dx, int8_t dy);

/// @brief Returns the bot id at given coordinates.
/// @param scan The radar scan struct.
/// @param dx Offset in the bot's direction.
/// @param dy Offset perpendicular to the bot's direction.
/// @return The bot id at given coordinates, or 0 if there's no bot there.
uint64_t radar_scan_9x9_bot_at(const RadarScan9x9 *scan, int8_t dx, int8_t dy);

#endif // RADAR_H