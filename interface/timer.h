#ifndef TIMER_H
#define TIMER_H

// Returns a pseudorandom number (timer seed)
uint32_t timer_seed();

// Returns the number of ticks that have passed since the bot's been born
uint32_t timer_ticks();

// Waits until the given number of ticks has passed
void timer_wait(uint32_t ticks);

#endif // TIMER_H
