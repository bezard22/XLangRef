// sort/javascript/src/sort/swap.js


// ------------------------------------------------------------------------
//     swap  -  Common functions for sorting
// ------------------------------------------------------------------------

// swap the values in the given array and indeces i and j.
function swap(ar, i, j){
    let tmp = ar[i];
    ar[i] = ar[j];
    ar[j] = tmp;
}

exports.swap = swap;