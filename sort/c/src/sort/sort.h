// sort/c/src/sort.h

#include "array.h"
#include <stdbool.h>

/*
------------------------------------------------------------------------
    sort.h  -   sort header file
------------------------------------------------------------------------
*/

// from sort.c
void swap(array *arptr, size_t i, size_t j);

// from bubbelSort.c
void bubbleSort(array *arptr, bool rev);

// from selectionSort.c
void selectionSort(array *arptr, bool rev);

// from insertionSort.c
void insertionSort(array *arptr, bool rev);

// from mergeSort.c
void mergeSort(array *arptr, bool rev);

// from quickSort.c
void quickSort(array *arptr, bool rev);