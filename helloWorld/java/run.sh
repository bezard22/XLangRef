#!/bin/bash
# helloWorld/java/run.sh

# execute java helloWorld
function run () {
    java ./src/main.java
}

case $PWD in
    */java) run ;;
    *) cd ./java; run ;;
esac