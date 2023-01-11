// sort/c/src/main.c

#include <stdio.h>
#include <argp.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <regex.h>
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

// sort functions
void (*funcs[5])(array *arptr, bool rev) = {
    &bubbleSort,
    &insertionSort,
    &selectionSort,
    &mergeSort,
    &quickSort,
};

enum algos {
    bubble=0,
    insertion=1,
    selection=2,
    merge=3,
    quick=4,
};

const char *algoStr[5] = {
    "bubble",
    "insertion",
    "selection",
    "merge",
    "quick",
};

bool valArStr(char *arStr) {
    char *expr = "^(([-]{0,1}[[:digit:]]{1,}([.][[:digit:]]*){0,1})[,]{0,1}[[:space:]]{0,1}){1,}$";
    regex_t regex;
    int regi;
    // regi = regcomp(&regex, "((-/?[[:digit:]]+([.]([[:digit:]])+)?),([[:space:]])*)+((-?[[:digit:]]+([.]([[:digit:]])+)?),?([[:space:]])*)", 0);
    regi = regcomp(&regex, expr, REG_EXTENDED);
    if (regi) {
        printf("regex compiliation error\n");
        exit(0);
    }

    regi = regexec(&regex, arStr, 0, NULL, 0);
    return (!regi);
}

bool digitStr(char *str) {
    while (*str) {
        if (isdigit(*str++)) {
            return true;
        }
    }
    return false;
}

void strReplace(char *str, char find, char replace) {
    char *cur = strchr(str, find);
    while (cur) {
        *cur = replace;
        cur = strchr(str, find);
    }
}

array * extractAr(char *arstr) {
    int n = 1;
    for (size_t i = 0; i < strlen(arstr); i++){
        if (arstr[i] == ',') {
            n++;
        }
    }
    float *ar_ = malloc(sizeof(float) * n);

    char *cur = strchr(arstr, ',');
    while (cur) {
        printf("%d\n", cur);
        *cur = 'c';
        cur = strchr(arstr, ',');
    }

    
}

// main function
int main(int argc, char **argv) {
    bool nAr = false;
    for (size_t i = 0; i < argc; i++){
        if (digitStr(argv[i])) {
            strReplace(argv[i], '-', 'n');
            nAr = true;
            break;
        }
    }
    

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

    int algo = quick;
    int ari = 0;
    array *arptr;


    if (strcmp(arguments.args[1], "") > 0){
        if (strcmp(arguments.args[0], "bubble") == 0) {
            algo=bubble;
        } else if (strcmp(arguments.args[0], "insertion") == 0) {
            algo=insertion;
        } else if (strcmp(arguments.args[0], "selection") == 0) {
            algo=selection;
        } else if (strcmp(arguments.args[0], "merge") == 0) {
            algo=merge;
        } else if (strcmp(arguments.args[0], "quick") == 0) {
            algo=quick;
        } else {
            printf("Unrecognized algo argumnet: %s\n", arguments.args[0]);
            exit(0);
        }
        if (!arguments.nflag){
            ari = 1;
        }
    }

    if (nAr) {
        strReplace(arguments.args[ari], 'n', '-');    
    }
    valArStr(arguments.args[ari]);
    extractAr(arguments.args[ari]);
    

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