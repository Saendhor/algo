#ifndef MERGE_H
#define MERGE_H

#include <stdio.h>

int merge(int tomerge[], int inf, int pivot, int sup) {
    //Determining left and right ranged based on the pivot
    int left_size = pivot - inf + 1;
    int right_size = sup - pivot;

    //Creating left and right array
    int left_array[left_size], right_array[right_size];

    //Copying data to the respective arrays
    for (int i = 0; i < left_size; i++) {
        left_array[i] = tomerge[inf + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_array[j] = tomerge[pivot + 1 + j];
    }

    //Merging left and right array
    int current = inf;
    int l_index = 0, r_index = 0;
    while (l_index < left_size && r_index < right_size) {
        if (left_array[l_index] <= right_array[r_index]) {
            tomerge[current] = left_array[l_index];
            l_index++;
        } else {
            tomerge[current] = right_array[r_index];
            r_index++;
        }
        current++;
    }

    //Keep merging the left side if the right array has already been emptied
    while (l_index < left_size) {
        tomerge[current] = left_array[l_index];
        l_index++;
        current++;
    }

    //Keep merging the right side if the left array has already been emptied
    while (r_index < right_size) {
        tomerge[current] = right_array[r_index];
        r_index++;
        current++;
    }

    return 0;
}

#endif
/* PSEUDOCODE

00    MERGE(A, p, q, r)
01        n ← q -p + 1
02        m ← r - q
03        create array L[n + 1] e R[m + 1]
04        for i ← 1 to n
05            L[i] ← A[p + i - 1]
06        for j ← 1 to m
07            R[j] ← A[q + j]
08        L[n] ← INF
09        R[m] ← INF
10        i ← 1
11        j ← 1
12        for k ← p to r
13            if L[i] <= R[j]
14                A[k] ← L[i]
15                i ← i + 1
16            else A[k] ← R[j]
17                j ← j + 1

*/