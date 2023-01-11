// sort/c/src/main.c

#include <stdio.h>
#include <argp.h>
#include <stdlib.h>
#include <time.h>
#include "sort/sort.h"

/*
------------------------------------------------------------------------
    sort  -   demonstrates functionality of several sort algorithms
------------------------------------------------------------------------
*/

// struct arguments {
//     char *args[2];
//     int verbose;
// };

// const struct argp_option options[] = {
//     {"algo", 'a', 0, 0, "sorting algorithm to use"},
// };

// static error_t parse_opt(int key, char *arg, struct argp_state *state) {
//     struct arguments *arguments = state->input;

//     switch (key) {
//     case /* constant-expression */:
//         /* code */
//         break;
    
//     default:
//         break;
//     }
// }


int main() {
    size_t n = 100000;
    char *algo = "quick";


    float *ar_ = malloc(sizeof(float) * n);
    for (size_t i = 0; i < n; i++){
        ar_[i] = (float)rand() / (float)rand();
    }
    array *ar = newArray(ar_, n, true);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    quickSort(ar, false);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("Sorted array of size %ld in %lu ms using %sSort.\n", n, elapsed, algo);
}