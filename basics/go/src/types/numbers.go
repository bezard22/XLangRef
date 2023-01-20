// basics/go/src/types/numbers.go

package main

import "fmt"

/*
------------------------------------------------------------------------
    numbers  -  numeric data types in Go
------------------------------------------------------------------------
*/

func main() {
	var a int = -100    // integer
	var b float32 = 1.1 // float32
	var c float64 = 2.2 // float65

	// printing
	fmt.Printf("integer: %d\n", a)
	fmt.Printf("float32: %f\n", b)
	fmt.Printf("float64: %f\n", c)
}
