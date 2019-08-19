#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

#include <iostream>
#include <cassert>

// Definition of the array container class
// with all common functionalities
template <class T>
class Array
{
private:
    T *m_array{nullptr}; // Points to dynamically allocated for the array memory
    size_t m_length{};   // Holds number of elements in the array

public:
    // Default constructor with no arguments
    Array(): m_array{ nullptr }, m_length{}
    {
    }

    Array(size_t length = 0);
    Array(const Array&);
    ~Array();
    T& operator[](size_t index) const;

    // Common getter for the size of the array
    size_t getLength() const { return m_length; }

    void erase();
    void reallocate(size_t);
    void resize(size_t);
    void insertBefore(T, size_t);
    void removeElement(size_t);
    void fillArray();
    Array& operator=(const Array&);

    template <typename U>
    friend std::ostream& operator<< (std::ostream&, const Array<U>&);
};

#include "array.inl"

Array<int> fillIntArray();
Array<char> fillCharArray();
Array<double> fillDoubleArray();

#endif // ARRAY_HPP_INCLUDED
