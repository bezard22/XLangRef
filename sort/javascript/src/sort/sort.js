// sort/javascript/src/sort/sort.js

const bubbleSort = require('./bubbleSort').bubbleSort;
const insertionSort = require('./insertionSort').insertionSort;
const selectionSort = require('./selectionSort').selectionSort;
const quickSort = require('./quickSort').quickSort;
const mergeSort = require('./mergeSort').mergeSort;

// ------------------------------------------------------------------------
//     sort  -  export sort functions
// ------------------------------------------------------------------------

exports.bubbleSort = bubbleSort;
exports.insertionSort = insertionSort;
exports.selectionSort = selectionSort;
exports.quickSort = quickSort;
exports.mergeSort = mergeSort;