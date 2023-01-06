#!/bin/bash
# helloWorld/c/runs.sh

# execute c helloWorld
function run () {
    gcc ./src/main.c -o main
    ./main
    rm ./main
}

lang="c"

while getopts ':vt' flag; do
    case "${flag}" in 
        v) verbose=1 ;;
        t) timed=1 ;;
    esac
done

function runin () {
    case $PWD in
        */$lang) run ;;
        *) cd ./$lang; run ;;
    esac    
}

if [[ -v verbose ]];
then
    echo "$lang:";
fi
if [[ -v timed ]];
then
    time runin
else
    runin
fi