#!/bin/bash
# <path>

function usage() {
    echo "usage: $0 [-l <langauge>] [-v <verbose flag>] [-t <timed flag>]";
}

while getopts 'l:vt' flag; do
    case "${flag}" in 
        l) lang="$OPTARG" ;;
        v) verbose=1 ;;
        t) timed=1 ;;
        *) usage ;;
    esac
done

if [[ -v lang ]];
then
    cd ./$lang
    if [[ -v verbose ]];
    then
        echo "$lang:";
    fi
    if [[ -v timed ]];
    then
        time ./run.sh
    else
        ./run.sh
    fi
else
    usage
fi
