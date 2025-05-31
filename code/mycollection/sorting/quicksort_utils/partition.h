#ifndef PARTITION_H
#define PARTITION_H

#include "../../swap.h"

int partition_i(int* input, int inf, int sup) {
    int value = input[sup];
    int index = inf - 1 ;
    for (int j = inf; j < sup; j++) {
        if (input[j] <= value) {
            index++;
            swap_i(input, index, j);
        }
    }
    swap_i(input, index + 1, sup);

    return 0;
}

#endif
/* PSEUDOCODE

    PARTITION(A, p, r)
        x ← A[r]
        i ← p-1
        for j← p to r-1
            if A[j] <= x
                i ← i + 1
                SWAP(A, i, j)
        SWAP(A, i+1, r)
        return i + 1
*/