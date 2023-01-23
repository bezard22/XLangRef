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
  -n                    generate and sort an array of length n
  -t, --timed           time sorting execution
  -v, --verbose         verbose output, full arrays will be printed
  -r, --rev             reverse flag, array will be sorted in descending order
```
---

## Project Status
| Language | Implementation | Testing | Run Script | Build Script |
| --- | --- | --- | --- | --- |
| c | Complete | Complete | Complete | Complete |
| c# | Not Started | Not Started | Not Started | Not Started |
| c++ | Not Started | Not Started | Not Started | Not Started |
| go | Complete | Complete | Complete | Complete |
| java | Not Started | Not Started | Not Started | NA |
| javascript | In Progress | In Progress | Not Started | Not Started |
| python | Complete | Complete | Complete | NA |
| ruby | Not Started | Not Started | Not Started | NA |
| rust | Not Started | Not Started | Not Started | Not Started |
| scala | Not Started | Not Started | Not Started | Not Started |
| typescript | Not Started | Not Started | Not Started | Not Started |

---

## Design

### Project Structure
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
│   ├── build.sh
│   ├── run.sh
│   └── test.sh
```
