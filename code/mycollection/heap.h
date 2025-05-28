#pragma once
#include <stdio.h>
#include <stdlib.h>

#include "swap.h"

typedef struct heap {
    int size;
    int heap_size;
    int* array;

} heap_t;

int fleft(int index) {
    return 2 * index + 1;
}

int fparent(int index) {
    return index / 2;
}

int fright(int index) {
    return 2 * index + 2;
}

heap_t createheap(int size) {
    heap_t new_heap;
    new_heap.size = size;
    new_heap.heap_size = 0;
    new_heap.array = (int*) malloc(size * sizeof(int));

    return new_heap;
}

int max_heapify(heap_t toheapify, int index) {
    int atindex_max = index;
    //left < heapsize && left value > index value
    if (fleft(index) <= toheapify.heap_size && toheapify.array[fleft(index)] > toheapify.array[index]) {
        atindex_max = fleft(index);
    }
    //right index < heapsize index && right value > max value (still index value if we entered into the "else")
    if (fright(index) <= toheapify.heap_size && toheapify.array[fright(index)] > toheapify.array[atindex_max]) {
        atindex_max = fright(index);
    }
    if (atindex_max != index) {
        swap_i(toheapify.array, index, atindex_max);
        max_heapify(toheapify, atindex_max);
    }

    return 0;
}

int build_max_heap_i(heap_t input) {
    //Setup the newly created element
    for (int i = input.size / 2; i > 0; i--) {
        max_heapify(input, i);
    }
    return 0;
}

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