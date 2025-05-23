#pragma once
#include "merge.h"

int mergesort(int A[], int inf, int sup) {
    int pivot;
    if (inf < sup) {
        pivot = (inf + sup) / 2; //already floor since is int

        //Invoke recursively mergesort on left side
        mergesort(A, inf, pivot);
        //Invoke recursively mergesort on right side
        mergesort(A, pivot + 1, sup);
        //Merge the results of the mergesort invocations
        merge(A, inf, pivot, sup);
    }

    return 0;
}

/* PSEUDOCODE

    MERGESORT(A, p, r)
1        if p < r
2            q ← floor((p+r) / 2)
3            MERGESORT(A, p, q)
4            MERGESORT(A, q+1, r)
5            MERGE(A, p, q, r)

*/