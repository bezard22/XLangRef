// sort/c/src/sort/insertionSort.c

#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    insertionSort  -   insertion sort implementation
------------------------------------------------------------------------
*/

// Insertion sort function.
void insertionSort(array *arptr, bool rev) {
    if (arptr->len > 1){
        for (size_t i = 0; i < arptr->len; i++) {
            size_t j = i;
            while (j > 0 && ((!rev && arptr->ar[j - 1] > arptr->ar[j]) || (rev && arptr->ar[j - 1] < arptr->ar[j]))){
                swap(arptr, j, j - 1);
                j -= 1;
            }
        }
    }
}