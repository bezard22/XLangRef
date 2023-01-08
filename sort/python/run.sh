#!/bin/bash
# sort/python/run.sh

python ./src/main.py -a bubble -tn 10
python ./src/main.py -a bubble -tn 100
python ./src/main.py -a bubble -tn 1000
python ./src/main.py -a bubble -tn 10000

python ./src/main.py -a insertion -tn 10
python ./src/main.py -a insertion -tn 100
python ./src/main.py -a insertion -tn 1000
python ./src/main.py -a insertion -tn 10000

python ./src/main.py -a selection -tn 10
python ./src/main.py -a selection -tn 100
python ./src/main.py -a selection -tn 1000
python ./src/main.py -a selection -tn 10000

python ./src/main.py -a merge -tn 10
python ./src/main.py -a merge -tn 100
python ./src/main.py -a merge -tn 1000
python ./src/main.py -a merge -tn 10000

python ./src/main.py -a quick -tn 10
python ./src/main.py -a quick -tn 100
python ./src/main.py -a quick -tn 1000
python ./src/main.py -a quick -tn 10000