#include <stdio.h>
#include <iostream>
#include <cstdlib>

// Function to initialize the array, allocating the necessary memory positions. 
int* allocateMemory(int size)
{
    int* array = (int*)malloc(size * sizeof(int)); 
    if (array == nullptr)
    {
        std::cerr << "Memory allocation failed" << std::endl;
        exit(EXIT_FAILURE);
    }
    return array;
}

// Function to resize the array 
void resizeArray(int **array, int resizeMult, int *ptrCurrentSize, int *maxSize)
{
    int *newArray = allocateMemory((resizeMult * (*maxSize))); // Allocate memory for the new array
    (*maxSize) = resizeMult * (*maxSize); // Set the out of scope maxSize to the new maxSize
    // Now that we've allocated the memory and created the array, we must copy the 
    // original array into the new one
    for (int i = 0; i < *ptrCurrentSize; ++i) {
        newArray[i] = (*array)[i];
    }
    // Deallocate the memory used for the original array
    free(*array);
    // Since we now want to modify the address our main array is pointing to, we must pass by reference the
    // address that the array originally points to. This way, by dereferencing the single pointer we can 
    // modify the address its pointing to.
    *array = newArray;
}

// Function to reverse the array
void reverseArray(int **array, int *ptrCurrentSize, int *maxSize)
{
    // Allocate necessary memory
    int *auxArray = allocateMemory(*maxSize);

    // Reverse-copy the elements from the original array
    int auxInt = *ptrCurrentSize - 1;
    for (int i = 0; i < *ptrCurrentSize; ++i)
    {
        *(auxArray + i) = *((*array) + auxInt);
        auxInt--; 
    }

    free(*array);
    *array = auxArray;
}

// Function to insert elements within the array.
void insert(int **array, int value, int index, int *ptrCurrentSize, int *maxSize)
{
    if (index < 0 || index > *ptrCurrentSize)
    {
        std::cerr << "Insertion index out of bounds or full array" << std::endl; 
        return;
    } 
    if (*ptrCurrentSize == *maxSize)
    {
        // We call this function using the memory address of the single pointer *arr, but the
        // function argument is a double pointer, so a pointer (array) to a pointer (&arr) is
        // created. 
        resizeArray(array, 2, ptrCurrentSize, maxSize);
    } 

    for (int i = *ptrCurrentSize; i > index; --i)
    {
        (*array)[i] = (*array)[i - 1];
    }

    (*array)[index] = value;
    (*ptrCurrentSize)++;
}

// Function to delete a number at a given position
void deleteValue(int *array, int index, int *ptrCurrentSize)
{
    if (index < 0 || index >= *ptrCurrentSize)
    {
        std::cerr << "Deletion index out of bounds" << std::endl;
    }

    for (int i = index; i < (*ptrCurrentSize) - 1; ++i){
        array[i] = array[i + 1];
    }

    (*ptrCurrentSize)--;
}

// Function to linearly search an element
int search(int *array, int value, int *ptrCurrentSize)
{
    for (int i = 0; i < (*ptrCurrentSize); ++i)
    {
        if (array[i] == value) return i;
    }
    std::cerr << "Element not found" << std::endl;
    return -1;
}


int main(){
    int maxSize = 5;
    int currentSize = 0; // This is a pointer to the last element of the array
    int *arr = allocateMemory(maxSize); // We initialize the array 
    std::cerr << "Memory address of the array: " << arr << std::endl; // This should prince the memory address of the first element
    std::cerr << "Insert three elements" << std::endl;
    insert(&arr, 10, 0, &currentSize, &maxSize);
    insert(&arr, 11, 1, &currentSize, &maxSize);
    insert(&arr, 12, 1, &currentSize, &maxSize); // We're pushing 12 to position 1, so now 11 moves to position 2

    for (int i = 0; i < currentSize; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << arr + i << '\n';
    }
    std::cout << std::endl;

    std::cerr << "Delete one element" << std::endl;
    deleteValue(arr, search(arr, 10, &currentSize), &currentSize);

    for (int i = 0; i < currentSize; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << arr + i << '\n';
    }
    std::cout << std::endl;

    std::cerr << "Insert 4 elements and resize the array" << std::endl;
    insert(&arr, 10, 2, &currentSize, &maxSize);
    insert(&arr, 13, 3, &currentSize, &maxSize);
    insert(&arr, 14, 4, &currentSize, &maxSize);
    insert(&arr, 15, 5, &currentSize, &maxSize);

    for (int i = 0; i < currentSize; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << arr + i << '\n';
    }
    std::cout << std::endl;

    std::cerr << "Reversed array" << std::endl;
    reverseArray(&arr, &currentSize, &maxSize);

    for (int i = 0; i < currentSize; ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << arr + i << '\n';
    }
    std::cout << std::endl;

    free(arr);
    arr = nullptr;
}
