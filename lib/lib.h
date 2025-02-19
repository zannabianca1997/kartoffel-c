#ifndef LIB_H
#define LIB_H

#include "lib.h"

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
static inline uint32_t rdi(volatile uint32_t *mem, uint32_t offset) {
    return *(volatile uint32_t *)((uintptr_t)mem + (offset * 4));
}

/* Writes a full 32-bit word to the memory map */
static inline void wri(volatile uint32_t *mem, uint32_t offset, uint32_t value) {
    *(volatile uint32_t *)((uintptr_t)mem + (offset * 4)) = value;
}

/* Creates a command word (packs 4 bytes into a 32-bit little-endian value) */
static inline uint32_t cmd(uint8_t cmd, uint8_t left, uint8_t right, uint8_t flags) {
    return cmd | (left << 8) | (right << 16) | (flags << 24);
}

#endif // LIB_H
