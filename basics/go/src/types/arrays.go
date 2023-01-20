// basics/go/src/types/arrays.go

package main

import "fmt"

/*
------------------------------------------------------------------------
    arrays  -  arrays in Go
------------------------------------------------------------------------
*/

func main() {
	// declare fixed size array
	var a [10]int

	// instantiate array with for loop
	for i := 0; i < 10; i++ {
		a[i] = 0
	}

	// instantiate array with array literal
	b := [10]int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

	// index array
	c := b[0]
	fmt.Println(c)

	// slice array
	var d []int = b[2:5] // inclusive of first index (2) exclusive of second (5)
	fmt.Println(d)

	e := b[:4] // : indicates all elements up to
	fmt.Println(e)

	// length of array
	f := len(b)
	fmt.Println((f))

	// iterate through array
	for i := 0; i < 10; i++ {
		fmt.Println(b[i])
	}

	// print array
	fmt.Println(b)

	// multidimensional array
	g := [5][5]int{
		{0, 1, 2, 3, 4},
		{5, 6, 7, 8, 9},
		{10, 11, 12, 13, 14},
		{15, 16, 17, 18, 19},
		{20, 21, 22, 23, 25},
	}
	fmt.Println(g)

	// dynamic array size
	h := 10
	l := make([]int, h)
	fmt.Println(l)
	for i := 0; i < h; i++ {
		l[i] = i * 5
	}
	fmt.Println(l)
}
