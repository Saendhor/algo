#pragma once
#include <stdio.h>

#define printarray(array, size) _Generic(array, \
    int*: printarray_i, \
    float*: printarray_f, \
    double*: printarray_d)

void printarray_d(double array[], int size) {
    printf("ARRAY SIZE: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("INDEX: %d\tVALUE: %e\n", i, array[i]);
    }
    printf("\n");
}

void printarray_f(float array[], int size) {
    printf("ARRAY SIZE: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("INDEX: %d\tVALUE: %f\n", i, array[i]);
    }
    printf("\n");
}

void printarray_i(int array[], int size) {
    printf("ARRAY SIZE: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("INDEX: %d\tVALUE: %d\n", i, array[i]);
    }
    printf("\n");
}