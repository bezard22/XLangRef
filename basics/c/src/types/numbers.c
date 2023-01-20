// basics/c/src/types/numbers.c

#include <stdio.h>

// ------------------------------------------------------------------------
//     numbers  -   numeric data types in C
// ------------------------------------------------------------------------

void main(){
    int a = -100;               // integer (4 bytes) -2,147,483,648 to 2,147,483,647
    short int b = -1;           // short integer (2 bytes) -32,768 to 32,767
    long int c = -1e9;          // long integer (4 bytes) -2,147,483,648 to 2,147,483,647
    unsigned int d = 1;         // unsigned integer (6 bytes) 0 to 4,294,967,295
    unsigned short int e = 100; // unsigned short integer (2 bytes) 0 to 65,535
    unsigned long int f = 1e9;  // unsigned long integer (2 bytes) 0 to 4,294,967,295
    float g = 1.1;              //float (4 bytes) 1.2E-38 to 3.4E+38
    double h = 1.1e39;            //double (8 bytes) 1.7E-308 to 1.7E+308

    // printing
    printf("integer: %d\n", a);
    printf("short integer: %hd\n", b);
    printf("long integer: %ld\n", c);
    printf("unsigned integer: %u\n", d);
    printf("unsigned shortinteger: %hu\n", e);
    printf("unsigned long integer: %lu\n", f);
    printf("float: %f\n", g);
    printf("double: %lf\n", h);
}
