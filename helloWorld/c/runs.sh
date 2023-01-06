#!/bin/bash
# helloWorld/c/runs.sh

# execute c helloWorld
function run () {
    gcc ./src/main.c -o main
    ./main
    rm ./main
}

case $PWD in
    */c) run ;;
    *) cd ./c; run ;;
esac