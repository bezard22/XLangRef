# sort/python/src/test/sortTest.py

from sort import *
from random import random

# ------------------------------------------------------------------------
#     sort  -   test script for sort
# ------------------------------------------------------------------------

if __name__ == "__main__":
    funcs = [
        bubbleSort,
        selectionSort,
        insertionSort,
        mergeSort,
        quickSort
    ]
    funcOpts = {}

    # arrays to be tested
    testArrays = [
        [],
        [1],
        [1, 2, 3, 4, 5],
        [5, 4, 3, 2, 1],
        [-2, -1, 0, 1, 2],
        [2, 1, 0, -1, -2],
        [0, 0.5, 1],
        [-1, -0.5, 0],
        [5, 4, 2, 8, 1],
        [random() for i in range(10)],
        [random() for i in range(900)],
    ]
    
    # perform test
    for func in funcs:
        for ar in testArrays:
            f = func(ar)
            fexp = sorted(ar)
            assert f == fexp, f"{func} forward {ar} expected: {fexp}, produced: {f}"
            r = func(ar, reverse=True)
            rexp = fexp[::-1]
            assert r == rexp, f"{func} reverse {ar} expected: {rexp}, produced: {r}"
    
    print("All tests passed.")