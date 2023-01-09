// sort/c/src/sort.c

#include <stdio.h>

/*
------------------------------------------------------------------------
    _sort  -  Common functions for sorting
------------------------------------------------------------------------
*/

// array object
struct array {
    int len;
    int *ar;
};

// array constructor
void newArray(struct array *arptr, int *ar, int len) {
    arptr->len = len;
    arptr->ar = ar;
}

// print array to the terminal
void printArray(struct array *arptr) {
    int i;
        for(i = 0; i < arptr->len; i++) {
            printf("%d, ", arptr->ar[i]);
        } 
        printf("\n");
}

// swap the values in the given array and indeces i and j.
void swap(struct array *arptr, int i, int j) {
    int tmp = arptr->ar[i];
    arptr->ar[i] = arptr->ar[j];
    arptr->ar[j] = tmp;
}

int main(void) {
    int test[5] = {5, 1, 4, 2, 8};
    struct array ar;
    newArray(&ar, test, 5);
    printArray(&ar);
    swap(&ar, 0, 1);
    printArray(&ar);
}