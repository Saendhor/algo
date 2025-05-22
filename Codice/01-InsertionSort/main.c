#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../misc/printarray.h"
#include "insertionsort.h"
#include "reverse_insertionsort.h"

int main(int argc, char* argv[]) {
    int input[] = {31, 41, 59, 26, 41, 58};
    int size = (int) sizeof(input) / sizeof(int);

    float input_f[] = {31.1, 41, 59, 26, 41, 58};
    int size_f = (int) sizeof(input_f) / sizeof(float);

    //INT
    printf("Stampo l'array in input\n");
    printarray(input, size);

    printf("Stampo l'array in input ordinato secondo insertionsort\n");
    insertionsort(input, size);
    printarray(input, size);

    printf("Stampo l'array in input ordinato secondo reverse_insertionsort\n");
    if (reverse_insertionsort(input, size) != 0) {
        perror("Error while performing insertionsort");
        exit(EXIT_FAILURE);
    }
    printarray(input, size);

    //FLOAT
    printf("Stampo l'array in input\n");
    printarray(input_f, size_f);

    printf("Stampo l'array in input ordinato secondo insertionsort\n");
    insertionsort(input_f, size_f);
    printarray(input_f, size_f);

    printf("Stampo l'array in input ordinato secondo insertionsort\n");
    insertionsort(input_f, size_f);
    printarray(input_f, size_f);

    return 0;
}