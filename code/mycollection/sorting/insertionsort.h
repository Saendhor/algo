#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <stdio.h>

int insertionsort_i(int A[], int size) {
    int key, i;

    printf("[MISC] Item to sort: %d\n", size);
    for (int j = 1; j < size; j++) { //notice j = 1 and not j = 2 since we're enumerating from 0
        key = A[j];
        i = j-1;
        while (i >= 0 && A[i] > key) { //notice that >= 0 or > -1 since we're enumerating from 0
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
    return 0;
}

#endif
/*  PSEUDOCODE

0    insertionsort(A)
1        for j ← 2 to length[A]
2            key ← A[j]
3            //Inserisce A[j] nella sequenza ordinata A[1 ... j-1]
4            i ← j-1
5            while i > 0 and A[i] > key
6                A[i+1] ← A[i]
7                i ← i-1
8            A[i+1] ← key

*/