#include "mem.h"
#include "types.h"

#define RADAR_H_LOW_LEVEL
#include "radar.h"

uint8_t is_radar_ready()
{
    return rdi(MEM_RADAR, 0) == 1;
}

/// @details
/// This function performs an `r x r` scan, so e.g. `r=3` will do a `3x3` scan.
/// Legal values of `r` are 3, 5, 7 or 9 - other values will cause the CPU to
/// crash.
///
/// Note that this is a low-level function - for convenience you'll most likely
/// want to use one of:
///
/// - `radar_scan_3x3()`,
/// - `radar_scan_5x5()`,
/// - `radar_scan_7x7()`,
/// - `radar_scan_9x9()`.
///
/// # Accessing scanned tiles
///
/// Use `radar_read()` to access the scanned data.
void radar_scan(uint8_t r)
{
    wri(MEM_RADAR, 0, cmd(0x01, r, 0x00, 0x00));
}

/// @details
/// Note that this is a low-level function
///
/// # Coordinate system
///
/// This function work in a bot-centric coordinate system, that is:
///
/// - `at(0, 0)` returns the bot itself (`'@'`),
/// - `at(-1, 0)` returns what's to the left of the bot,
/// - `at(1, 0)` returns what's to the right of the bot,
/// - `at(0, -1)` returns what's in front of the bot,
/// - `at(0, 1)` returns what's behind the bot,
/// - etc.
///
/// This also means that the 3x3 scan allows you to access `at(-1..=1)`, 5x5
/// gives you `at(-2..=2)` etc.
///
/// # Return value
///
/// Meaning of the returned number depends on `z`:
///
/// - `z=0` returns the tile located at `dx,dy`,
/// - `z=1` returns the higher 32 bits of the id of the bot located at `dx,dy`,
/// - `z=2` returns the lower 32 bits of the id of the bot located at `dx,dy`.
uint32_t radar_read(uint8_t r, int8_t dx, int8_t dy, uint8_t z)
{
    uint32_t x = (dx + (r / 2)) & 0xFF;
    uint32_t y = (dy + (r / 2)) & 0xFF;
    uint32_t z_offset = z * r * r + y * r + x;
    return rdi(MEM_RADAR, 1 + z_offset);
}

#define SCAN(R, R_STR)                     \
    RadarScan##R_STR *radar_scan_##R_STR() \
    {                                      \
        radar_scan(R);                     \
        return NULL;                       \
    }

/// @details
/// For performance reasons, those functions doesn't copy the scanned area into
/// your bot's RAM - rather, the data is kept inside the radar's memory and
/// transparently accessed each time you call `radar_scan_RxR_at()` etc.
///
/// In practice, this means that consecutive scans "overwrite" previous scans'
/// results.

SCAN(3, 3x3)
SCAN(5, 5x5)
SCAN(7, 7x7)
SCAN(9, 9x9)

#undef SCAN

#define SCAN_AT(R, R_STR)                                                               \
    uint8_t radar_scan_##R_STR##_at(const RadarScan##R_STR *scan, int8_t dx, int8_t dy) \
    {                                                                                   \
        return radar_read(R, dx, dy, 0) & 0xFF;                                         \
    }

/// @details
/// Returns the topmost thing visible at given coordinates:
///
/// - if there's a bot, returns `'@'`,
/// - otherwise, if there's an object, returns that object (e.g. `'*'`),
/// - otherwise, if there's a tile, returns that tile (e.g. `'.'` or `'|'`),
/// - otherwise returns `' '` (a space) representing void (driving into it
///   makes you fall out of the map and die).

SCAN_AT(3, 3x3)
SCAN_AT(5, 5x5)
SCAN_AT(7, 7x7)
SCAN_AT(9, 9x9)

#undef SCAN_AT

#define SCAN_BOT_AT(R, R_STR)                                                                \
    uint64_t radar_scan_##R_STR##_bot_at(const RadarScan##R_STR *scan, int8_t dx, int8_t dy) \
    {                                                                                        \
        uint64_t d1 = (uint64_t)radar_read(R, dx, dy, 1);                                    \
        uint64_t d2 = (uint64_t)radar_read(R, dx, dy, 2);                                    \
        return (d1 << 32) | d2;                                                              \
    }

/// @details
/// Returns id of the bot at given coordinates or `0` if there's no bot there.
///
/// Bot ids are random, unique, non-zero 64-bit numbers assigned to each bot
/// during its upload; ids are preserved when a bot is reincarnated.

SCAN_BOT_AT(3, 3x3)
SCAN_BOT_AT(5, 5x5)
SCAN_BOT_AT(7, 7x7)
SCAN_BOT_AT(9, 9x9)

#undef SCAN_BOT_AT