#pragma once
#include <stdio.h>
#include "merge.h"
#include "printarray.h"

int mergesort(int input[], int inf, int sup) {
    if (inf < sup) {
        int pivot = inf + (sup - inf) / 2; //already floor since is int

        //Invoke recursively mergesort on left side
        mergesort(input, inf, pivot);
        //Invoke recursively mergesort on right side
        mergesort(input, pivot + 1, sup);
        //Merge the results of the mergesort invocations
        if (merge(input, inf, pivot, sup) != 0) {
            printf("Error while attempting to merge with indexes\n\
                            inf: %d\tsup: %d", inf, sup);
            return 1; //ERROR
        }
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