#ifndef COMPASS_H
#define COMPASS_H

#include "lib.h"

// Function to get the current compass direction
uint32_t compass_dir() {
    // Reads the first byte from the memory-mapped COMPASS register (0 offset)
    return rdi(MEM_COMPASS, 0);
}

#endif // COMPASS_H
