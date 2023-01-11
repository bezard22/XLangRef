// sort/c/src/bubbleSort.c

#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

/*
------------------------------------------------------------------------
    bubblSort  -   bubble sort implementation
------------------------------------------------------------------------
*/

// bubble sort function
void bubbleSort(array *arptr, bool rev) {
    // iterate through array
    if (arptr->len > 1){
        int i = 0;
        while (i < arptr->len - 1) {
            if ((!rev && arptr->ar[i] > arptr->ar[i + 1]) || (rev && arptr->ar[i] < arptr->ar[i + 1])) {
                swap(arptr, i, i + 1);
                i -= 1;
            } else {
                i += 1;
            }
            if (i < 0) {
                i = 0;
            }
        }
    }
}