#pragma once
#include "../../swap.h"

typedef struct heap {
    int* array;
    int heap_size;
    int total_size;

} heap_t;

int fleft(int index) {
    return 2 * index + 1;
}

int fparent(int index) {
    return index / 2;
}

int fright(int index) {
    return 2 * index + 2;
}