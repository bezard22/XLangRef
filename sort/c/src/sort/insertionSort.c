// sort/c/src/sort/insertionSort.c

#include <stdio.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    insertionSort  -   insertion sort implementation
------------------------------------------------------------------------
*/

// Insertion sort function.
void insertionSort(array *arptr, int rev) {
    for (int i = 0; i < arptr->len; i++) {
        int j = i;
        while (j > 0 && ((!rev && arptr->ar[j - 1] > arptr->ar[j]) || (rev && arptr->ar[j - 1] < arptr->ar[j]))){
            swap(arptr, j, j - 1);
            j -= 1;
        }
    }
    
}