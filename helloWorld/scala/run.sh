#!/bin/bash
# helloWorld/scala/run.sh

# execute scala helloWorld
function run () {
    scalac ./src/main.scala
    scala main
    rm ./main.class
    rm ./main$.class
}

case $PWD in
    */scala) run ;;
    *) cd ./scala; run ;;
esac