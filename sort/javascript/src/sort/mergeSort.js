// sort/javascript/src/sort/mergeSort.js

const { split } = require("lodash");

const swap = require("./swap").swap

// ------------------------------------------------------------------------
//     mergeSort  -   merge sort implementation
// ------------------------------------------------------------------------

// split array in half
async function splitAr(ar, n) {
    let arl = ar.slice(0, Math.trunc(n/2));
    let arr = ar.slice(Math.trunc(n/2), ar.length);
    return [arl, arr];
}

// Recursive merge function.
async function merge(arl, arr, rev) {
    if (arl.length == 0) {
        return arr;
    }
    if (arr.length == 0) {
        return arl;
    }
    if ((!rev && arl[0] <= arr[0]) || (rev && arl[0] >= arr[0])) {
        let remainder = await merge(arl.slice(1), arr, rev);
        return [arl[0]].concat(remainder);
    } else {
        let remainder =  await merge(arl, arr.slice(1), rev);
        return [arr[0]].concat(remainder);
    }
}

// Recursive merge sort function.
async function mergeSort_(ar, rev) {
    let n = ar.length;
    if (n > 1) {
        let ars = await splitAr(ar, n);
        let arl = await mergeSort_(ars[0], rev);
        let arr = await mergeSort_(ars[1], rev);
        ar = await merge(arl, arr, rev);
    }
    return ar;
}

// Merge sort function.
async function mergeSort(ar, rev=false) {
    let fin = await mergeSort_(ar, rev);
    for (let i = 0; i < fin.length; i++) {
        ar[i] = fin[i];
    }
}

exports.mergeSort = mergeSort;