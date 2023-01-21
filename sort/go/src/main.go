// sort/go/src/main.go

package main

import (
	"fmt"
	"sort/sort"
)

func main() {
	funcs := []func(*[]float32, bool){
		sort.BubbleSort,
		sort.InsertionSort,
		sort.SelectionSort,
	}

	testArrays := [][]float32{
		{},
		{1},
		{1, 2, 3, 4, 5},
		{5, 4, 3, 2, 1},
		{-2, -1, 0, 1, 2},
		{2, 1, 0, -1, -2},
		{0, 0.5, 1},
		{-1, -0.5, 0},
		{5, 4, 2, 8, 1},
	}

	for _, f := range funcs {
		for _, ar := range testArrays {
			test := make([]float32, len(ar))
			copy(test, ar)
			f(&test, false)
			fmt.Println(test)
		}
	}
}
