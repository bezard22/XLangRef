// sort/c/src/sort/array.c

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

/*
------------------------------------------------------------------------
    array  -  expanded array functionality
------------------------------------------------------------------------
*/

// array constructor
array * newArray(int *ar, int len) {
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
    array *newAr = newArray(arsl, n);
    return newAr;
}