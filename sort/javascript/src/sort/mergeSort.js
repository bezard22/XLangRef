// sort/javascript/src/sort/mergeSort.js

const swap = require("./swap").swap

// ------------------------------------------------------------------------
//     mergeSort  -   merge sort implementation
// ------------------------------------------------------------------------

// Recursive merge function.
async function merge(arl, arr, rev) {
    if (arl.length == 0) {
        return arr;
    }
    if (arr.length == 0) {
        return arl;
    }
    if ((!rev && arl[0] <= arr[0]) || (rev && arl[0] >= arr[0])) {
        return [arl[0]].concat(merge(arl.slice(1), arr, rev));
    } else {
        return [arr[0]].concat(merge(arl, arr.slice(1), rev));
    }
}

// Recursive merge sort function.
async function mergeSort_(ar, rev) {
    let n = ar.length;
    if (n > 1) {
        let arl = ar.slice(0, Math.trunc(n/2));
        let arr = ar.slice(Math.trunc(n/2), ar.length);
        let ar = await merge(mergeSort_(arl, rev), mergeSort_(arr, rev), rev);
    }
    return ar;
}

// Merge sort function.
async function mergeSort(ar, rev=false) {
    await mergeSort_(ar, rev);
    // ar = fin;
}

exports.mergeSort = mergeSort;