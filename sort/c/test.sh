#!/bin/bash
# sort/c/test.sh

# test c sort
gcc -o sortLibTest \
	./src/sort/array.c \
	./src/sort/sort.c \
	./src/sort/bubbleSort.c \
	./src/sort/selectionSort.c \
	./src/sort/insertionSort.c \
	./src/sort/mergeSort.c \
	./src/sort/quickSort.c \
	./src/sort/test.c
./sortLibTest
rm ./sortLibTest