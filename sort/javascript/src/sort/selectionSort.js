// sort/javascript/src/sort/selectionSort.js

const swap = require("./swap").swap

// ------------------------------------------------------------------------
//     selectionSort  -   selection sort implementation
// ------------------------------------------------------------------------

// Selection sort function.
async function selectionSort(ar, rev=false) {
    for (let i = 0; i < ar.length; i++) {
        let minIndex = i;
        for (let j = i; j < ar.length; j++) {
            if ((!rev && ar[j] < ar[minIndex]) || (rev && ar[j] > ar[minIndex])) {
                minIndex = j
            }
        }
        if (minIndex > 1) {
            swap(ar, i ,minIndex)
        }
    }
}

exports.selectionSort = selectionSort;