// sort/go/src/main.go

package main

import (
	"errors"
	"fmt"
	"github.com/akamensky/argparse"
	"os"
	"regexp"
	"strconv"
	"strings"
)

// ------------------------------------------------------------------------
//     sort  -   demonstrates functionality of several sort algorithms
// ------------------------------------------------------------------------

type argStruct struct {
	algo    string
	n       int
	timed   bool
	verbose bool
	ar      []float32
}

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
		&argparse.Options{Help: "Verbose output, full arrays will be printed"},
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
	if arStr != nil {
		args.ar = extractAr(*arStr)
	}
	return args
}

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

func extractAr(arStr string) []float32 {
	strSl := strings.Split(arStr, ",")
	ar := make([]float32, len(strSl))
	for i, val := range strSl {
		flVal, _ := strconv.ParseFloat(val, 32)
		ar[i] = float32(flVal)
	}
	return ar
}

func main() {
	args := parse()
	fmt.Println("algo: ", args.algo)
	fmt.Println("n: ", args.n)
	fmt.Println("timed: ", args.timed)
	fmt.Println("verbose: ", args.verbose)
	fmt.Println("ar: ", args.ar)
}
