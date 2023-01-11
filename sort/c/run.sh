#!/bin/bash
# sort/c/run.sh

# Execute c sort
gcc -o sortMain \
	./src/sort/array.c \
	./src/sort/sort.c \
	./src/sort/bubbleSort.c \
	./src/sort/selectionSort.c \
	./src/sort/insertionSort.c \
	./src/sort/mergeSort.c \
	./src/sort/quickSort.c \
	./src/main.c
./sortMain "$1" "$2" "$3"
rm ./sortMain