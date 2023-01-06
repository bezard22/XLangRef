#!/bin/bash
# helloWorld/ruby/run.sh

# execute ruby helloWorld
function run () {
    ruby ./src/helloWorld.rb
}

lang="ruby"

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