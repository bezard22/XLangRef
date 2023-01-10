// sort/c/src/sort.h

#include <stddef.h>

/*
------------------------------------------------------------------------
    array.h  -   array header file
------------------------------------------------------------------------
*/

// array object
struct array {
    int *ar;
    size_t len;
};

typedef struct array array;

// from array.c
array * newArray(int *ar, size_t n);
void printArray(array *arptr);
array * slice(array *arptr, int start, int end);
array * concat(array *arl, array * arr);
array * copy(array *arptr);