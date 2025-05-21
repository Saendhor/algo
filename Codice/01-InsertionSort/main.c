#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[]) {


    return 0;
}

/*  PSEUDOCODICE

    for j ← 2 to length [A]
        do key ← A[j]
            > Inserisce A[j] nella sequenza ordinata A[1 .. j-1]
            i ← j-1
            while i > 0 and A[i] > key
                do A[i+1] ← A[i]
                    i ← i-1
            A[i+1] ← key


*/