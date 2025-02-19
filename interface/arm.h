#ifndef ARM_H
#define ARM_H

// Function to read the arm status
int is_arm_ready();
// Function to wait for the arm to be ready
void arm_wait();
// Function to stab the bot (if it's ready)
void arm_stab();
// Function to pick up an object
void arm_pick();
// Function to drop an object from inventory at given index
void arm_drop(uint8_t idx);

#endif
