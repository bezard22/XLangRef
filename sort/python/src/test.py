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
            for i in range(2):
                test = ar.copy()
                sol = sorted(ar)
                if i == 0:
                    func(test)
                    assert test == sol, f"{func} forward {ar} expected: {sol}, produced: {test}"
                else:
                    func(test, True)
                    sol = sol[::-1]
                    assert test == sol, f"{func} reverse {ar} expected: {sol}, produced: {test}"
    
    print("All tests passed.")