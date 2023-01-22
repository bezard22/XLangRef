# sort/python/src/sort/quickSort.py

from ._sort import swap
from random import randint

# ------------------------------------------------------------------------
#     quickSort  -   quick sort implementation
# ------------------------------------------------------------------------

# Partition straties
strategies = {
    "high": lambda high, low : high,
    "low": lambda high, low : low,
    "rand": lambda high, low : randint(low, high),
}

def _partition(ar: list, low: int, high: int, rev: bool, strat: str) -> int:
    """Partition function for quick sort

    :param ar: array to be sorted
    :type ar: list
    :param low: low index of portion of array
    :type low: int
    :param high: high index of portion of array
    :type high: int
    :param rev: sort array highest to lowest
    :type rev: bool
    :param strat: pivot selection strategy
    :type strat: str
    :raises Exception: Unrecognized pivot strategy
    :return: post partition pivot index
    :rtype: int
    """        
    # pivot strategy
    if strat not in strategies.keys():
        raise Exception(f"Unrecoginzed pivot strategy: {strat}, must be in ['high', 'low', 'rand']")
    pi = strategies[strat](high, low)
    
    # iterate through array
    piv = ar[pi]
    i = low - 1
    for j in range(low, high + 1):
        if ((not rev and ar[j] < piv) or (rev and ar[j] > piv)):
            i += 1
            swap(ar, i, j)
            if pi == i:
                pi = j
    swap(ar, i + 1, pi)
    return i + 1

def _quickSort(ar: list, low: int, high: int, rev: bool, strat: str) -> None:
    """Recursive quick sort function.

    :param ar: array to be sorted
    :type ar: list
    :param low: low index of portion of array
    :type low: int
    :param high: high index of portion of array
    :type high: int
    :param rev: sort array highest to lowest
    :type rev: bool
    :param strat: pivot selection strategy
    :type strat: str
    """        
    if low < high:
        pi = _partition(ar, low, high, rev, strat)
        _quickSort(ar, low, pi - 1, rev, strat)
        _quickSort(ar, pi + 1, high, rev, strat)

def quickSort(ar: list, rev=False, strat="high") -> None:
    """Quick sort function.

    :param ar: array to be sorted
    :type ar: list
    :param rev: sort array highest to lowest, defaults to False
    :type rev: bool, optional
    :param strat: pivot selection strategy, defaults to "high"
    :type strat: str, optional
    """        
    _quickSort(ar, 0, len(ar) - 1, rev, strat)