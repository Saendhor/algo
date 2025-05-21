#pragma once

void insertionsort(int A[], int size) {
    int key, i;
    for (int j = 2; j < size; j++) {
        key = A[j];
        i = j-1;
        while (i >= 0 && A[i] > key) { //notice that >= 0 or > -1 since we're numering it from 0
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }

}

/*  PSEUDOCODICE

0    insertionsort(A)
1        for j ← 2 to length[A]
2            do key ← A[j]
3            // Inserisce A[j] nella sequenza ordinata A[1 ... j-1]
4            i ← j-1
5            while i > 0 and A[i] > key
6                do A[i+1] ← A[i]
7                    i ← i-1
8            A[i+1] ← key
*/