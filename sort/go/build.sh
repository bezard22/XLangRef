#!/bin/bash
# sort/go/build.sh

mkdir ./bin
cd ./src
go build -o ../bin/sortUtil ./main.go