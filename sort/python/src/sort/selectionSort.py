# sort/python/src/sort/selectionSort.py

from ._sort import swap

# ------------------------------------------------------------------------
#     selectionSort  -   selection sort implementation
# ------------------------------------------------------------------------

def selectionSort(toSort: list, reverse=False) -> list:
    """Selection sort function.

    :param toSort: array to be sorted
    :type toSort: list
    :param reverse: sort array highest to lowest, defaults to False
    :type reverse: bool, optional
    :return: sorted array
    :rtype: list
    """        
    ar = toSort.copy()

    # iterate through array
    for i in range(len(ar)):
        minIndex = i
        for j in range(i, len(ar)):
            if (not reverse and ar[j] < ar[minIndex]) or (reverse and ar[j] > ar[minIndex]):
                minIndex = j
        if minIndex > i:
            swap(ar, i, minIndex)

    return ar