#!/bin/bash
# helloWorld/c#/run.sh

# execute c# helloWorld
function run () {
    mcs -out:main.exe ./src/main.cs
    mono ./main.exe
    rm ./main.exe
}

lang="c#"

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