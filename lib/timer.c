#include "mem.h"
#include "types.h"
#include "timer.h"

/// @details
/// Returns a pseudorandom number that can be used as a source of randomness
/// for hashmaps and the like.
///
/// Note that this doesn't return a *new* random number each time it's called -
/// the number is randomized once, when the bot is born.
uint32_t timer_seed()
{
    return rdi(MEM_TIMER, 0);
}

/// @details
/// This counter overflows after about 18 hours, after which it will start
/// counting from zero.
uint32_t timer_ticks()
{
    return rdi(MEM_TIMER, 1);
}