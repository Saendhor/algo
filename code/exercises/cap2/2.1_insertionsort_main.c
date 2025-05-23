#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../mycollection/printarray.h"
#include "../../mycollection/insertionsort.h"
#include "../../mycollection/reverse_insertionsort.h"

//pag 17 n2.1-1, n2.1-2
int main(int argc, char* argv[]) {
    int input[] = {31, 41, 59, 26, 41, 58};
    int size = (int) sizeof(input) / sizeof(int);

    float input_f[] = {31.1, 41, 59, 26, 41, 58};
    int size_f = (int) sizeof(input_f) / sizeof(float);

    //INT
    printf("Stampo l'array in input\n");
    printarray_i(input, size);

    printf("Stampo l'array in input ordinato secondo insertionsort\n");
    insertionsort_i(input, size);
    printarray_i(input, size);

    printf("Stampo l'array in input ordinato secondo reverse_insertionsort\n");
    if (reverse_insertionsort(input, size) != 0) {
        perror("Error while performing insertionsort");
        exit(EXIT_FAILURE);
    }
    printarray_i(input, size);

    //FLOAT
    printf("Stampo l'array in input\n");
    printarray_f(input_f, size_f);

    printf("Stampo l'array in input ordinato secondo insertionsort\n");
    insertionsort_f(input_f, size_f);
    printarray_f(input_f, size_f);

    return 0;
}
