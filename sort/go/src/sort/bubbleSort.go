// sort/go/src/sort/bubbleSort.go

package sort

// ------------------------------------------------------------------------
//     bubblSort  -   bubble sort implementation
// ------------------------------------------------------------------------

// Bubble sort function.
func BubbleSort(ar *[]float32, rev bool) {
	i := 0
	for i < len(*ar)-1 {
		if (!rev && (*ar)[i] > (*ar)[i+1]) || (rev && (*ar)[i] < (*ar)[i+1]) {
			swap(ar, i, i+1)
			i -= 1
		} else {
			i += 1
		}
		if i < 0 {
			i = 0
		}
	}
}
