#include "DynamicArray.h"
#include <cstdio>
#include <stdio.h>
#include <iostream>

int main()
{
    DynamicArray arr(3);
    arr.insert(10, 0);
    arr.insert(5, 1);
    arr.insert(12, 1);

    std::cout << "Maximum Size: " << arr.getMaxSize() << std::endl;
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << &(arr[i]) << '\n';
    }
    std::cout << arr.print() << std::endl;
    std::cout << std::endl;

    arr.insert(20, 2);
    arr.insert(15, 3);

    std::cout << "Maximum Size: " << arr.getMaxSize() << std::endl;
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << &(arr[i]) << '\n';
    }
    std::cout << arr.print() << std::endl;
    std::cout << std::endl;

    std::cout << "Reverse the array" << std::endl;
    arr.reverseArray();
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << &(arr[i]) << '\n';
    }
    std::cout << arr.print() << std::endl;
    std::cout << std::endl;

    std::cout << "Sort the array" << std::endl;
    arr.bubbleSort();
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << &(arr[i]) << '\n';
    }
    std::cout << arr.print() << std::endl;
    std::cout << std::endl;
        
    DynamicArray arr2(3);
    arr.insert(90, 0);
    arr.insert(91, 1);
    arr.insert(92, 1);

    arr.merge(arr2);
    std::cout << "Merge the array" << std::endl;
    arr.bubbleSort();
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Element " << i << ": " << arr[i] << " Memory address: " << &(arr[i]) << '\n';
    }
    std::cout << arr.print() << std::endl;
    std::cout << std::endl;

    return 0;
}