#include <stdio.h>

#include "../../mycollection/heap.h"
#include "../../mycollection/printarray.h"

int main(int argc, char* argv[]) {
    heap_t myheap = createheap(10);
    for (int i = 0; i < myheap.size - 2; i++) {
        myheap.array[i] = 70+i % 3;
    }
    printarray_i(myheap.array, myheap.size);

    return 0;
}