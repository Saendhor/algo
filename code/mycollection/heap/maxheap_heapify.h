#ifndef MAXHEAP_HEAPIFY_H
#define MAXHEAP_HEAPIFY_H

#include "heap_t.h"

int maxheap_heapify(heap_t toheapify, int index) {
    int atindex_max = index;
    //left < heapsize && left value > index value
    if (fleft(index) <= toheapify.heap_size
        && toheapify.array[fleft(index)] > toheapify.array[atindex_max]) {
        atindex_max = fleft(index);
    }
    //right index < heapsize index && right value > max value (still index value if we entered into the "else")
    if (fright(index) <= toheapify.heap_size
        && toheapify.array[fright(index)] > toheapify.array[atindex_max]) {
        atindex_max = fright(index);
    }
    if (atindex_max != index) {
        swap_i(toheapify.array, index, atindex_max);
        maxheap_heapify(toheapify, atindex_max);
    }

    return 0;
}

#endif
/* PSEUDOCODE

    MAX-HEAPIFY (A, i)
        l ← LEFT(i)
        r ← RIGHT(i)
        if l <= heap-size[A] and A[l] > A[i]
            max ← l
        else
            max ← i
        if r <= heap-size[A] and A[r] > A[max]
            max ← r
        if max != i
            swap A[i] ←→ A[max]
            MAX-HEAPIFY(A, max)

*/