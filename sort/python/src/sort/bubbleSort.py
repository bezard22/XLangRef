# sort/python/src/sort/bubbleSort.py

from ._sort import swap

# ------------------------------------------------------------------------
#     bubblSort  -   bubble sort implementation
# ------------------------------------------------------------------------

def bubbleSort(ar: list, rev=False) -> None:
    """Bubble sort function.

    :param ar: array to be sorted
    :type ar: list
    :param rev: sort array highest to lowest, defaults to False
    :type rev: bool, optional
    """        
    i = 0;
    while i < len(ar) - 1:
        if (not rev and ar[i] > ar[i + 1]) or (rev and ar[i] < ar[i + 1]):
            swap(ar, i, i + 1)
            i -= 1
        else:
            i += 1
        if i < 0:
            i = 0