#!/bin/bash
# basics/c/run.sh

# numbers
echo numbers:
gcc ./src/types/numbers.c -o numbers
./numbers
rm ./numbers
echo ""

# arrays
echo arrays:
gcc ./src/types/arrays.c -o arrays
./arrays
rm ./arrays
echo ""