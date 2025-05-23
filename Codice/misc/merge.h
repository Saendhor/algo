#pragma once
#define INF 8000

void merge(int A[], int inf, int pivot, int sup) {
    //Determining left and right ranged based on the pivot
    int left_size = pivot - inf + 1,
        right_size = sup - pivot;
    int L[left_size], R[right_size];
    //Setup left array
    for (int i = 1; i < left_size; i++) {
        L[i] = A[inf + i - 1];
    }
    L[left_size] = (int) INF;

    //Setup left array
    for (int j = 1; j < right_size; j++) {
        R[j] = A[pivot + j];
    }
    R[right_size] = (int) INF;

    int l_index, r_index;
    l_index = r_index = 0;
    for (int k = inf; k < sup; k++) {
        if (L[l_index] <= R[r_index]) {
            //grab item from left array
            A[k] = L[l_index];
            l_index++;
        } else {
            //grab item from right array
            A[k] = R[r_index];
            r_index++;
        }
    }



}

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