#!/bin/bash
# helloWorld/c++/run.sh

# execute c++ helloWorld
function run () {
    g++ ./src/main.cpp -o main
    ./main
    rm main
}

case $PWD in
    */c++) run ;;
    *) cd ./c++; run ;;
esac