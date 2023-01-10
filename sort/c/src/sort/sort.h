// sort/c/src/sort.h

#include "array.h"

/*
------------------------------------------------------------------------
    sort.h  -   sort header file
------------------------------------------------------------------------
*/

// from sort.c
void swap(array *arptr, int i, int j);

// from bubbelSort.c
void bubbleSort(array *arptr, int rev);

// from selectionSort.c
void selectionSort(array *arptr, int rev);

// from insertionSort.c
void insertionSort(array *arptr, int rev);

// from mergeSort.c
void mergeSort(array *arptr, int rev);

// from quickSort.c
void quickSort(array *arptr, int rev);