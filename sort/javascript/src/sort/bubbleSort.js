// sort/python/src/sort/bubbleSort.py

const swap = require("./swap").swap

// ------------------------------------------------------------------------
//     bubblSort  -   bubble sort implementation
// ------------------------------------------------------------------------

async function bubbleSort(ar, rev=false){
    let i=0;
    while (i < ar.length) {
        if ((!rev && ar[i] > ar[i+1]) || (rev && ar[i] < ar[i+1])) {
            swap(ar, i, i+1);
            i -= 1;
        } else {
            i += 1;
        }
        if (i < 0) {
            i = 0;
        }
    }
}

exports.bubbleSort = bubbleSort;