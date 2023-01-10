// sort/c/src/main.c

#include "sort/sort.h"
// #include "sort/array.h"

/*
*/

enum algos  {
    bubble=0,
    selection=1,
    insertion=2,
    // merge=3,
};

void test(enum algos algo, int rev) {
    int test[5] = {5, 1, 4, 2, 8};
    array *arptr = newArray(test, 5);
    printArray(arptr);
    switch (algo){
        case bubble:
            bubbleSort(arptr, rev);
            break;
        case selection:
            selectionSort(arptr, rev);
            break;
        case insertion:
            insertionSort(arptr, rev);
            break;
        // case merge:
        //     mergeSort(arptr, rev);
        //     break;
    }
    printArray(arptr);
}

// Main function
int main(void) {
    int test[5] = {5, 1, 4, 2, 8};
    array *arptr = newArray(test, 5);
    mergeSort(arptr, 0);
    // for (int i = 0; i <=2; i++){
    //     test(i, 0);
    //     test(i, 1);
    // }
}