#ifndef SORT_HPP_INCLUDED
#define SORT_HPP_INCLUDED

#include <iostream>

// Alias for a type of pointers to comparison functions
template <typename T>
using comparisonFcn = bool (*)(const T&, const T&);

// Structure for associative table of letters and comparison functions
template <typename T>
struct comparisonStruct
{
    char letter;
    comparisonFcn<T> fcn;
};

// Comparison function that will sort the array in the descending order.
// In selection sort, the parameter x is the estimated minimum element of
// the array and y is the current element of the array. In bubble, x and y
// are two adjacent elements. In selection sort, we search for minimum
// to place it to the left side of the array. In bubble, we move the
// maximum element to the right side of the array
template <typename T>
bool ascend(const T &x, const T &y)
{
    return y < x;
}

// Comparison function that will sort the array in descending order.
// In selection sort, the parameter x is the estimated maximum element of
// the array and y is the current element of the array. In bubble, x and y
// are two adjacent elements. In selection sort, we search for maximum
// to place it to the left side of the array. In bubble, we move the
// minimum element to the right side of the array
template <typename T>
bool descend(const T &x, const T &y)
{
    return y > x;
}

// Function that changes the values of two elements
template <typename T>
void swap(T &x, T &y)
{
    T temp{ x };
    x = y;
    y = temp;
}

// The function makes association between user-inputted letter
// and comparison function using associative table
template <typename T>
comparisonFcn<T> getComparisonFunction(const char &letter)
{
    // Initialization of associative table
    const comparisonStruct<T> comp_array[]
    {
        { 'a', ascend },
        { 'd', descend }
    };

    for (const auto &comparison : comp_array)
        if (comparison.letter == letter)
            return comparison.fcn;

    return ascend;
}

// A selection sort function that uses a function pointer as a parameter to
// do a user-defined comparison and sort the array in required order
template <typename T>
void selectionSort(T *array, const int &length, comparisonFcn<T> comparison)
{
    // Outer loop iterates through the unsorted part of the array
    // and to the penultimate element because inner loop iterator starts
    // from the value of outer loop iterator + 1.
    for (int i{}; i < length - 1; ++i)
    {
        // Index of the maximum/minimum element, depending on the required
        // sorting order. By default, it is the initial value of the outer
        // loop iterator (first element in the unsorted part of the array)
        int bestIndex{ i };

        // Inner loop starts from one element ahead of the outer loop because
        // sorted part is on the left side of the array and index of the first
        // unsorted element will always be stored in the bestIndex variable
        for (int j{i + 1}; j < length; ++j)
            // If current element is lower/higer (ascend/descend) than the
            // bestIndex, current element becomes best. Comparison condition
            // is based on user choice
            if (comparison(array[bestIndex], array[j]))
                bestIndex = j;

        // Swaps first element in the unsorted side of the array with the
        // maximum/minimum element found in the inner loop cycle. As a result,
        // that element becomes the last in the left sorted part, the number of
        // the unsorted elements decreases by 1 and the iterator of the outer
        // loop moves forward by one
        swap(array[bestIndex], array[i]);
    }
}

// A bubble sort function that uses a function pointer as a parameter to
// do a user-defined comparison and sort the array in required order
template <typename T>
void bubbleSort(T *array, const int &length, comparisonFcn<T> comparison)
{
    // Outer loop is used to track the number of sorts. Starts with one and
    // repeats until only one element remains in the unsorted part which is
    // equivalent to [array length-1] times
    for (int sortNumber{1}; sortNumber < length; ++sortNumber)
    {
        // Mark that will become false if at least one swap occurs in inner loop
        bool noSwap{true};

        // Inner loop iterates to the penultimate element in the unsorted part
        // of the array which is [array length-sort number] element because it
        // compares the pairs of elements ([i] and [i+1]), the sorted elements
        // are located on the right side of the array and with each sort the
        // number of the unsorted elements will decrease by one
        for (int bubbleIndex{}; bubbleIndex < length - sortNumber; ++bubbleIndex)
            // Comparison between two adjacent elements based on user's choice
            if (comparison(array[bubbleIndex], array[bubbleIndex+1]))
            {
                // Swaps elements if the condition is true. As a result,
                // the maximum/minimum (ascend/descend) element will move
                // to the right sorted part of the array
                swap(array[bubbleIndex], array[bubbleIndex+1]);
                noSwap = false;
            }

        // If no swap was made during the current sort, it means that the array
        // is completely sorted and sorting can be stopped
        if (noSwap)
        {
            std::cout << "Early termination on iteration number "
                      << sortNumber << '\n';
            break;
        }
    }
}

#endif // SORT_HPP_INCLUDED
