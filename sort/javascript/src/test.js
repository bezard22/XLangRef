// sort/javascript/src/test.js

const assert = require('assert');
const lodash = require('lodash');

const sort = require('./sort/sort')

// ------------------------------------------------------------------------
//     sort  -   test script for sort
// ------------------------------------------------------------------------

// let ar = [5, 1, 4, 2, 8];
// console.log(ar);
// let test = [...ar];
// let sol = [...ar].sort();
// sort.bubbleSort(test);
// console.log(lodash.isEqual(test, sol));


// Main Fuction
function main() {
    // sort functions to be tested
    const funcs = [
        sort.bubbleSort,
        sort.insertionSort,
        sort.selectionSort,
        // sort.mergeSort,
        sort.quickSort,
    ]
    // arrays to be tested
    const testArrays = [
        [],
        [1],
        [1, 2, 3, 4, 5],
        [5, 4, 3, 2, 1],
        [-2, -1, 0, 1, 2],
        [2, 1, 0, -1, -2],
        [0, 0.5, 1],
        [-1, -0.5, 0],
        [5, 4, 2, 8, 1],
    ];

    // perform tests
    funcs.forEach(func => {
        testArrays.forEach(ar => {
            for (let i = 0; i < 2; i++) {
                let test = [...ar];
                let sol = [...ar].sort((a, b) => {return a - b;});
                if (i == 0) {
                    func(test);
                    const msg = `forward ${ar} expected: ${sol}, produced: ${test}`;
                    assert(lodash.isEqual(test, sol), msg);
                }
            }
        });
    });
    console.log("All tests passed.");
}

main();