// sort/go/src/sort/selectionSort.go

package sort

// ------------------------------------------------------------------------
//     selectionSort  -   selection sort implementation
// ------------------------------------------------------------------------

// Selection sort function.
func SelectionSort(ar *[]float32, rev bool) {
	for i := range *ar {
		minIndex := i
		for j := i; j < len(*ar); j++ {
			if (!rev && (*ar)[j] < (*ar)[minIndex]) || (rev && (*ar)[j] > (*ar)[minIndex]) {
				minIndex = j
			}
		}
		if minIndex > i {
			swap(ar, i, minIndex)
		}
	}
}
