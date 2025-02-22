/**
 * Memory interface
 *
 * Low level memory functions and pointers. You probably don't want to use
 * these functions directly, but use the higher-level ones defined in the
 * appropriate header files instead.
 */

#ifndef MEM_H
#define MEM_H

#include "types.h"

#define MEM ((volatile uint32_t *)0x08000000)
#define MEM_TIMER (MEM)
#define MEM_BATTERY ((volatile uint32_t *)((uintptr_t)MEM + 1024))
#define MEM_SERIAL ((volatile uint32_t *)((uintptr_t)MEM + (2 * 1024)))
#define MEM_MOTOR ((volatile uint32_t *)((uintptr_t)MEM + (3 * 1024)))
#define MEM_ARM ((volatile uint32_t *)((uintptr_t)MEM + (4 * 1024)))
#define MEM_RADAR ((volatile uint32_t *)((uintptr_t)MEM + (5 * 1024)))
#define MEM_COMPASS ((volatile uint32_t *)((uintptr_t)MEM + (6 * 1024)))

// Reads a uint32_t from the memory
static inline uint32_t rdi(volatile uint32_t *mem, uint32_t offset)
{
    return *(volatile uint32_t *)((uintptr_t)mem + (offset * 4));
}

// Writes a uint32_t to the memory
static inline void wri(volatile uint32_t *mem, uint32_t offset, uint32_t value)
{
    *(volatile uint32_t *)((uintptr_t)mem + (offset * 4)) = value;
}

// Creates a command uint32_t (from little endian bytes)
static inline uint32_t cmd(uint8_t cmd, uint8_t left, uint8_t right, uint8_t flags)
{
    return cmd | (left << 8) | (right << 16) | (flags << 24);
}

#endif // MEM_H