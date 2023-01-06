#!/bin/bash
# helloWorld/python/run.sh

# execute python helloWorld
function run () {
    python ./src/main.py
}

case $PWD in
    */python) run ;;
    *) cd ./python; run ;;
esac