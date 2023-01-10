// sort/c/src/test.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort/sort.h"

/*
------------------------------------------------------------------------
    sort  -   test script for sort
------------------------------------------------------------------------
*/

void checkArray(array *arptr, int *ar) {
    for (size_t i = 0; i < arptr->len; i++){
        assert(arptr->ar[i] == ar[i]);
    }
}

int main(){
    void (*funcs[5])(array *arptr, int rev) = {
        &bubbleSort,
        &selectionSort,
        &insertionSort,
        &mergeSort,
        &quickSort,
    };

    int testSizes[6] = {0, 1, 5, 5, 5, 5};

    // test arrays
    int *testArrays[6];
    int ar0[0] = {};
    testArrays[0] = ar0;
    int ar1[1] = {1};
    testArrays[1] = ar1;
    int ar2[5] = {1, 2, 3, 4, 5};
    testArrays[2] = ar2;
    int ar3[5] = {5, 4, 3, 2, 1};
    testArrays[3] = ar3;
    int ar4[5] = {-2, -1, 0, 1, 2};
    testArrays[4] = ar4;
    int ar5[5] = {2, 1, 0, -1, -2};
    testArrays[5] = ar5;

    // forward arrays
    int *fwdArrays[6];
    int fwdar0[0] = {};
    fwdArrays[0] = fwdar0;
    int fwdar1[1] = {1};
    fwdArrays[1] = fwdar1;
    int fwdar2[5] = {1, 2, 3, 4, 5};
    fwdArrays[2] = fwdar2;
    int fwdar3[5] = {1, 2, 3, 4, 5};
    fwdArrays[3] = fwdar3;
    int fwdar4[5] = {-2, -1, 0, 1, 2};
    fwdArrays[4] = fwdar4;
    int fwdar5[5] = {-2, -1, 0, 1, 2};
    fwdArrays[5] = fwdar5;

    // reverse arrays
    int *revArrays[6];
    int revar0[0] = {};
    revArrays[0] = revar0;
    int revar1[1] = {1};
    revArrays[1] = revar1;
    int revar2[5] = {5, 4, 3, 2, 1};
    revArrays[2] = revar2;
    int revar3[5] = {5, 4, 3, 2, 1};
    revArrays[3] = revar3;
    int revar4[5] = {2, 1, 0, -1, -2};
    revArrays[4] = revar4;
    int revar5[5] = {2, 1, 0, -1, -2};
    revArrays[5] = revar5;
    
    
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            array *fwd = newArray(testArrays[i], testSizes[i]);
            array *rev = copy(fwd);
            bubbleSort(fwd, 0);
            bubbleSort(rev, 1);
            checkArray(fwd, fwdArrays[i]);
            checkArray(rev, revArrays[i]);
        }
    }
    printf("All tests passed.\n");
}