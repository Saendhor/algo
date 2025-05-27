#include <stdio.h>
#include <unistd.h>

#include "../../mycollection/mergesort.h"
#include "../../mycollection/printarray.h"

//pag 30 n2.3-1
int main(int argc, char* argv[]) {
    int input[] =  {3, 41, 52, 26, 38, 57, 9, 49};
    int size = (int) sizeof(input) / sizeof(int);

    printf("[MAIN] Printing given input\n");
    printarray_i(input, size);

    printf("[MAIN] Printing array after mergesort\n");
    mergesort(input, 0, size-1);
    printarray_i(input, size);


    return 0;
}