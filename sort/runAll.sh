#!/bin/bash
# sort/runAll.sh

function usage() {
    echo "usage: $0 [-v <verbose flag>] [-t <timed flag>]";
}

v=""
t=""

while getopts 'vt' flag; do
    case "${flag}" in 
        v) v="v";;
        t) t="t";;
        *) usage; exit ;;
    esac
done

./run.sh -$v${t}l "c"
./run.sh -$v${t}l "c#"
./run.sh -$v${t}l "c++"
./run.sh -$v${t}l "go"
./run.sh -$v${t}l "java"
./run.sh -$v${t}l "javascript"
./run.sh -$v${t}l "python"
./run.sh -$v${t}l "ruby"
./run.sh -$v${t}l "rust"
./run.sh -$v${t}l "scala"
./run.sh -$v${t}l "typescript"