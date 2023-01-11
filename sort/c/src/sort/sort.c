// sort/c/src/sort/sort.c

#include "sort.h"

/*
------------------------------------------------------------------------
    sort  -  Common functions for sorting
------------------------------------------------------------------------
*/

// swap the values in the given array and indeces i and j.
void swap(array *arptr, size_t i, size_t j) {
    float tmp = arptr->ar[i];
    arptr->ar[i] = arptr->ar[j];
    arptr->ar[j] = tmp;
}