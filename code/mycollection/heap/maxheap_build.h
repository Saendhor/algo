#ifndef MAXHEAP_BUILD_H
#define MAXHEAP_BUILD_H

#include "maxheap_heapify.h"

int maxheap_build_i(heap_t input) {
    //Setup the newly created element
    for (int i = (input.heap_size - 1) / 2; i >= 0; i--) {
        maxheap_heapify(input, i);
    }
    return 0;
}

#endif
/* PSEUDOCODE

    BUILD-MAX-HEAP(A)
        heap-size[A] ← length[A]
        for i ← floor(length[A / 2]) downto 1
            MAX-HEAPIFY(A, i)

*/