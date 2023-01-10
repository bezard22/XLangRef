// sort/c/src/sort/array.c

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "array.h"

/*
------------------------------------------------------------------------
    array  -  expanded array functionality
------------------------------------------------------------------------
*/

// array constructor
array * newArray(int *ar, size_t len) {
    array *newAr = malloc(sizeof(array));
    newAr->len = len;
    newAr->ar = ar;
    return newAr;
}

// print array to the terminal
void printArray(array *arptr) {
    for(int i = 0; i < arptr->len; i++) {
        printf("%d, ", arptr->ar[i]);
    } 
    printf("\n");
}

// slice subset of an array
array * slice(array *arptr, int start, int end) {
    int n = end - start;
    int *arsl = malloc(sizeof(int) * n);
    int i = 0;
    for (int j = start; j < end; j++){
        arsl[i] = arptr->ar[j];
        i++;
    }
    return newArray(arsl, n);
}

// concatenate two arrays
array * concat(array *arl, array * arr) {
    int n = arl->len + arr->len;
    int *arc = malloc(sizeof(int) * n);
    int i = 0;
    for (int j = 0; j < arl->len; j++) {
        arc[i] = arl->ar[j];
        i++;
    }
    for (int j = 0; j < arr->len; j++) {
        arc[i] = arr->ar[j];
        i++;
    }
    return newArray(arc, n);
}

array * copy(array *arptr) {
    int *newAr = malloc(sizeof(int) * arptr->len);
    for (size_t i = 0; i < arptr->len; i++){
        newAr[i] = arptr->ar[i];
    }
    return newArray(newAr, arptr->len);
}