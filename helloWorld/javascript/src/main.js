// helloWorld/javascript/src/main.js

// ------------------------------------------------------------------------
//    helloWorld  -  Print "Hello World!" to terminal
//------------------------------------------------------------------------

// Prints Hello World message to the terimanl.
function hello() {
    console.log("Hello World!");
}

// Main Fuction
if (require.main === module) {
    hello();
}