/**
 * Allocator interface
 *
 * This file contains functions for allocating and freeing memory.
 *
 * For now the implementation is very simple and allocates memory permanently.
 * Only when all the allocations are freed, the memory is freed. As long as the
 * bot periodically frees all the allocated memory, the quantity of allocated
 * memory remains bounded.
 */

#ifndef ALLOC_H
#define ALLOC_H

#include "types.h"

void *alloc_malloc(uintptr_t size);
void alloc_free(void *ptr);

#endif // ALLOC_H