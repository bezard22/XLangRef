# sort/python/src/sort/bubbleSort.py

from ._sort import swap

# ------------------------------------------------------------------------
#     bubblSort  -   bubble sort implementation
# ------------------------------------------------------------------------

def bubbleSort(toSort: list, reverse=False) -> list:
    """Bubble sort function.

    :param toSort: array to be sorted
    :type toSort: list
    :param reverse: sort array highest to lowest, defaults to False
    :type reverse: bool, optional
    :return: sorted array
    :rtype: list
    """        
    ar = toSort.copy()

    # iterate through array
    i = 0;
    while i < len(ar) - 1:
        if (not reverse and ar[i] > ar[i + 1]) or (reverse and ar[i] < ar[i + 1]):
            swap(ar, i, i + 1)
            i -= 1
        else:
            i += 1
        if i < 0:
            i = 0

    return ar