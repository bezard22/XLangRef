// basics/c/src/types/arrays.c

#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------------------
//     arrays  -   arrays in c
// ------------------------------------------------------------------------

// C arrays are fixed type, fixed size

void main(){
    // declare array with size known at compile-time
    int a[10];

    // declare array with size known at runtime
    int n = 10;
    int *b = (int*)malloc(sizeof(int) * n);
    free(b);

    // declare array and instantiate with array literal
    int c[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // index array
    int i = c[0];

    // length of array
    size_t len = sizeof(c) / sizeof(int);

    // iterate through array
    for (size_t i = 0; i < len; i++){
        printf("%d\n", c[i]);
    }

    // print array
    for (size_t i = 0; i < len; i++){
        printf("%d, ", c[i]);
    }
    printf("\n");

    // multidimensional array
    int d[5][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 25},
    };
    
    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 5; j++){
               printf("%d, ", d[i][j]);
        }
        printf("\n");
    }
    

}
