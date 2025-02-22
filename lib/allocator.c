#include "mem.h"
#include "types.h"
#include "allocator.h"

/// @brief The start of the heap, filled in by the linker script.
extern const uint32_t _heap_start;
/// @brief The end of the heap, filled in by the linker script.
extern const uint32_t _heap_end;

/// @brief The start of the heap.
static uint32_t *const heap_start = (uint32_t *)&_heap_start;

/// @brief The current position in the heap.
/// @details All allocations are between `heap_start` and `heap_fill`.
static uint32_t *heap_fill = (uint32_t *)&_heap_start;

/// @brief The end of the heap.
static uint32_t *const heap_end = (uint32_t *)&_heap_end;

/// @brief The number of allocations made.
/// @details This is used to keep track of the number of allocations made,
/// and to free all the memory when there are no more allocations.
static uintptr_t allocations = 0;

void *alloc_malloc(uintptr_t size)
{
  uintptr_t uint32_t_size = (size + sizeof(uint32_t) - 1) / sizeof(uint32_t);

  if (heap_fill + uint32_t_size >= heap_end)
  {
    return NULL;
  }

  uint32_t *ret = heap_fill;
  heap_fill += uint32_t_size;
  allocations += 1;
  return (void *)ret;
}

void alloc_free(void *ptr)
{
  allocations -= 1;
  if (allocations == 0)
  {
    heap_fill = heap_start;
  }
}