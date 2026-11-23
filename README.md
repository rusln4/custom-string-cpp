# Custom String Implementation in C++

![C++](https://img.shields.io/badge/C++-17-blue?logo=cplusplus)
![CMake](https://img.shields.io/badge/CMake-Build-green?logo=cmake)
![GoogleTest](https://img.shields.io/badge/GoogleTest-Testing-orange)
![Status](https://img.shields.io/badge/Status-Educational_Project-purple)

## 📖 About the Project

**Custom String** is an educational C++ project implementing a simplified version of `std::string` from scratch.

The class provides dynamic memory management, string manipulation, operator overloading, and basic substring operations without using standard containers.

The project focuses on understanding how strings work internally in C++.

## ✨ Features

### Constructors and Memory Management
- Default, C-string, fill, and copy constructors
- Deep copying and copy assignment
- Dynamic memory allocation using `new[]` and `delete[]`
- Automatic capacity growth
- Memory optimization with `ShrinkToFit()`

### String Operations
- `PushBack()` / `PopBack()` — add or remove characters
- `Clear()` — clear string contents
- `Size()` / `Length()` — get string length
- `Capacity()` — get allocated capacity
- `Empty()` — check whether a string is empty
- `Front()` / `Back()` — access first and last characters
- `Data()` / `operator[]` — direct character access

### Operators
- `+` and `+=` — string concatenation
- `=` — copy assignment
- `==`, `<`, `>`, `<=`, `>=` — string comparisons
- `<<` and `>>` — stream input and output

### Substring Operations
- `Find()` — find the first occurrence
- `Rfind()` — find the last occurrence
- `Substr()` — extract a substring

## 💻 Usage Example

Create two strings:

`String first("Hello");`

`String second("World");`

Concatenate them:

`String result = first + ' ' + second;`

Print the result:

`std::cout << result << '\n';`

**Output:**

`Hello World`

### Building the Alphabet

Another example demonstrates dynamic string growth using `PushBack()`.

Start with an empty string:

`String alphabet;`

Append characters from `'a'` to `'z'` using a loop, then output the string with `std::cout`.

**Result:**

`abcdefghijklmnopqrstuvwxyz`

## 📁 Project Structure

- `string/string.hpp` — class declarations and public interface
- `string/src/string.cpp` — method implementations
- `string/tests/test.cpp` — GoogleTest unit tests
- `string/play/main.cpp` — examples and experiments
- `string/CMakeLists.txt` — build configuration

## 🧪 Testing

The project uses **GoogleTest** for unit testing and **CMake** for building.

From the root directory of the original CMake project:

1. Build the test target: `cmake --build build --target test_string`
2. Run the tests: `./build/test_string`

Tests cover constructors, copying, character operations, comparisons, and other functionality.

## 🛠 Tech Stack

- **Language:** C++17
- **Build System:** CMake
- **Testing:** GoogleTest
- **Compiler:** Clang / GCC

## 🎯 Learning Objectives

This project was developed to practice:

- Object-oriented programming (OOP)
- Pointers and references
- Dynamic memory allocation
- Constructors and destructors
- Deep copy semantics
- Operator overloading
- Const correctness
- Manual resource management
- Unit testing

## 📝 Notes

This is an educational implementation intended to demonstrate the internals of a string class.

It is not designed as a complete replacement for the standard `std::string`.

---

**Built with C++ to understand what happens behind the scenes.**
