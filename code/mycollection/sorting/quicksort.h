#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "quicksort_utils/partition.h"

int quicksort_i(int* input, int inf, int sup) {
    int pivot = 0;
    if (inf < sup) {
        pivot = partition_i(input, inf, sup); //Splits array into 3 parts: (1) <= x ; (2) > x; (3) pivot
        if(pivot != 0) {
            quicksort_i(input, inf, pivot - 1);
            quicksort_i(input, pivot + 1, sup);
        }
    }
}

#endif
/* PSEUDOCODE

    QUICKSORT(A, p, r)
        if p < r
            q ← PARTITION(A, p, r)
            QUICKSORT(A, p, q-1)
            QUICKSORT(A, q+1, r)

*/