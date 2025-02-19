#ifndef ARM_H
#define ARM_H

#include "lib.h"

// Function to read the arm status
int is_arm_ready() {
    // Reads the first byte from the memory-mapped ARM register (0 offset)
    return rdi(MEM_ARM, 0) == 1;
}

// Function to wait for the arm to be ready
void arm_wait() {
    // Continuously checks if the arm is ready
    while (!is_arm_ready()) {
        // Do nothing, just wait
    }
}

// Function to stab the bot (if it's ready)
void arm_stab() {
    // Write command to the arm memory address to stab (0x01 is the command for stab)
    wri(MEM_ARM, 0, cmd(0x01, 0x00, 0x00, 0x00));
}

// Function to pick up an object
void arm_pick() {
    // Write command to the arm memory address to pick an object (0x02 is the pick command)
    wri(MEM_ARM, 0, cmd(0x02, 0x00, 0x00, 0x00));
}

// Function to drop an object from inventory at given index
void arm_drop(uint8_t idx) {
    // Write command to drop the object at the given index (0x03 is the drop command)
    wri(MEM_ARM, 0, cmd(0x03, idx, 0x00, 0x00));
}

#endif // ARM_H
