#pragma once
#include <stdio.h>

int swap_i(int* input, int index, int dest) {
    int temp = input[index];
    input[index] = input[dest];
    input[dest] = temp;

    return 0;
}