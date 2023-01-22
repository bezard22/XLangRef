// sort/go/src/main.go

package main

import (
	"errors"
	"fmt"
	"github.com/akamensky/argparse"
	"math/rand"
	"os"
	"regexp"
	srt "sort/sort"
	"strconv"
	"strings"
	"time"
)

// ------------------------------------------------------------------------
//     sort  -   demonstrates functionality of several sort algorithms
// ------------------------------------------------------------------------

// Sort arguments
type argStruct struct {
	algo    string    // sorting algorithm
	n       int       // length of array to generate
	timed   bool      // timed flag
	verbose bool      // verbose flag
	rev     bool      // reverse flag
	ar      []float32 // array to sort
}

// mapping of sort algorithm functions
var algos = map[string]func(*[]float32, bool){
	"bubble":    srt.BubbleSort,
	"insertion": srt.InsertionSort,
	"selection": srt.SelectionSort,
	"merge":     srt.MergeSort,
	"quick":     srt.QuickSort,
}

// Parses command line arguments and returns a dictionary containing argument values
// Will error and report usage if incorrect synrax is passed
func parse() argStruct {
	parser := argparse.NewParser("sort", "Sorting Utility. supports integer, floating point and negative numbers")
	algo := parser.Selector("a", "algo",
		[]string{"bubble", "insertion", "selection", "merge", "quick"},
		&argparse.Options{
			Help:    "sorting algorithm to use",
			Default: "quick",
		},
	)
	n := parser.Int("n", "n",
		&argparse.Options{Help: "generate and sort a random array of length n"},
	)
	timed := parser.Flag("t", "timed",
		&argparse.Options{Help: "time sorting execution"},
	)
	verbose := parser.Flag("v", "verbose",
		&argparse.Options{Help: "verbose output, full arrays will be printed"},
	)
	rev := parser.Flag("r", "rev",
		&argparse.Options{Help: "reverse flag, array will be sorted in descending order"},
	)
	arStr := parser.StringPositional(
		&argparse.Options{
			Help:     "array to be sorted, entered as comma seperated string",
			Validate: validateAr,
		},
	)
	err := parser.Parse(os.Args)
	if err != nil {
		fmt.Print(parser.Usage(err))
	}

	var args argStruct
	args.algo = *algo
	args.n = *n
	args.timed = *timed
	args.verbose = *verbose
	args.rev = *rev
	if arStr != nil {
		args.ar = extractAr(*arStr)
	}
	return args
}

// Validate that the array string passed is a comma separated list of numbers
func validateAr(args []string) error {
	if len(args) > 0 {
		match, _ := regexp.MatchString(`^((-?\d+(\.(\d)+)?),(\s)*)+((-?\d+(\.(\d)+)?),?(\s)*)$`, args[0])
		if !match {
			errorStr := fmt.Sprintf("Incorrect array passed: %s", args[0])
			return errors.New(errorStr)
		}
	}
	return nil
}

// Generate an array based on validated array string
func extractAr(arStr string) []float32 {
	if len(arStr) == 0 {
		return []float32{}
	}
	strSl := strings.Split(arStr, ",")
	ar := make([]float32, len(strSl))
	for i, val := range strSl {
		flVal, _ := strconv.ParseFloat(val, 32)
		ar[i] = float32(flVal)
	}
	return ar
}

// main function
func main() {
	// parse and validate arguments
	args := parse()
	if !(args.n > 0 || len(args.ar) > 0) {
		fmt.Println("Please either provide an array to be sorted, or specify the length of array to generate using -n")
		os.Exit(1)
	}
	if args.n > 0 && len(args.ar) > 0 {
		fmt.Println("The -n flag generates a random array to be sorted of size n. An array argument should not be passed with -n")
		os.Exit(1)
	}

	// set array to be sorted
	var toSort *[]float32
	var n int
	if args.n > 0 {
		n = args.n
		tmp := make([]float32, args.n)
		for i := range tmp {
			tmp[i] = rand.Float32()
		}
		toSort = &tmp
	} else {
		toSort = &args.ar
		n = len(args.ar)
	}

	// sort array
	if args.timed {
		if args.verbose {
			fmt.Println("Original: ", *toSort)
			start := time.Now()
			algos[args.algo](toSort, args.rev)
			duration := time.Since(start)
			fmt.Println("Sorted: ", *toSort)
			fmt.Printf("Sorted array of size %d in %s using %sSort.\n", n, duration, args.algo)

		} else {
			start := time.Now()
			algos[args.algo](toSort, args.rev)
			duration := time.Since(start)
			fmt.Printf("Sorted array of size %d in %s using %sSort.\n", n, duration, args.algo)
		}
	} else {
		if args.verbose {
			fmt.Println("Original: ", *toSort)
			algos[args.algo](toSort, args.rev)
			fmt.Println("Sorted: ", *toSort)
		} else {
			algos[args.algo](toSort, args.rev)
		}
	}
}
