# sort/python/src/sort/mergeSort.py

from ._sort import swap
import sys

# ------------------------------------------------------------------------
#     mergeSort  -   merge sort implementation
# ------------------------------------------------------------------------

def _merge(arl: list, arr: list, rev: bool) -> list:
    """Recursive merge function.

    :param arl: left array
    :type arl: list
    :param arr: right array
    :type arr: list
    :param rev: sort array highest to lowest
    :type rev: bool
    :return: merged array
    :rtype: list
    """        
    if len(arl) == 0:
        return arr
    if len(arr) == 0:
        return arl
    if (not rev and arl[0] <= arr[0]) or (rev and arl[0] >= arr[0]):
        return [arl[0]] + _merge(arl[1:], arr, rev)
    else:
        return [arr[0]] + _merge(arl, arr[1:], rev)

def mergeSort_(ar: list, rev=False) -> list:
    """Recursive merge sort function.

    :param ar: array to be sorted
    :type ar: list
    :param rev: sort array highest to lowest, defaults to False
    :type rev: bool, optional
    :return: sorted array
    :rtype: list
    """        
    n = len(ar)
    if n > 1:
        arl = ar[:int(n/2)]
        arr = ar[int(n/2):]
        ar = _merge(mergeSort_(arl, rev), mergeSort_(arr, rev), rev)
    return ar

def mergeSort(ar: list, rev=False) -> None:
    """Merge sort function.

    :param ar: array to be sorted
    :type ar: list
    :param rev: sort array highest to lowest, defaults to False
    :type rev: bool, optional
    """        
    ar[:] = mergeSort_(ar, rev)[:]
    