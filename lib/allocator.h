#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "lib.h"

extern const uint8_t _heap_start;
extern const uint8_t _heap_end;

static  void *ptr = (void *) 0;

void *malloc(uint32_t size) {
    if (!ptr) {
      ptr = (void *)(((uint32_t)&_heap_start / 4) * 4);
    }
    void* ret = ptr;
    ptr += ((size / 4) * 4);
    return ret;
}

void free(void *ptr) {

}

#endif // ALLOCATOR_H
