#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <stdlib.h>
#include "../findmax.h"

int countingsort(int* input) {
    int size = (int) sizeof(input) / sizeof(int);
    int max = findmax_i(input);

    //create C array and initialize it to 0
    int num_values[max];
    for (int i = 0; i < max; i++) {
        num_values[i] = 0;
    }

    //increase the amount of occurences of the A[j] value in C
    for (int j = 0; j < size; j++) {
        num_values[input[j]]++;
    }

    //define the cumulative amount in the array C
    for (int i = 1; i < max; i++) {
        num_values[i] = num_values[i] + num_values[i - 1];
    }

    //creating the array of the ordered input
    int ordered_input[size];
    for (int j = size; j > 0; j--) {
        ordered_input[num_values[input[j]]] = input[j];
        num_values[input[j]]--;
    }

    //Copying the ordered values inside the inputed array
    for (int i = 0; i < size; i++) {
        input[i] = ordered_input[i];
    }

    return 0;
}

#endif
/*  PSEUDOCODE

    COUNTING-SORT(A, B, k)
        for i ← 0 to k
            C[i] ← 0
        for j ← 1 to length[A]
            C[A[j]] ← C[A[j]] + 1
        for i ← 1 to k
            C[i] ← C[i] + C[i - 1]
        for j ← length[A] downto 1
            B[C[A[j]]] ← A[j]
            C[A[j]] ← C[A[j]] - 1

*/