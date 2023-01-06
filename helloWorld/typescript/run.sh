#!/bin/bash
# helloWorld/typescript/run.sh

# execute typescript helloWorld
function run () {
    tsc ./src/main.ts
    node ./src/main.js
    rm ./src/main.js
}

lang="typescript"

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