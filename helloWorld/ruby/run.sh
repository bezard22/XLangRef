#!/bin/bash
# helloWorld/ruby/run.sh

# execute ruby helloWorld
function run () {
    ruby ./src/helloWorld.rb
}

case $PWD in
    */ruby) run ;;
    *) cd ./ruby; run ;;
esac