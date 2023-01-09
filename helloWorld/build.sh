#!/bin/bash
# helloWorld/build.sh

function usage() {
    echo "usage: $0 [-l <langauge>] [-o outfile]";
}

while getopts 'l:o:v' flag; do
    case "${flag}" in 
        l) lang="$OPTARG" ;;
        v) verbose=1 ;;
        o) outfile="$OPTARG" ;;
        *) usage ;;
    esac
done

if [[ -v lang  ]] && [[ -v outfile  ]];
then
    cd ./$lang/build
    if [[ -v verbose ]];
    then
        echo "Building $lang:";
    fi
    ./build.sh $outfile
else
    usage
fi
