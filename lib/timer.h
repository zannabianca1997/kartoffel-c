#ifndef TIMER_H
#define TIMER_H

#include "lib.h"

// Returns a pseudorandom number (timer seed)
uint32_t timer_seed() {
    return rdi(MEM_TIMER, 0);
}

// Returns the number of ticks that have passed since the bot's been born
uint32_t timer_ticks() {
    return rdi(MEM_TIMER, 1);
}

// Waits until the given number of ticks has passed
void timer_wait(uint32_t ticks) {
    uint32_t target_ticks = timer_ticks() + ticks;

    while (timer_ticks() < target_ticks) {
        // Empty loop waiting for the required ticks to pass
    }
}

#endif // TIMER_H
