#pragma once
#include "heap_t.h"
#include "max_heapify.h"

int build_max_heap_i(heap_t input) {
    //Setup the newly created element
    for (int i = (input.heap_size - 1) / 2; i >= 0; i--) {
        printf("[GUARDA] i = %d\n", i);
        max_heapify(input, i);
    }
    return 0;
}