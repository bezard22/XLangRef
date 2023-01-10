// sort/c/src/sort/selectionSort.c

#include <stdio.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    bubbleSort  -   selection sort implementation
------------------------------------------------------------------------
*/

// Selection sort function.
void selectionSort(array *arptr, int rev) {
    for (int i = 0; i < arptr->len; i++) {
        int minIndex = i;
        for (int j = i; j < arptr->len; j++) {
            if ((!rev && arptr->ar[j] < arptr->ar[minIndex]) || (rev && arptr->ar[j] > arptr->ar[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex > i) {
            swap(arptr, i, minIndex);
        }
    }
}