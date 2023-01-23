// sort/javascript/src/sort/insertionSort.js

const swap = require("./swap").swap

// ------------------------------------------------------------------------
//     insertionSort  -   insertion sort implementation
// ------------------------------------------------------------------------

// Insertion sort function.
function insertionSort(ar, rev=false) {
    for (let i = 0; i < ar.length; i++) {
        let j = i;
        while (j > 0 && ((!rev && ar[j - 1] > ar[j]) || (rev && ar[j - 1] < ar[j]))) {
            swap(ar, j, j - 1);
            j -= 1;
        }
    }
}

exports.insertionSort = insertionSort;