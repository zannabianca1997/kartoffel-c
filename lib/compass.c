#ifndef COMPASS_H
#define COMPASS_H

#include "mem.h"
#include "types.h"
#include "compass.h"

/// @details
/// The first measurement is available immediately after the bot is born, and it
/// corresponds to the bot's direction right after spawning, while the next
/// measurements are provided automatically every ~128k ticks (~2s).
///
/// Calling this function before the next measurement is ready returns zero,
/// indicating `measurement not ready yet`.
uint32_t compass_dir()
{
    return rdi(MEM_COMPASS, 0);
}

#endif // COMPASS_H
