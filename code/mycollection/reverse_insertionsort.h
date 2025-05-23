#pragma once

int reverse_insertionsort(int A[], int size) {
    int key, i;
    for (int j = 1; j < size; j++) { //notice j = 1 and not j = 2 since we're enumerating from 0
        key = A[j];
        i = j-1;
        while (i >= 0 && A[i] < key) { //notice that >= 0 or > -1 since we're enumerating from 0
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
    return 0;
}