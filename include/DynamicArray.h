#include <string>
#include <sstream>
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* array;          // Pointer to the dynamically-allocated array
    int currentSize;     // Current number of elements in the array
    int maxSize;        // Current capacity of the array

    // Method to resize the array
    void resizeArray(int resizeMult);

public:
    DynamicArray(int maxSize = 5); // Constructor with default capacity
    ~DynamicArray();                     // Destructor to free the allocated memory

    // Method to insert an element at a specified index
    void insert(int value, int index);

    // Method to delete an element at a specified index
    void deleteValue(int index);

    // Method to search for an element and return its index
    int search(int value);

    // Method to get the current size of the array
    void reverseArray();

    // Method to sort the array
    void bubbleSort();
    
    // Method to get the number of elements of the array (size)
    int size();

    // Method to get the maximum size of the array
    int getMaxSize();
        
    // Method to get the printf of the array
    std::string print();

    // Method to merge two arrays
    DynamicArray merge(const DynamicArray& other) const;

    // Overloaded operator to access elements in the array
    int& operator[](int index);

    // Const version of the overloaded operator for read-only access
    const int& operator[](int index) const;

};

#endif // DYNAMIC_ARRAY_H
