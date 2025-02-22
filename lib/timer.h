/**
 * Timer interface
 *
 * This file contains functions for reading the timer.
 */

#ifndef TIMER_H
#define TIMER_H

#include "types.h"

/// @brief Returns a pseudorandom number
/// @return A pseudorandom number
uint32_t timer_seed();

/// @brief Returns the number of ticks that have passed since the bot's been born.
/// @return The number of ticks that have passed since the bot's been born.
uint32_t timer_ticks();

/// @brief Waits until the given number of ticks has passed
/// @param ticks Number of ticks to wait for
static inline void timer_wait(uint32_t ticks)
{
    uint32_t target_ticks = timer_ticks() + ticks;

    while (timer_ticks() < target_ticks)
    {
        // Busy-wait loop
    }
}

#endif // TIMER_H
