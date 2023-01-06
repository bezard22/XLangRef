#!/bin/bash
# helloWorld/scala/run.sh

# execute scala helloWorld
scalac ./src/main.scala
scala main
rm ./main.class
rm ./main$.class