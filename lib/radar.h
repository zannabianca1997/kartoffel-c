#ifndef RADAR_H
#define RADAR_H

#include "lib.h"

// Check if the radar is ready
static inline int is_radar_ready() {
    return rdi(MEM_RADAR, 0) == 1;
}

// Wait for the radar to become ready
static inline void radar_wait() {
    while (!is_radar_ready()) {
        // Empty loop
    }
}

// Low-level radar scan function
static inline void radar_scan(uint8_t r) {
    wri(MEM_RADAR, 0, cmd(0x01, r, 0x00, 0x00));
}

// Radar data reading function (equivalent to radar_read in Rust)
static inline uint32_t radar_read(uint8_t r, int8_t dx, int8_t dy, uint8_t z) {
    uint32_t x = (dx + (r / 2)) & 0xFF;
    uint32_t y = (dy + (r / 2)) & 0xFF;
    uint32_t z_offset = z * r * r + y * r + x;
    return rdi(MEM_RADAR, 1 + z_offset);
}

// Radar scan struct
typedef struct {
    // No direct data storage; will access memory directly when needed
} RadarScan;

// Access a scanned tile (equivalent to RadarScan::at in Rust)
static inline char radar_scan_at(const RadarScan *scan, uint8_t r, int8_t dx, int8_t dy) {
    return (char)(radar_read(r, dx, dy, 0) & 0xFF);
}

// Access the bot ID at the given coordinates (equivalent to RadarScan::bot_at in Rust)
static inline uint64_t radar_scan_bot_at(const RadarScan *scan, uint8_t r, int8_t dx, int8_t dy) {
    uint64_t d1 = (uint64_t)radar_read(r, dx, dy, 1);
    uint64_t d2 = (uint64_t)radar_read(r, dx, dy, 2);
    return (d1 << 32) | d2;
}

// Radar scan 3x3 (equivalent to radar_scan_3x3 in Rust)
static inline RadarScan radar_scan_3x3() {
    radar_scan(3);
    RadarScan scan;
    return scan;
}

// Radar scan 5x5 (equivalent to radar_scan_5x5 in Rust)
static inline RadarScan radar_scan_5x5() {
    radar_scan(5);
    RadarScan scan;
    return scan;
}

// Radar scan 7x7 (equivalent to radar_scan_7x7 in Rust)
static inline RadarScan radar_scan_7x7() {
    radar_scan(7);
    RadarScan scan;
    return scan;
}

// Radar scan 9x9 (equivalent to radar_scan_9x9 in Rust)
static inline RadarScan radar_scan_9x9() {
    radar_scan(9);
    RadarScan scan;
    return scan;
}

#endif // RADAR_H
