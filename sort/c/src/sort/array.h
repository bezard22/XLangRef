// sort/c/src/sort.h

#include <stddef.h>
#include <stdbool.h>

/*
------------------------------------------------------------------------
    array.h  -   array header file
------------------------------------------------------------------------
*/

// array object
struct array {
    float *ar;
    size_t len;
    bool arMem;
};

typedef struct array array;

// from array.c
array * newArray(float *ar, size_t len, bool arMem);
void printArray(array *arptr);
array * slice(array *arptr, size_t start, size_t end);
array * concat(array *arl, array * arr);
array * copy(array *arptr);
void freeArray(array *arptr);