#include <stdio.h>

#include "../../mycollection/heap.h"
#include "../../mycollection/printarray.h"

int main(int argc, char* argv[]) {
    heap_t myheap = createheap(10);
    for (myheap.heap_size = 0; myheap.heap_size < myheap.total_size - 2; myheap.heap_size++) {
        myheap.array[myheap.heap_size] = (70 + myheap.heap_size) % 3 + 1;
    }
    printarray_i(myheap.array, myheap.total_size);

    printf("Building heap\n");
    build_max_heap_i(myheap);
    printarray_i(myheap.array, myheap.total_size);

    printf("SIZE: %d\tHEAPSIZE: %d\n", myheap.total_size, myheap.heap_size);

    return 0;
}