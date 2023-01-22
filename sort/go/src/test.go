// sort/go/src/main.go

package main

import (
	"fmt"
	"sort"
	srt "sort/sort"
)

// ------------------------------------------------------------------------
//     sort  -   test script for sort
// ------------------------------------------------------------------------

func main() {
	funcs := []func(*[]float32, bool){
		srt.BubbleSort,
		srt.InsertionSort,
		srt.SelectionSort,
		srt.MergeSort,
		srt.QuickSort,
	}

	funcStr := []string{
		"BubbleSort",
		"InsertionSort",
		"SelectionSort",
		"MergeSort",
		"QuickSort",
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

	for i := range funcs {
		for _, ar := range testArrays {
			for j := 0; j < 2; j++ {
				test := make([]float32, len(ar))
				sol := make([]float32, len(ar))
				copy(test, ar)
				copy(sol, ar)
				if j == 0 {
					sort.Slice(sol, func(i, j int) bool { return sol[i] < sol[j] })
					funcs[i](&test, false)
					for k, v := range test {
						if v != sol[k] {
							err := fmt.Sprintf("%s forward %v expected: %v", funcStr[i], test, sol)
							panic(err)
						}
					}
				} else {
					sort.Slice(sol, func(i, j int) bool { return sol[i] > sol[j] })
					funcs[i](&test, true)
					for k, v := range test {
						if v != sol[k] {
							err := fmt.Sprintf("%s reverse %v expected: %v", funcStr[i], test, sol)
							panic(err)
						}
					}
				}

			}

		}
	}
	fmt.Println("All tests passed.")
}
