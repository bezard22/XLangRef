# sort/python/src/sort/insertionSort.py

from ._sort import swap

# ------------------------------------------------------------------------
#     insertionSort  -   insertion sort implementation
# ------------------------------------------------------------------------

def insertionSort(toSort: list, reverse=False) -> list:
    """Insertion sort function.

    :param toSort: array to be sorted
    :type toSort: list
    :param reverse: sort array highest to lowest, defaults to False
    :type reverse: bool, optional
    :return: sorted array
    :rtype: list
    """        
    ar = toSort.copy()

    # iterate through array
    i = 1
    while i < len(ar):
        j = i
        while j > 0 and ((not reverse and ar[j - 1] > ar[j]) or (reverse and ar[j - 1] < ar[j])):
            swap(ar, j, j - 1)
            j -= 1
        i += 1

    return ar