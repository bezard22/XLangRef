#!/bin/bash
# helloWorld/c#/run.sh

# execute c# helloWorld
function run () {
    mcs -out:main.exe ./src/main.cs
    mono ./main.exe
    rm ./main.exe
}

case $PWD in
    */c#) run ;;
    *) cd ./c#; run ;;
esac