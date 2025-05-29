#include "maxheap_heapify.h"

int maxheap_extract_max_i(heap_t input) {
    int max = 0;
    return max;
}

/* PSEUDOCODE

    HEAP-EXTRACT-MAX(A)
        if heap-size[A] < 1
            error "heap underflow"
        max ← A[1]
        A[1] ← A[heap-size[A]]
        heap-size[A] ← heap-size[A] - 1
        MAX-HEAPIFY(A, 1)
        return max
    
*/