// sort/c/src/sort/mergeSort.c

#include <stdio.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    mergeSort  -   merge sort implementation
------------------------------------------------------------------------
*/

array * merge(array *arl, array *arr, int rev) {
    if (arl->len == 0) {
        return arr;
    }
    if (arr->len == 0) {
        return arl;
    } 
    if ((!rev && arl->ar[0] <= arr->ar[0]) || (rev && arl->ar[0] >= arr->ar[0])) {
        array *newArl = slice(arl, 1, arl->len);
        return concat(slice(arl, 0, 1), merge(newArl, arr, rev));
    } else {
        array *newArr = slice(arr, 1, arr->len);
        return concat(slice(arr, 0, 1), merge(arl, newArr, rev));
    }
}

// merge sort function.
void mergeSort(array *arptr, int rev) {
    int n = arptr->len;
    if (n > 1) {
        array *arl = slice(arptr, 0, n / 2);
        array *arr = slice(arptr, n / 2, n);

        mergeSort(arl, rev);
        mergeSort(arr, rev);
        *arptr = *merge(arl, arr, rev);
    }
}