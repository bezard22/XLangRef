// sort/c/src/sort/quickSort.c

#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    quickSort  -   quick sort implementation
------------------------------------------------------------------------
*/

size_t partition(array *arptr, int low, int high, bool rev) {
    int pi = high;

    float piv = arptr->ar[pi];
    int i = low - 1;
    for (int j = low; j <= high; j++) {
        if ((!rev && arptr->ar[j] < piv) || (rev && arptr->ar[j] > piv)){
            i += 1;
            swap(arptr, i, j);
            if (pi == i) {
                pi = j;
            }
        }
    }
    swap(arptr, i + 1, pi);
    return i + 1;
}

// Recursive quick sort function
void _quickSort(array *arptr, int low, int high, bool rev) {
    if (low < high) {
        int pi = partition(arptr, low, high, rev);
        _quickSort(arptr, low, pi - 1, rev);
        _quickSort(arptr, pi + 1, high, rev);
    }
}

// Quick sort function.
void quickSort(array *arptr, bool rev) {
    if (arptr->len > 1) {
        _quickSort(arptr, 0, arptr->len - 1, rev);
    }
}