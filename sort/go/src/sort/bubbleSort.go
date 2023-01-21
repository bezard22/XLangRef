// sort/go/src/sort/bubbleSort.go

package sort

// ------------------------------------------------------------------------
//     bubblSort  -   bubble sort implementation
// ------------------------------------------------------------------------

func BubbleSort(ar *[]float32, rev bool) {
	var i int
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
