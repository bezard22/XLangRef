# sort/python/src/main.py

from sort import *
import argparse
import re
from random import randint
from time import time

# ------------------------------------------------------------------------
#     sort  -   demonstrates functionality of several sort algorithms
# ------------------------------------------------------------------------

def parse() -> dict[str, any]:
    """Parsese command line arguments and returns a dictionary containing argument values

    :return: dictionary containgin argument values
    :rtype: dict[str, any]
    """    
    parser = argparse.ArgumentParser(prog="sort", description="Sorting Utility. supports integer, floating point and negative numbers")
    parser.add_argument("-a", "--algo",
        help="sorting algorithm to use",
        default="quick",
        choices=["bubble", "insertion", "selection", "merge", "quick"],
    )
    parser.add_argument("-n",
        help="generate and sort a random array of length n",
        type=int
    )
    parser.add_argument("-t", "--timed",
        help="time sorting execution",
        action="store_true"
    )
    parser.add_argument("-v", "--verbose",
        help="Verbose output, full arrays will be printed",
        action="store_true"
    )
    parser.add_argument("ar",
        help="array to be sorted, entered as comma seperated string",
        nargs="?",
        type=validateAr
    )
    return vars(parser.parse_args())

def validateAr(arString: str) -> list[float]:
    """Validate that the array string passed is a comma separated list of numbers

    :param arString: array string passed via command line
    :type arString: str
    :raises argparse.ArgumentError: argument error
    :return: list of float values derived from array string
    :rtype: list[float]
    """    
    if re.search(r"((-?\d+(\.(\d)+)?),(\s)*)+((-?\d+(\.(\d)+)?),?(\s)*)", arString).group() != arString:
        raise argparse.ArgumentError()
    return [float(i) for i in arString.strip().split(",")]


def main() -> None:
    """Main function, parses arguments and performs sorting"""    
    
    algos = {
        "bubble": bubbleSort,
        "insertion": insertionSort,
        "selection": selectionSort,
        "merge": mergeSort,
        "quick": quickSort,
    }
    
    # Parse and validate arguments
    args = parse()
    if not (args["n"] or args["ar"]):
        print("Please either provide an array to be sorted, or specify the length of array to generate using -n")
        exit()
    if args["n"] and args["ar"]:
        print("The -n flag generates a random array to be sorted of size n. An array argument should not be passed with -n")
        exit()
    
    # set array to be sorted
    if args["n"]:
        n = args["n"]
        ar = [randint(0, 9) for _ in range(n)]
    else:
        ar = args["ar"]
        n = len(ar)
    
    # sort array
    if args["timed"]:
        start = time()
        try:
            arSorted = algos[args["algo"]](ar)
        except RecursionError:
            print(f"Unable to sort array of size {n} using {args['algo']}Sort due to Python recursion limit")
            exit()
        print(f"Sorted array of size {n} in {(time() - start) :.3f} seconds using {args['algo']}Sort." )
    else:
        arSorted = algos[args["algo"]](ar)
    
    # optionally print output
    if args["verbose"]:
        print(f"Original: {ar}")
        print(f"Sorted: {arSorted}")


# Execute main function
if __name__ == "__main__":
    main()
