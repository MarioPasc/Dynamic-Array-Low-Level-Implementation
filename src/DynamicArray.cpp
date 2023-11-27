#include "DynamicArray.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

// Constructor implementation
DynamicArray::DynamicArray(int capacity)
    : array(nullptr), currentSize(0), maxSize(capacity) 
    {
    array = (int*)malloc(capacity * sizeof(int));
    if (!array) 
    {
        std::cerr << "Failed to allocate memory for DynamicArray." << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Destructor implementation
DynamicArray::~DynamicArray() 
{
    free(array);
}

// Method to resize the Dynamic Array given a factor 
void DynamicArray::resizeArray(int factor)
{
    int newMaxSize = (factor * maxSize);
    int * newArray = (int*)malloc(sizeof(int) * newMaxSize); // Allocate memory for new array
    
    if (!newArray) 
    {
        throw std::bad_alloc(); 
    }

    for (int i = 0; i < currentSize; ++i)
    {
        *(newArray + i) =  *(array + i); // Copy the elements into the new array
    }

    free(array); // Deallocate memory
    array = newArray; // Update the pointer
    maxSize = newMaxSize; // Update the max Size
}

// Method to insert a new element into the Dynamic Array
void DynamicArray::insert(int value, int index)
{
    if (index < 0 || index > currentSize || currentSize > maxSize)
    {
        std::cerr << "Insertion index out of bounds or full array" << std::endl; 
        return;
    } 
    else if (currentSize == maxSize) // If the array has reached its maximum capacity, double its size
    {
        resizeArray(2);
    }
    
    for (int i = currentSize; i > index; --i)
    {
        array[i] = array[i - 1];
    }

    array[index] = value;
    (currentSize)++;
}

// Method to delete a value from the dynamic array
void DynamicArray::deleteValue(int index)
{
    if (index < 0 || index > currentSize)
    {
        throw std::out_of_range("Index must be within bounds");
    }

    for (int i = index; i < (currentSize - 1); ++i)
    {
        array[i] = array[i + 1];
    }

    array[currentSize] = 0; // Optional: Set the last element to a default value like 0
    currentSize--;
}

// Method to reverse the array
void DynamicArray::reverseArray()
{
    int *auxArray = (int*)malloc(sizeof(int) * maxSize);
    int auxCurrentSize = currentSize - 1;
    for (int i = 0; i < currentSize; ++i)
    {
        *(auxArray + i) = *(array + auxCurrentSize);
        auxCurrentSize--;
    }

    free(array);
    array = auxArray;
}

// Method to sort the array
void DynamicArray::bubbleSort()
{
    bool swapped;

    for (int i = 0; i < currentSize - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < currentSize - i - 1; ++j)
        {
            if (array[j] > array[j+1])
            {
                int temp = *(array + j + 1);
                *(array + j + 1) = *(array + j);
                *(array + j) = temp;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

// Method to linearly search for an element
int DynamicArray::search(int value)
{
    for (int i = 0; i < currentSize; ++i)
    {
        if (*(array + i) == value) return i;
    }
    std::cerr << "Value not found" << std::endl;
    return -1;
}

// Method to merge two arrays
DynamicArray DynamicArray::merge(const DynamicArray& array2) const
{
    int maxSizeNew = this->maxSize + array2.maxSize;
    DynamicArray newArray(maxSizeNew);

    int i;
    for (i = 0; i < this->currentSize; ++i)
    {
        newArray.insert(*(this->array + i), i);
    }
    for (i = 0; i < array2.currentSize; ++i)
    {
        newArray.insert(*(array2.array + i), this->currentSize + i);
    }

    return newArray;
}


// Return the number of elements within the array
int DynamicArray::size()
{
    return currentSize;
}

// Return the maximum size of the array
int DynamicArray::getMaxSize()
{
    return maxSize;
}

// Method to print the array 
std::string DynamicArray::print()
{
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < currentSize; ++i)
    {
        ss << *(array + i);
        if (i < currentSize - 1)
        {
            ss << ", ";
        }
    }   
    ss << "]";
    return ss.str();
}

// Method to access elements in the array (non-const version)
int& DynamicArray::operator[](int index) 
{
    if (index < 0 || index >= currentSize) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

// const version of the operator[] for read-only access
const int& DynamicArray::operator[](int index) const 
{
    if (index < 0 || index >= currentSize) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}
