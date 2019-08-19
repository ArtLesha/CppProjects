#ifndef FIXEDPOINT2_HPP_INCLUDED
#define FIXEDPOINT2_HPP_INCLUDED

#include <iostream>

class FixedPoint2
{
private:
    int16_t m_base{};   // Integer part
    int8_t m_decimal{}; // Fractional part, after decimal

public:
    // Default constructor which takes integer
    // and floating parts of number as arguments
    FixedPoint2(int16_t, int8_t);

    // Constructor for double number which decompose it into two parts
    FixedPoint2(double value);

    // Overloaded unary minus operator as member function
    FixedPoint2& operator-();

    // Type cast into double from FixedPoint2 type
    operator double() const;

    // Overloaded equality operator as friend function
    friend bool operator==(const FixedPoint2&, const FixedPoint2&);
};

// Overloaded binary plus operator as normal function
FixedPoint2 operator+(const FixedPoint2&, const FixedPoint2&);

// Overloaded output operator as normal function
std::ostream& operator<<(std::ostream&, const FixedPoint2&);

// Overloaded input operator as normal function
std::istream& operator>>(std::istream&, FixedPoint2&);

// Function for overloaded binary plus operator test
void testAddition();

#endif // FIXEDPOINT2_HPP_INCLUDED
