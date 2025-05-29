#pragma once
#include "createheap.h"
#include "maxheap_heapify.h"

int maxheap_build_i(int input[]) {
    //Creates heap with inputed array
    heap_t heap = createheap_i(input);
    //Setup the newly created element
    for (int i = (heap.heap_size - 1) / 2; i >= 0; i--) {
        maxheap_heapify(heap, i);
    }
    return 0;
}

/* PSEUDOCODE

    BUILD-MAX-HEAP(A)
        heap-size[A] ← length[A]
        for i ← floor(length[A / 2]) downto 1
            MAX-HEAPIFY(A, i)

*/