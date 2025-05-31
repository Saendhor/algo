#ifndef HEAPSORT_H
#define HEAPSORT_H


#include "../heap/createheap.h"
#include "../heap/maxheap_build.h"

int heapsort(int* input) {
    heap_t heap = createheap_i(input);
    maxheap_build_i(heap);
    int size = (int) sizeof(input) / sizeof(int);
    for (int i = size; i > 1 ; i--) {
        swap_i(input, 0, i);
        heap.heap_size--;
        maxheap_heapify(heap, 1);
    }
    return 0;
}

#endif
/*  PSEUDOCODE

    HEAPSORT(A)
        BUILD-MAX-HEAP(A)
        for i ← length[A] downto 2
            SWAP(A, 1, i)
            heap-size[A] ← heap-size[A] - 1
            MAX-HEAPIFY(A, 1)
*/