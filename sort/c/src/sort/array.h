// sort/c/src/sort.h


/*
------------------------------------------------------------------------
    array.h  -   array header file
------------------------------------------------------------------------
*/

// array object
struct array {
    int len;
    int *ar;
};

typedef struct array array;

// from array.c
array * newArray(int *ar_, int len);
void printArray(array *arptr);
array * slice(array *arptr, int start, int end);