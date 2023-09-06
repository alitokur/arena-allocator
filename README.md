<div align="center">
<h1>Arena Allocator</h1>
<h5> A custom memory allocator written in C++. </h5>
  
![Work In Progress](https://img.shields.io/badge/-WORK%20IN%20PROGRESS-orange)
[![Build](https://github.com/alitokur/arena-allocator/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/alitokur/arena-allocator/actions/workflows/cmake.yml)
</div>

## Table of Contents

- [Arena Allocator](#arena-allocator)
  - [Cons ](#cons)
  - [Pros ](#pros)
  - [Memory Alignment](#memory-alignment)
- [FAQ](#faq)
- [Build](#build)
- [Contributing](#contributing)


## Arena Allocator
The Arena Memory Allocator (region based memory allocator) is a fundamental
custom memory allocation system. It involves creating single large memory block
and using an offset to manage allocations. The offset serves as a reference point for
the last allocated memory location.


### Cons
Speed: Arena allocators can be faster than dynamic allocation because there's no need to manage a list of free blocks or perform complex searches for suitable memory blocks.
Predictable: Memory fragmentation is less of an issue with arena allocators, as you're allocating memory in large, contiguous chunks.
Memory Leak Prevention: When the arena goes out of scope or is explicitly deallocated, all the memory allocated within it is automatically freed, reducing the risk of memory leaks.

### Pros
Arenas can be less flexible than other memory allocation techniques because you have to determine the maximum memory requirement upfront.
They may not be suitable for applications with highly variable or unpredictable memory needs.

### Memory Alignment 
Memory alignment is indeed an important concept in computer architecture and memory 
management. Its essential for optimizing memory access and ensuring that data is accessed in 
way that aligns with the word size of the computers architecture.

Modern computer architectures typically have a specifig word size, which is the amount
of data the proccessor can read form memory in a single operation. For example, on 32-bit
systems, the word size typically 4 bytes, and on 64-bit systems, it is often 8 bytes. 
Memory alignment ensures that data structures start at addresses that are multiples of 
the word size.

## FAQ
- Why I use malloc in custom memoru allocator? Its already an allocator?
- Can i use brk() or sbrk() instead of malloc();

## Build
 You can build Arena Allocator by following these steps:

- Clone the repository: 

```
git clone 
```

- Create a build directory: 

```
mkdir build && cd build
```

- Run CMake: 

```
cmake ..
```

- Build the project: 

```
make
```

If the build is successful, you should see the executable file for your project in the build directory.
If you encounter any issues during the build process or have questions, please don't hesitate to reach out for assistance.
Please note that the Arena Allocator is currently compatible with Linux systems. Support for other operating systems may be added in the future as the project evolves.
Arena Memory Allocator is indeed simple and often do not support fine-grained memory deallocation where you can free individual memory blocks.
In arena allocator, memory is typically released all at once, which means that when you are done with the entire arena, you deallocate the entire areana in a single operation.

## Contributing

 If you would like to contribute, please follow these guidelines:

- Fork the repository and make changes on your own fork.
- Ensure that your code adheres to the existing code formatting and style guidelines.
- Write clear commit messages and pull request descriptions.


## Contact
If you have any questions, feedback or suggestions, please feel free to contact me at alitokurr@gmail.com . 
You can also follow me on Twitter at @alitokur. 
I'm always open to feedback and would love to hear from you!
