# Dynamic Array Implementation in C++

## Overview
This repository contains the implementation of a `DynamicArray` class that mimics the behavior of a dynamic array (similar to `std::vector` in C++ Standard Library). It supports operations such as insertion, deletion, searching, sorting, reversing, and merging arrays.

## Features
- **Dynamic Resizing:** The array can be resized automatically when it reaches its capacity.
- **Insertion:** Insert elements at any position within the array.
- **Deletion:** Remove elements from any position within the array.
- **Search:** Perform a linear search for an element within the array.
- **Sorting:** Sort the array using bubble sort algorithm.
- **Reversing:** Reverse the order of elements within the array.
- **Merging:** Merge two `DynamicArray` instances into a new one.
- **Element Access:** Access elements with bounds checking.
- **Printing:** Print the array elements to the console.

## Usage

### Compilation
Compile the source files with your preferred C++ compiler:
```sh
g++ -o DynamicArray DynamicArray.cpp main.cpp
```

### Creating a Dynamic Array
```cpp
DynamicArray arr(10); // Initialize a dynamic array with an initial capacity of 10 elements.
```

### Inserting Elements
```cpp
arr.insert(42, 0); // Insert the value 42 at index 0.
```

### Deleting Elements
```cpp
arr.deleteValue(0); // Delete the element at index 0.
```

### Searching for Elements
```cpp
int index = arr.search(42); // Search for the value 42 in the array.
```

### Sorting the Array
```cpp
arr.bubbleSort(); // Sort the array elements.
```

### Reversing the Array
```cpp
arr.reverseArray(); // Reverse the array elements.
```

### Merging Arrays
```cpp
DynamicArray arr1(10);
DynamicArray arr2(10);
// Add elements to arr1 and arr2...
DynamicArray mergedArr = arr1.merge(arr2); // Merge arr1 and arr2 into a new array.
```

### Accessing Elements
```cpp
int value = arr[0]; // Access the first element of the array.
```

### Printing the Array
```cpp
std::cout << arr.print() << std::endl; // Print the array elements to the console.
```

## Implementation Details
- The `DynamicArray` class is implemented in C++ and uses raw pointers for managing its internal storage.
- Memory management is done manually using `malloc`, `free`, and manual element copying.

## Contribution
Feel free to fork this repository, submit pull requests, or send suggestions to improve the code.

