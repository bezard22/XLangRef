#!/bin/bash
# helloWorld/javascript/run.sh

# execute javascript helloWorld
function run () {
    node ./src/main.js
}

case $PWD in
    */javascript) run ;;
    *) cd ./javascript; run ;;
esac