# sort/python/src/sort/insertionSort.py

from ._sort import swap

# ------------------------------------------------------------------------
#     insertionSort  -   insertion sort implementation
# ------------------------------------------------------------------------

def insertionSort(ar: list, rev=False) -> None:
    """Insertion sort function.

    :param ar: array to be sorted
    :type ar: list
    :param rev: sort array highest to lowest, defaults to False
    :type rev: bool, optional
    """        
    for i in range(len(ar)):
        j = i
        while j > 0 and ((not rev and ar[j - 1] > ar[j]) or (rev and ar[j - 1] < ar[j])):
            swap(ar, j, j - 1)
            j -= 1