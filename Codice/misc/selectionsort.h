#pragma once
#include <stdio.h>

int selectionsort_i(int A[], int size) {
    int min_index, temp;
    for (int i = 0; i < size; i++) {
        min_index = i;
        for (int j = i+1; j < size; j++) {
            if (A[min_index] > A[j]) {
                min_index = j;
            }
        }
        //swap
        temp = A[i];
        A[i] = A[min_index];
        A[min_index] = temp;
    }
    return 0;
}