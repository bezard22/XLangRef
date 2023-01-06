#!/bin/bash
# /helloWorld/rust/run.sh

# execute rust helloWorld
function run () {
    rustc ./src/main.rs
    ./main
    rm ./main
}

case $PWD in
    */rust) run ;;
    *) cd ./rust; run ;;
esac