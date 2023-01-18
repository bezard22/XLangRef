# XLangRef
Cross Language Reference

A series of data structures, algorithms, utilities, and application implemented across the following programming languages.

- C
- C++
- C#
- Go
- Java
- JavaScript
- Python
- Ruby
- Rust
- Scala
- TypeScript

---

## Projects

See README wihtin each project directory for further details.

| Project | Description | Status |
| --- | --- | --- |
| helloWorld | simple hello world script | Complete |
| sort | implementation of multiple sorting algorithms | In Progress |
| array | implementation of array data structures: stack, queue, priority-queue, linked-list, doubly linked-list | Not Started |
| tree | implementeation of graph data structures: tree, binary-tree, binary-search-tree, heap
| graph | implementation of graph data structures and algorithms | Not Started |
| database | database interface | Not Started |
| stateMachine | implementation of the state machine design pattern | Not Started |


---

## Project Status

Each project README contains a status table in the following format:
| Language | Implementation | Testing | Run Script | Build Script |
| --- | --- | --- | --- | --- |
| c | Status | Status | Status | Status |
| c# | Status | Status | Status | Status |
| c++ | Status | Status | Status | Status |
| go | Status | Status | Status | Status |
| java | Status | Status | Status | Status |
| javascript | Status | Status | Status | Status |
| python | Status | Status | Status | Status |
| ruby | Status | Status | Status | Status |
| rust | Status | Status | Status | Status |
| scala | Status | Status | Status | Status |
| typescript | Status | Status | Status | Status |

---

## Design
Within each project directory there will be a directory for each language containg a src directory and a run.sh script. Each project directory will also include a README.md run.sh, and runAll.sh

|  |  |  |
| --- | --- | --- |
| \<proj\>/\<lang\>/run.sh | bash script which executes the imlementation |
| \<proj\>/\<lang\>/build/build.sh | bash script which builds a binary of the implementation |
| \<proj\>/run.sh | bash script which executes the specified implementation | usage: ./run.sh [-l \<langauge\>] [-v \<verbose flag\>] [-t \<timed flag\>] |
| \<proj\>/runAll.sh | bash script which executes all implementations |  usage: ./runAll.sh [-v \<verbose flag\>] [-t \<timed flag\>] |

### Project Structure

```
├── <proj>
│   ├── <lang>
│   │   ├── src
│   │   │   ├── main.
│   │   │   └── test.
│   │   ├── build
│   │   │   └── build.sh
│   │   └── run.sh
|   ├── README.md
|   ├── run.sh
|   └── runAll.sh
```
