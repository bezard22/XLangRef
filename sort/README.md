# sort

Library and command line interface Implementation of the following sort algorithms:
- bubble sort
- selection sort
- insertion sort
- merge sort
- quick sort

---

## Usage
```
Sorting Utility. supports integer, floating point and negative numbers

positional arguments:
  ar                    array to be sorted, entered as comma seperated string

options:
  -h, --help            show this help message and exit
  -a {bubble,insertion,selection,merge,quick}, --algo {bubble,insertion,selection,merge,quick}
                        sorting algorithm to use
  -n N                  generate and sort an array of length n
  -t, --timed           time sorting execution
  -v, --verbose         Verbose output, full arrays will be printed
```
---

## Project Status
| Language | Implementation | Testing | Run Script | Build Script |
| --- | --- | --- | --- | --- |
| c | Not Started | Not Started | Not Started | Not Started |
| c# | Not Started | Not Started | Not Started | Not Started |
| c++ | Not Started | Not Started | Not Started | Not Started |
| go | Not Started | Not Started | Not Started | Not Started |
| java | Not Started | Not Started | Not Started | Not Started |
| javascript | Not Started | Not Started | Not Started | Not Started |
| python | Complete | Complete | Complete | Not Started |
| ruby | Not Started | Not Started | Not Started | Not Started |
| rust | Not Started | Not Started | Not Started | Not Started |
| scala | Not Started | Not Started | Not Started | Not Started |
| typescript | Not Started | Not Started | Not Started | Not Started |

---

## Design

### Project structure
```
├── <lang>
│   ├── src
│   │   ├── sort
│   │   │   ├── sort.
│   │   │   ├── bubbleSort.
│   │   │   ├── selectionSort.
│   │   │   ├── insertionSort.
│   │   │   ├── mergeSort.
│   │   │   └── quickSort.
│   │   ├── main.
│   │   └── test.
│   └── run.sh
```
