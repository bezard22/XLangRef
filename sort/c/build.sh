#!/bin/bash
# sort/c/build.sh

# build c sort
mkdir ./bin
gcc -o ./bin/sortUtil \
	./src/sort/array.c \
	./src/sort/sort.c \
	./src/sort/bubbleSort.c \
	./src/sort/selectionSort.c \
	./src/sort/insertionSort.c \
	./src/sort/mergeSort.c \
	./src/sort/quickSort.c \
	./src/main.c