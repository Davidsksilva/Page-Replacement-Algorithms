# Page Replacement Algorithms

This code is a project for the discipline Operational Systems, in the Federal University of Paraiba, Brazil.

## Introduction

When the computer refers to a page in the page table, sometimes the refered page is not located in the table. If there is a free block in the page table, the refered page will be loaded into that block, but when the table is full, and the refered page is not there, a page replacement will be needed. We will cover three of them:

* **FIFO** When a page replacement is needed, the oldest(first) page in the table will be replaced by the refered page.
* **OTM** A theorical algorithms, repleases the page that will not be accessed for the longest time. It is not practicable because there is no way to know when a page will be refered.
* **LRU** The page with the oldest access(reference) on the page table will be repleaced.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them

```
G++ or compatible installed.
```

### Installing

To run the code in LINUX, in the directoy file:

```
make
```

And next:

```
./build/pagereplacement
```

## Built With

* [Atom](https://atom.io/) - Used for code editting.

## Authors

* **David Simon** - *Whole Project* - [Davidsksilva](https://github.com/Davidsksilva)

## Special Thanks

Special thanks to my girlfriend Nadja, for the moral support, and [Avin1cius](https://github.com/Avin1cius) for the makefile!

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
