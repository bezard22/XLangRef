#!/bin/bash
# helloWorld/c#/run.sh

# execute c# helloWorld
mcs -out:main.exe ./src/main.cs
mono ./main.exe
rm ./main.exe