
/*
 This is a program that performs sorting of arrays using selection
or bubble sort including user-defined comparison, function pointers
and template functions.
*/

#include "sort.hpp"
#include "input.hpp"
#include <iostream>
#include <string>

template<typename T>
void printArray(const T *array, const int &length)
{
    for (int index{}; index < length; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}

int main()
{
    // Test for integer array and bubble sort
    int array_i[]{ -3, 5, 10, 8, 2, 10, 2, 100, 51, -2, -100 };
    int arrayLength{ sizeof(array_i) / sizeof(array_i[0]) };

    std::cout << "\nThis is unsorted integer array: ";
    printArray(array_i, arrayLength);

    bubbleSort(array_i, arrayLength,
               getComparisonFunction<int>(getOrder()));

    std::cout << "\nThis is sorted integer array: ";
    printArray(array_i, arrayLength);


    // Test for double array and selection sort
    double array_d[]{ -0.51, 2.98, -10.1, 20.0, 15.2, 0, 0.01, -0.9, 151.25};
    arrayLength = sizeof(array_d) / sizeof(array_d[0]);

    std::cout << "\n\nThis is unsorted double array: ";
    printArray(array_d, arrayLength);

    selectionSort(array_d, arrayLength,
                  getComparisonFunction<double>(getOrder()));

    std::cout << "\nThis is sorted double array: ";
    printArray(array_d, arrayLength);


    // Test for string array and bubble sort
    std::string array_s[]{ "Matt", "Bella", "Kelvin", "Jack", "Alex", "Patrick" };
    arrayLength = sizeof(array_s) / sizeof(array_s[0]);

    std::cout << "\n\nThis is unsorted string array: ";
    printArray(array_s, arrayLength);

    bubbleSort(array_s, arrayLength,
               getComparisonFunction<std::string>(getOrder()));

    std::cout << "\nThis is sorted string array: ";
    printArray(array_s, arrayLength);

    exit();

    return 0;
}
