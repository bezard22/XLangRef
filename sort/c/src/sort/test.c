// sort/c/src/test.c

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    test  -   test script for sort library
------------------------------------------------------------------------
*/

void checkArray(array *arptr, float *ar) {
    for (size_t i = 0; i < arptr->len; i++){
        assert(arptr->ar[i] == ar[i]);
    }
}

int main(){
    void (*funcs[5])(array *arptr, bool rev) = {
        &bubbleSort,
        &selectionSort,
        &insertionSort,
        &mergeSort,
        &quickSort,
    };

    size_t testSizes[6] = {0.0, 1.0, 5.0, 5.0, 5.0, 5.0};

    // test arrays
    float *testArrays[6];
    float ar0[0] = {};
    testArrays[0] = ar0;
    float ar1[1] = {1.0};
    testArrays[1] = ar1;
    float ar2[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    testArrays[2] = ar2;
    float ar3[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    testArrays[3] = ar3;
    float ar4[5] = {-2.0, -1.0, 0.0, 1.0, 2.0};
    testArrays[4] = ar4;
    float ar5[5] = {2.0, 1.0, 0.0, -1.0, -2.0};
    testArrays[5] = ar5;

    // forward arrays
    float *fwdArrays[6];
    float fwdar0[0] = {};
    fwdArrays[0] = fwdar0;
    float fwdar1[1] = {1.0};
    fwdArrays[1] = fwdar1;
    float fwdar2[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    fwdArrays[2] = fwdar2;
    float fwdar3[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    fwdArrays[3] = fwdar3;
    float fwdar4[5] = {-2.0, -1.0, 0.0, 1.0, 2.0};
    fwdArrays[4] = fwdar4;
    float fwdar5[5] = {-2.0, -1.0, 0.0, 1.0, 2.0};
    fwdArrays[5] = fwdar5;

    // reverse arrays
    float *revArrays[6];
    float revar0[0] = {};
    revArrays[0] = revar0;
    float revar1[1] = {1.0};
    revArrays[1] = revar1;
    float revar2[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    revArrays[2] = revar2;
    float revar3[5] = {5.0, 4.0, 3.0, 2.0, 1.0};
    revArrays[3] = revar3;
    float revar4[5] = {2.0, 1.0, 0.0, -1.0, -2.0};
    revArrays[4] = revar4;
    float revar5[5] = {2.0, 1.0, 0.0, -1.0, -2.0};
    revArrays[5] = revar5;
    
    
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            array *fwd = newArray(testArrays[i], testSizes[i], false);
            array *rev = copy(fwd);
            (*funcs[j])(fwd, false);
            (*funcs[j])(rev, true);;
            checkArray(fwd, fwdArrays[i]);
            checkArray(rev, revArrays[i]);
            freeArray(fwd);
            freeArray(rev);
        }
    }
    printf("All tests passed.\n");
}