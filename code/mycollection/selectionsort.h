#pragma once
#include <stdio.h>

#include "swap.h"

int selectionsort_i(int input[], int size) {
    int min_index, temp;
    for (int i = 0; i < size -1; i++) {
        min_index = i;
        for (int j = i+1; j < size; j++) {
            if (input[min_index] > input[j]) {
                min_index = j;
            }
        }
        //swap
        swap_i(input, i, min_index);
    }
    return 0;
}

/* PSEUDOCODE

0    selectionsort(A)
1        for i ← 1 to length[A]-1:
2            min_index ← i
3            for j ← i + 1 to length[A]:
4                if A[j] < A[min_index]:
5                    min_index ← j
6            swap(A, i, min_index)

*/