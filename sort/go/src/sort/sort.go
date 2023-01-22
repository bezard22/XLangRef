// sort/go/src/sort/sort.go

package sort

// ------------------------------------------------------------------------
//     sort  -  Common functions for sorting
// ------------------------------------------------------------------------

// swap the values in the given array and indeces i and j.
func swap(ar *[]float32, i int, j int) {
	(*ar)[i], (*ar)[j] = (*ar)[j], (*ar)[i]
}
