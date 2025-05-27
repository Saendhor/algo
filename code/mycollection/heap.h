#pragma once
#include <stdio.h>

#include "swap.h"

typedef struct heap {
    int size;
    int heap_size;
    int* array;

} heap_t;

int fleft(int index) {
    return 2 * index;
}

int fparent(int index) {
    return index / 2;
}

int fright(int index) {
    return 2 * index + 1;
}

int max_heapify(heap_t toheapify, int index) {
    int atindex_max;
    //left < heapsize && left value > index value
    if (fleft(index) <= toheapify.heap_size && toheapify.array[fleft(index)] > toheapify.array[index]) {
        atindex_max = fleft(index);
    } else { 
        atindex_max = index;
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

heap_t build_max_heap_i(int* input) {
    heap_t new_heap;
    new_heap.array = input;
    new_heap.size = new_heap.heap_size = (int) sizeof(input) / sizeof(int);
    for (int i = new_heap.size / 2; i > 0; i--) {
        max_heapify(new_heap, i);
    }
    return new_heap;
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