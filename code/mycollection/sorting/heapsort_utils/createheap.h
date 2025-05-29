#pragma once
#include <stdlib.h>

#include "heap_t.h"

heap_t createheap(int size) {
    heap_t new_heap;
    new_heap.total_size = size;
    new_heap.heap_size = 0;
    new_heap.array = (int*) malloc(size * sizeof(int));

    return new_heap;
}