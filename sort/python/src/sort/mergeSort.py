# sort/python/src/sort/mergeSort.py

from ._sort import swap
import sys

# ------------------------------------------------------------------------
#     mergeSort  -   merge sort implementation
# ------------------------------------------------------------------------

def _merge(arl: list, arr: list, reverse: bool) -> list:
    """Recursive merge function.

    :param arl: left array
    :type arl: list
    :param arr: right array
    :type arr: list
    :param reverse: sort array highest to lowest
    :type reverse: bool
    :return: merged array
    :rtype: list
    """        
    """Recursive merge method.

    :param arl: left array
    :type arl: list
    :param arr: right array
    :type arr: list
    :return: merged array
    :rtype: list
    """        
    if len(arl) == 0:
        return arr
    if len(arr) == 0:
        return arl
    if (not reverse and arl[0] <= arr[0]) or (reverse and arl[0] >= arr[0]):
        return [arl[0]] + _merge(arl[1:], arr, reverse)
    else:
        return [arr[0]] + _merge(arl, arr[1:], reverse)

def mergeSort(toSort: list, reverse=False) -> list:
    """merge sort function.

    :param toSort: array to be sorted
    :type toSort: list
    :param reverse: sort array highest to lowest, defaults to False
    :type reverse: bool, optional
    :return: sorted array
    :rtype: list
    """        
    ar = toSort.copy()

    # iterate through array
    n = len(ar)
    if n > 1:
        arl = ar[:int(n/2)]
        arr = ar[int(n/2):]
        ar = _merge(mergeSort(arl, reverse), mergeSort(arr, reverse), reverse)
    return ar