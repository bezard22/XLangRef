// sort/c/src/sort/selectionSort.c

#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    bubbleSort  -   selection sort implementation
------------------------------------------------------------------------
*/

// Selection sort function.
void selectionSort(array *arptr, bool rev) {
    for (size_t i = 0; i < arptr->len; i++) {
        size_t minIndex = i;
        for (size_t j = i; j < arptr->len; j++) {
            if ((!rev && arptr->ar[j] < arptr->ar[minIndex]) || (rev && arptr->ar[j] > arptr->ar[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex > i) {
            swap(arptr, i, minIndex);
        }
    }
}