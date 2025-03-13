/*

DEVO CREARE UN MAXHEAP


int getLeft(i){
    i=i << 1;
}

int getRight(i){
    i= i << 1 | 1;
}

int getParent(i){
    i= i/2;
}

BuildMaxHeap(A){
    A.heapsize=A.length;
    for(int i=A.length/2, i>0, i--){    //fa il floor
        MaxHeapify(A,i);
    }
}

MaxHeapify(A,i){
    l=getLeft(i);
    r=getRight(i);
    if(l<=A.heapsize && A[l]>A[i]){
        massimo=l;
    }
    else { massimo = i; }

    if(r<=A.heapsize && A[r]>A[massimo]){
        massimo=r;
    }

    if(massimo != i){
        swap (A[i],A[massimo]);
        MaxHeapify(A, massimo);
    }
}

Heapsort(A){
    BuildMaxHeap(A);
    for(int i= A.length; i>1; i--){
        swap (A[1].A[i]);
        A.heapsize = A.heapsize-1;
        MaxHeapify(A,1);
    }
}

output.txt
1 1 1 1 1 1 1 0 0 0
93 86 93 56 56 18 41 53 52 30
9.94 8.28 9.58 8.28 7.22 2.06 3.88 0.95 7.2 3.95 


*/