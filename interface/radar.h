#ifndef RADAR_H
#define RADAR_H

// Check if the radar is ready
int is_radar_ready();
// Wait for the radar to become ready
void radar_wait();
// Low-level radar scan function
void radar_scan(uint8_t r);
// Radar data reading function
uint32_t radar_read(uint8_t r, int8_t dx, int8_t dy, uint8_t z);
// Radar scan struct

typedef struct {
    // No direct data storage; will access memory directly when needed
} RadarScan;

// Access a scanned tile (equivalent to RadarScan::at in Rust)
char radar_scan_at(const RadarScan *scan, uint8_t r, int8_t dx, int8_t dy);
// Access the bot ID at the given coordinates
uint64_t radar_scan_bot_at(const RadarScan *scan, uint8_t r, int8_t dx, int8_t dy);
RadarScan radar_scan_3x3();
RadarScan radar_scan_5x5();
RadarScan radar_scan_7x7();
RadarScan radar_scan_9x9();


#endif // RADAR_H
