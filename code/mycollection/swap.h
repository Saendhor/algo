#ifndef SWAP_H
#define SWAP_H

int swap_i(int* input, int index, int dest) {
    int temp = input[index];
    input[index] = input[dest];
    input[dest] = temp;

    return 0;
}

#endif