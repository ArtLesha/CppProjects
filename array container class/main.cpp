
/*
 This is a self-written dynamically allocated resizable array container
class with all common functionalities implemented using class template.
 Array class consists of the following components:
 - pointer to the dynamically allocated memory and length of the allocated array;
 - default constructor with assertion from negative length and statement for
dynamic memory allocation;
 - deep copy constructor for initialization by another object. That constructor
checks if source is not empty, allocates memory and copies values;
 - default destructor with memory deallocation;
 - overloaded subscript operator with range-based assertion for index checking;
 - methods erase(), reallocate(), resize(), insertBefore(), removeElement() that
perform basic interactions with the array;
 - overloaded assignment operator with self-assignment check, old memory
deallocation, new memory allocation, values copying and *this pointer return
value for operator chaining;
 - overloaded output operator;
*/

#include "array.hpp"
#include "input.hpp"
#include <iostream>

int main()
{
    Array<int> a(8);
    a.fillArray();
    std::cout << "Created the array A with 8 elements and filled it:" << a;

    a.resize(9);
    std::cout << "Resized the array A to 9 elements:" << a;

    a.insertBefore(15, 7);
    std::cout << "Inserted number 15 in place of the element\n"
            "with index 7 in the array A:" << a;

    a.removeElement(3);
    std::cout << "Removed the element with index 3 from the array A:" << a;

    Array<int> temp{ fillIntArray() };
    Array<int> b{ temp };
    std::cout << "Array B is created using deep copy constructor:" << b;

    Array<int> c(5);
    std::cout << "Created empty array C using default constructor:" << c
         << "Tests of self-assignment and overloaded assignment"
            " operator chaining.";

	b = b;         // Self-assignment test
	c = b = c = b; // Overloaded assignment operator chaining test
	std::cout << "\nThat's our previously empty array C"
            " after chained assignments:" << b;

    std::cout << "Tests of class template instantiations.";
    Array<char> d{ fillCharArray() };
    std::cout << "\nArray D is created using"
                 " character array fill function:" << d;

    d.insertBefore('c', 2);
    std::cout << "Character \'c\' is inserted in place\n"
            "of the element with index 2 in the array D:" << d;

    Array<double> e{ fillDoubleArray() };
    std::cout << "Array E is created using"
                 " double array fill function:" << e;

    exit();

    return 0;
}
