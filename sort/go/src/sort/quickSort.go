// sort/go/src/sort/quickSort.go

package sort

import (
	"fmt"
	"math/rand"
	"os"
)

// ------------------------------------------------------------------------
//     quickSort  -   quick sort implementation
// ------------------------------------------------------------------------

// Partition stratigies
var strategies = map[string]func(int, int) int{
	"high": func(high int, low int) int { return high },
	"low":  func(high int, low int) int { return low },
	"rand": func(high int, low int) int { return rand.Intn(high-low) + low },
}

// Partition function for quick sort.
func partition(ar *[]float32, low int, high int, rev bool, strat string) int {
	// pivot strategy
	val, ok := strategies[strat]
	if !ok {
		fmt.Printf("Unrecoginzed pivot strategy: %s, must be in ['high', 'low', 'rand']\n", strat)
		os.Exit(1)
	}
	pi := val(high, low)

	piv := (*ar)[pi]
	i := low - 1
	for j := low; j < high+1; j++ {
		if (!rev && (*ar)[j] < piv) || (rev && (*ar)[j] > piv) {
			i += 1
			swap(ar, i, j)
			if pi == i {
				pi = j
			}
		}
	}
	swap(ar, i+1, pi)
	return i + 1
}

// Recursive quick sort function.
func quickSort(ar *[]float32, low int, high int, rev bool, strat string) {
	if low < high {
		pi := partition(ar, low, high, rev, strat)
		quickSort(ar, low, pi-1, rev, strat)
		quickSort(ar, pi+1, high, rev, strat)
	}
}

// Quick sort function.
func QuickSort(ar *[]float32, rev bool) {
	quickSort(ar, 0, len(*ar)-1, rev, "high")
}
