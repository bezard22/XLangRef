// sort/go/src/sort/insertionSort.go

package sort

// ------------------------------------------------------------------------
//     insertionSort  -   insertion sort implementation
// ------------------------------------------------------------------------

func InsertionSort(ar *[]float32, rev bool) {
	var j int
	for i := range *ar {
		j = i
		for j > 0 && ((!rev && (*ar)[j-1] > (*ar)[j]) || (rev && (*ar)[j-1] < (*ar)[j])) {
			swap(ar, j, j-1)
			j -= 1
		}
	}
}
