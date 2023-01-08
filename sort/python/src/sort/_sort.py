# sort/python/src/sort/_sort.py


# ------------------------------------------------------------------------
#     _sort  -  Common functions for sorting
# ------------------------------------------------------------------------

def swap(ar: list, i: int, j: int) -> None:
    """swap the values in the given array and indeces i and j.

    :param ar: array to make the swap in
    :type ar: list
    :param i: index 1
    :type i: int
    :param j: index 2
    :type j: int
    """        
    (ar[i], ar[j]) = (ar[j], ar[i])