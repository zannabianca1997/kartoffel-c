#ifndef LIB_H
#define LIB_H

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef unsigned int uint32_t;
typedef signed int int32_t;

typedef unsigned long long uint64_t;
typedef signed long long int64_t;

typedef unsigned int uintptr_t;

#define MEM         ((volatile uint32_t *)0x08000000)
#define MEM_TIMER   (MEM)
#define MEM_BATTERY ((volatile uint32_t *)((uintptr_t)MEM + 1024))
#define MEM_SERIAL  ((volatile uint32_t *)((uintptr_t)MEM + (2 * 1024)))
#define MEM_MOTOR   ((volatile uint32_t *)((uintptr_t)MEM + (3 * 1024)))
#define MEM_ARM     ((volatile uint32_t *)((uintptr_t)MEM + (4 * 1024)))
#define MEM_RADAR   ((volatile uint32_t *)((uintptr_t)MEM + (5 * 1024)))
#define MEM_COMPASS ((volatile uint32_t *)((uintptr_t)MEM + (6 * 1024)))

// Reads a byte from the memory map
uint8_t rdi(volatile uint32_t *mem, uint32_t offset);
// Writes a byte to the memory map
void wri(volatile uint32_t *mem, uint32_t offset, uint8_t value);
// Creates a command byte (from little endian bytes)
uint32_t cmd(uint8_t cmd, uint8_t left, uint8_t right, uint8_t flags);

#endif // LIB_H