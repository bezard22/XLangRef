#!/bin/bash
# sort/c/run.sh

# run c sort
gcc -o sortUtil \
	./src/sort/array.c \
	./src/sort/sort.c \
	./src/sort/bubbleSort.c \
	./src/sort/selectionSort.c \
	./src/sort/insertionSort.c \
	./src/sort/mergeSort.c \
	./src/sort/quickSort.c \
	./src/main.c
./sortUtil "$@"
rm ./sortUtil