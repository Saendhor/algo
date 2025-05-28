#include <stdio.h>

#include "../../mycollection/printarray.h"
#include "../../mycollection/selectionsort.h"

int main(int argc, char* argv[]) {
    int input[] = {4, 9, 10, 21, 2, 64, 5};
    int size = (int) sizeof(input) / sizeof(int);

    printf("[MAIN] Printing inputed array\n");
    printarray_i(input, size);

    selectionsort_i(input, size);
    printf("[MAIN] Printing inputed array after selectionsort\n");
    printarray_i(input, size);

    return 0;
}