// sort/c/src/sort/array.c

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "array.h"

/*
------------------------------------------------------------------------
    array  -  expanded array functionality
------------------------------------------------------------------------
*/

// array constructor
array * newArray(float *ar, size_t len, bool arMem) {
    array *newAr = (array*)malloc(sizeof(array));
    newAr->len = len;
    newAr->ar = ar;
    newAr->arMem = arMem;
    return newAr;
}

// print array to the terminal
void printArray(array *arptr) {
    for(size_t i = 0; i < arptr->len; i++) {
        printf("%.3f, ", arptr->ar[i]);
    } 
    printf("\n");
}

// slice subset of an array
array * slice(array *arptr, size_t start, size_t end) {
    size_t n = end - start;
    float *arsl = (float*)malloc(sizeof(float) * n);
    size_t i = 0;
    for (size_t j = start; j < end; j++){
        arsl[i] = arptr->ar[j];
        i++;
    }
    return newArray(arsl, n, true);
}

// concatenate two arrays
array * concat(array *arl, array * arr) {
    size_t n = arl->len + arr->len;
    float *arc = (float*)malloc(sizeof(float) * n);
    size_t i = 0;
    for (size_t j = 0; j < arl->len; j++) {
        arc[i] = arl->ar[j];
        i++;
    }
    for (size_t j = 0; j < arr->len; j++) {
        arc[i] = arr->ar[j];
        i++;
    }
    return newArray(arc, n, true);
}

array * copy(array *arptr) {
    float *newAr = (float*)malloc(sizeof(float) * arptr->len);
    for (size_t i = 0; i < arptr->len; i++){
        newAr[i] = arptr->ar[i];
    }
    return newArray(newAr, arptr->len, true);
}

void freeArray(array *arptr) {
    if (arptr->arMem) {
        free(arptr->ar);
    }
    free(arptr);
}