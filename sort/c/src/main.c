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

// main arguments
struct arguments {
    char *args[2];
    bool verbose, timed, nflag;
};

// parser argp_options 
const struct argp_option options[] = {
    {"verbose", 'v', 0, OPTION_ARG_OPTIONAL, "verbose output, full arrays will be printed"},
    {"timed", 't', 0, OPTION_ARG_OPTIONAL, "time sorting execution"},
    {"n", 'n', 0, OPTION_ARG_OPTIONAL, "generate and sort an array length n"},
    {0}
};

// parser doc
static char doc[] = "Sorting Utility. supports integer, floating point and negative numbers";

// parser args_doc
static char args_doc[] = "algo(optional, defaults to quick), [n || array]";

// parser parse_opt function
static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;

    switch (key) {
    case 'v':
        arguments->verbose = true;
        break;
    
    case 't':
        arguments->timed = true;
        break;
    
    case 'n':
        arguments->nflag = true;
        break;
    
    case ARGP_KEY_ARG:
        if (state->arg_num >= 2) {
            argp_usage(state);
        }
        arguments->args[state->arg_num] = arg;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

// parser argp
static struct argp argp = {options, parse_opt, args_doc, doc};

// main function
int main(int argc, char **argv) {
    struct arguments arguments;
    arguments.verbose = false;
    arguments.timed = false;
    arguments.nflag = false;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    printf("args[0]: %s\n", arguments.args[0]);
    printf("args[1]: %s\n", arguments.args[1]);
    printf("verbose: %d\n", arguments.verbose);
    printf("timed: %d\n", arguments.timed);
    printf("nflag: %d\n", arguments.nflag);



    exit(0);

    // size_t n = 100000;
    // char *algo = "quick";


    // float *ar_ = malloc(sizeof(float) * n);
    // for (size_t i = 0; i < n; i++){
    //     ar_[i] = (float)rand() / (float)rand();
    // }
    // array *ar = newArray(ar_, n, true);

    // struct timespec start, end;
    // clock_gettime(CLOCK_MONOTONIC, &start);
    // quickSort(ar, false);
    // clock_gettime(CLOCK_MONOTONIC, &end);
    // long elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    // printf("Sorted array of size %ld in %lu ms using %sSort.\n", n, elapsed, algo);
}