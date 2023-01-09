#!/bin/bash
# helloWorld/typescript/build/build.sh

# build typescript helloWorld
tsc ../src/main.ts
pkg ../src/main.js -o $1
rm ../src/main.js