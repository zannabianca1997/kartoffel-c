/**
 * Interface for the arm
 *
 * This file contains functions for controlling the arm.
 */

#ifndef ARM_H
#define ARM_H

/// @brief Returns whether the arm is ready and `arm_stab()` can be invoked.
/// @return 1 if the arm is ready, 0 otherwise.
uint8_t is_arm_ready();

/// @brief Waits for the arm to become ready.
static inline void arm_wait()
{
    while (!is_arm_ready())
    {
        // Busy-wait loop
    }
}

/// @brief Stabs the bot in front of you, killing it.
void arm_stab();

/// @brief Picks the object in front of you and puts it into the inventory under the
/// zeroth index
void arm_pick();

/// @brief Takes object from the inventory and drops it in front of you
/// @param idx Index of the object to drop
void arm_drop(uint8_t idx);

#endif
