# C++ Command-Line File Manager

A command-line file-management utility built with C++17 and the standard filesystem library.

## Features

- List directory contents
- Show the current directory
- Change directories
- Read text files
- Create directories
- Copy files
- Move files
- Interactive command-line interface

## Tech Stack

- C++17
- `<filesystem>`
- File streams
- STL strings and vectors
- Command parsing with `std::istringstream`

## Commands

```text
ls
cd <directory>
cat <file>
mkdir <directory>
cp <source> <destination>
mv <source> <destination>
help
exit
```

## Build

```bash
g++ -std=c++17 file-manager.cpp -o file-manager
./file-manager
```

Windows/MinGW:

```bash
g++ -std=c++17 file-manager.cpp -o file-manager.exe
file-manager.exe
```

## Concepts Demonstrated

- C++17 filesystem operations
- File I/O
- Exception handling
- Command parsing
- Standard Template Library
- Interactive CLI development

## Planned Improvements

- Modular class-based architecture
- Delete and rename commands
- Recursive search
- Better argument validation
- Automated tests
- CMake build configuration

## Author

**Prashant Kumar**
