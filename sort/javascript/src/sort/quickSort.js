// sort/javascript/src/sort/quickSort.js

const swap = require("./swap").swap

// ------------------------------------------------------------------------
//     quickSort  -   quick sort implementation
// ------------------------------------------------------------------------

// partition strategies
const strategies = {
    "high": function(high, low) {return high;},
    "low": function(high, low) {return low;},
    "rand": function(high, low) {Math.random() * high - low},
}

// Parition function for quick sort.
function partition(ar, low, high, rev, strat) {
    // pivot strategy
    if (!(strat in strategies)) {
        throw new Error(`Unrecoginzed pivot strategy: ${strat}, must be in ['high', 'low', 'rand']`)
    }
    pi = strategies[strat](high, low);

    let piv = ar[pi];
    let i = low - 1;
    for (let j = low; j < high + 1; j++) {
        if ((!rev && ar[j] < piv) || (rev && ar[j] > piv)) {
            i++;
            swap(ar, i, j)
            if (pi == i) {
                pi = j;
            }
        }
    }
    swap(ar, i + 1, pi);
    return i + 1;
}

// Recursive quick sort function.
function _quickSort(ar, low, high, rev, strat) {
    if (low < high) {
        pi = partition(ar, low, high, rev, strat);
        _quickSort(ar, low, pi - 1, rev, strat);
        _quickSort(ar, pi + 1, high, rev, strat);
    }
}

// Quick sort function.
function quickSort(ar, rev=false, strat="high") {
    _quickSort(ar, 0, ar.length - 1, rev, strat);
}

exports.quickSort = quickSort;