// sort/c/src/sort/mergeSort.c

#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    mergeSort  -   merge sort implementation
------------------------------------------------------------------------
*/

array * merge(array *arl, array *arr, bool rev) {
    if (arl->len == 0) {
        return arr;
    }
    if (arr->len == 0) {
        return arl;
    } 
    if ((!rev && arl->ar[0] <= arr->ar[0]) || (rev && arl->ar[0] >= arr->ar[0])) {
        array *newArl = slice(arl, 1, arl->len);
        array *newAr = concat(slice(arl, 0, 1), merge(newArl, arr, rev));
        freeArray(newArl);
        return newAr;
    } else {
        array *newArr = slice(arr, 1, arr->len);
        array *newAr = concat(slice(arr, 0, 1), merge(arl, newArr, rev));
        freeArray(newArr);
        return newAr;
    }
}

// merge sort function.
void mergeSort(array *arptr, bool rev) {
    if (arptr->len > 1){
        size_t n = arptr->len;
        if (n > 1) {
            array *arl = slice(arptr, 0, n / 2);
            array *arr = slice(arptr, n / 2, n);

            mergeSort(arl, rev);
            mergeSort(arr, rev);
            *arptr = *merge(arl, arr, rev);
            freeArray(arl);
            freeArray(arr);
        }
    }
}