# sort/python/src/sort/selectionSort.py

from ._sort import swap

# ------------------------------------------------------------------------
#     selectionSort  -   selection sort implementation
# ------------------------------------------------------------------------

def selectionSort(ar: list, rev=False) -> None:
    """Selection sort function.

    :param ar: array to be sorted
    :type ar: list
    :param rev: sort array highest to lowest, defaults to False
    :type rev: bool, optional
    :return: sorted array
    :rtype: list
    """        
    for i in range(len(ar)):
        minIndex = i
        for j in range(i, len(ar)):
            if (not rev and ar[j] < ar[minIndex]) or (rev and ar[j] > ar[minIndex]):
                minIndex = j
        if minIndex > i:
            swap(ar, i, minIndex)