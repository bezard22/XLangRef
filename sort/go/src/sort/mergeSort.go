// sort/go/src/sort/mergeSort.go

package sort

// ------------------------------------------------------------------------
//     mergeSort  -   merge sort implementation
// ------------------------------------------------------------------------

// Recursive merge function.
func merge(arl []float32, arr []float32, rev bool) []float32 {
	if len(arl) == 0 {
		return arr
	}
	if len(arr) == 0 {
		return arl
	}
	if (!rev && arl[0] <= arr[0]) || (rev && arl[0] >= arr[0]) {
		return append([]float32{arl[0]}, merge(arl[1:], arr, rev)...)
	} else {
		return append([]float32{arr[0]}, merge(arl, arr[1:], rev)...)
	}
}

// Recursive merge sort function.
func mergeSort(ar *[]float32, rev bool) []float32 {
	n := len(*ar)
	if n > 1 {
		arl := (*ar)[:int(n/2)]
		arr := (*ar)[int(n/2):]
		*ar = merge(mergeSort(&arl, rev), mergeSort(&arr, rev), rev)
	}
	return *ar
}

// Merge sort function.
func MergeSort(ar *[]float32, rev bool) {
	mergeSort(ar, rev)
}
