// sort/go/src/sort/sort.go

package sort

// ------------------------------------------------------------------------
//     sort  -  Common functions for sorting
// ------------------------------------------------------------------------

func swap(ar *[]float32, i int, j int) {
	(*ar)[i], (*ar)[j] = (*ar)[j], (*ar)[i]
}
