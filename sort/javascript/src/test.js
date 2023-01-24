// sort/javascript/src/test.js

const assert = require('assert');
const lodash = require('lodash');

const sort = require('./sort/sort')

// ------------------------------------------------------------------------
//     sort  -   test script for sort
// ------------------------------------------------------------------------

async function testSet(ar, rev) {
    let test = [...ar];
    let sol;
    if (rev) {
        sol = [...ar].sort((a, b) => {return b - a;});
    } else {
        sol = [...ar].sort((a, b) => {return a - b;});
    }
    return [test, sol];
}

// Main Fuction
async function main() {
    // sort functions to be tested
    const funcs = [
        sort.bubbleSort,
        sort.insertionSort,
        sort.selectionSort,
        sort.mergeSort,
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
    for (let i = 0; i < funcs.length; i++) {
        for (let j = 0; j < testArrays.length; j++) {
            for (let i = 0; i < 1; i++) {
                let rev = i > 0;
                let testVals = await testSet(testArrays[j], rev);
                await funcs[i](testVals[0], rev);
                const msg = `${rev ? "Reverse" : "Forward:"} ${testArrays[j]} expected: ${testVals[1]}, produced: ${testVals[0]}`;
                assert(lodash.isEqual(testVals[0], testVals[1]), msg);
            }
        }
    }
    console.log("All tests passed.");
}

main();