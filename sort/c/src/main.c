// sort/c/src/main.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <time.h>

#include "sort/sort.h"

// main arguments
struct arguments {
    char *ar, *algo, *n;
    bool verbose, timed;
};

// usage function
void usage(){
    printf("Sorting Utility. supports integer, floating point and negative numbers\n\n");
    printf("positional arguments:\n");
    printf("  ar                    array to be sorted, entered as comma seperated string\n\n");
    printf("options:\n");
    printf("  -h, --help            show this help message and exit\n");
    printf("  -a {bubble,insertion,selection,merge,quick}, --algo {bubble,insertion,selection,merge,quick}\n");
    printf("                        sorting algorithm to use\n");
    printf("  -n N                  generate and sort a random array of length n\n");
    printf("  -t, --timed           time sorting execution\n");
    printf("  -v, --verbose         Verbose output, full arrays will be printed\n");
    exit(0);
}

// parse arguments
void parseArgs(struct arguments *argptr, int argc, char* argv[]){
    int next_option;
    const char* const short_options = "hvtn:a:";

    const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {"verbose", 0, NULL, 'v'},
        {"timed", 0, NULL, 't'},
        {"algo", 0, NULL, 'a'},
        {NULL, 0, NULL, 0},
    };

    while (next_option != -1) {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option){
            case 'h':
                usage();
                break;
            
            case 'v':
                argptr->verbose = true;
                break;
            
            case 't':
                argptr->timed = true;
                break;
            
            case 'n':
                argptr->n = optarg;
                break;
            
            case 'a':
                argptr->algo = optarg;
                break;
            
            case '?':
                usage();
                break;

            case -1:
                break;

            default:
                abort();
        }
    }

    for (size_t i = optind; i < argc; i++){
        if (argptr->ar == NULL){
            argptr->ar = argv[i];
        } else {
            printf("Unexpected positional argument: %s\n", argv[i]);
            usage();
        }
    }

}

// sort functions
void (*funcs[5])(array *arptr, bool rev) = {
    &bubbleSort,
    &insertionSort,
    &selectionSort,
    &mergeSort,
    &quickSort,
};

// sorting algorithms enum
enum algos {
    bubble=0,
    insertion=1,
    selection=2,
    merge=3,
    quick=4,
};

// sorting algorithms strings
const char *algoStr[5] = {
    "bubble",
    "insertion",
    "selection",
    "merge",
    "quick",
};

// check whether a string contain a digit character 0-9
bool digitStr(char *str) {
    while (*str) {
        if (isdigit(*str++)) {
            return true;
        }
    }
    return false;
}

// replace a character in the given string
void strReplace(char *str, char find, char replace) {
    char *cur = strchr(str, find);
    while (cur) {
        *cur = replace;
        cur = strchr(str, find);
    }
}

// validate array string
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

// build array based on array string
array * extractAr(char *arstr, int *nptr) {
    for (size_t i = 0; i < strlen(arstr); i++){
        if (arstr[i] == ',') {
            *nptr = *nptr + 1;
        }
    }
    float *ar_ = malloc(sizeof(float) * *nptr);

    char *token;
    const char delim[2] = ",";
    token = strtok(arstr, delim);
    size_t i = 0;
    while (token != NULL){
        ar_[i] = atof(token);
        token = strtok(NULL, delim);
        i++;
    }
    return newArray(ar_, *nptr, true);
}

// main function
int main(int argc, char* argv[]){
    // instantiate arguments
    struct arguments arguments;
    arguments.verbose = false;
    arguments.timed = false;

    // check for negative values
    bool negative = false;
    for (size_t i = 0; i < argc; i++){
        if (digitStr(argv[i])) {
            strReplace(argv[i], '-', 'n');
            negative = true;
        }
    }

    // parse arguments
    parseArgs(&arguments, argc, argv);

    // validate arguments
    if (arguments.ar == NULL && arguments.n == NULL){
        printf("Please either provide an array to be sorted, or specify the length of array to generate using -n\n");
        exit(0);
    }
    if (arguments.ar != NULL && arguments.n != NULL){
        printf("The -n flag generates a random array to be sorted of size n. An array argument should not be passed with -n\n");
        exit(0);
    }

    // set array
    array *arptr;
    int n;
    if (arguments.ar != NULL){
        // add negative character back in
        if (negative) {
            strReplace(arguments.ar, 'n', '-');
        }

        // validate and extract 
        valArStr(arguments.ar);
        arptr = extractAr(arguments.ar, &n);
    } else {
        n = (int)atof(arguments.n);
        srand(time(NULL));
        float *ar_ = malloc(sizeof(float) * n);
        for (size_t i = 0; i < n; i++){
            ar_[i] = rand() % 9;
        }
        arptr = newArray(ar_, n, true);
    }


    int algo = quick;
    // update algorithm if second positional is passed
    if (arguments.algo != NULL){
        if (strcmp(arguments.algo, "bubble") == 0) {
            algo=bubble;
        } else if (strcmp(arguments.algo, "insertion") == 0) {
            algo=insertion;
        } else if (strcmp(arguments.algo, "selection") == 0) {
            algo=selection;
        } else if (strcmp(arguments.algo, "merge") == 0) {
            algo=merge;
        } else if (strcmp(arguments.algo, "quick") == 0) {
            algo=quick;
        } else {
            printf("Unrecognized algo argumnet: %s\n", arguments.algo);
            exit(0);
        }
    }

    // sort array
    if (arguments.timed) {
        clock_t start, end;
        double timeTaken;

        if (arguments.verbose) {
            printf("Original ");
            printArray(arptr);
            start = clock();
            (*funcs[algo])(arptr, false);
            end = clock();
            printf("Sorted: ");
            printArray(arptr);
        } else {
            start = clock();
            (*funcs[algo])(arptr, false);
            end = clock();
        }
        printf("Sorted array of size n in %.3f seconds using %sSort.\n", (((double)(end - start)) / CLOCKS_PER_SEC), algoStr[algo]);
    } else {
        if (arguments.verbose) {
            printf("Original: ");
            printArray(arptr);
            (*funcs[algo])(arptr, false);
            printf("Sorted: ");
            printArray(arptr);
        } else {
            (*funcs[algo])(arptr, false);
        }
    }

    exit(0);
}