#!/bin/bash
# helloWorld/go/run.sh

# execute go helloWorld
function run () {
    go run ./src/main.go
}

case $PWD in
    */go) run ;;
    *) cd ./go; run ;;
esac