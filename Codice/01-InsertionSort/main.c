#include <stdio.h>
#include <unistd.h>
#include "insertionsort.h"

void printArray(int* array, int size) {
    printf("ARRAY SIZE: %d\n", size);
    for (int i = 0; i < size; i++) {
        printf("INDEX: %d\tVALUE: %d\n", i, array[i]);
    }

    printf("\n");
}


int main(int argc, char* argv[]) {
    int input[] = {31, 41, 59, 26, 41, 58};
    int size = (int) sizeof(input) / sizeof(int);

    printf("Stampo l'array in input\n");
    printArray(input, size);

    printf("Stampo l'array in input ordinato secondo insertionsort\n");
    insertionsort(input, size);
    printArray(input, size);

    return 0;
}