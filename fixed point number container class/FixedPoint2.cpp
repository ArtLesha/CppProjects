#include "FixedPoint2.hpp"
#include <cmath> // for std::round()

// Default constructor which takes integer
// and floating parts of number as arguments
FixedPoint2::FixedPoint2(int16_t base = 0, int8_t decimal = 0):
    m_base{ base }, m_decimal{ decimal }
{
    // Check if only one of the parts is negative
    // and change sign for the ease of arithmetic operations
    if ((m_base < 0) != (m_decimal < 0))
    {
        if (m_base >= 0) // Change sign if integer part is non-negative
            m_base = -m_base;
        else
            m_decimal = -m_decimal; // else change sign of fractional part
    }
}

// Constructor for double number which decompose it into two parts
FixedPoint2::FixedPoint2(double value)
{
    // Get integer part of double argument
    m_base = static_cast<int>(value);
    // Get fractional part
    m_decimal = static_cast<int8_t>(std::round((value - m_base) * 100));
}

// Overloaded unary minus operator as member function
FixedPoint2& FixedPoint2::operator-()
{
    m_base = -m_base;
    m_decimal = -m_decimal;
    return *this;
}

// Type cast into double from FixedPoint2 type
FixedPoint2::operator double() const
{
    return m_base + static_cast<double>(m_decimal) / 100 ;
}

// Overloaded equality operator as friend function
bool operator==(const FixedPoint2 &x, const FixedPoint2 &y)
{
        return x.m_base == y.m_base && x.m_decimal == y.m_decimal;
}

// Overloaded binary plus operator as normal function
FixedPoint2 operator+(const FixedPoint2 &x, const FixedPoint2 &y)
{
    return { static_cast<double>(x) + static_cast<double>(y) };
}

// Overloaded output operator as normal function
std::ostream& operator<<(std::ostream &out, const FixedPoint2 &value)
{
    return out << static_cast<double>(value);
}

// Overloaded input operator as normal function
std::istream& operator>>(std::istream &in, FixedPoint2 &value)
{
    double temp{};
    in >> temp;
    value = FixedPoint2{ temp };
    return in;
}

// Test of overloaded binary plus operator
void testAddition()
{
    std::cout << "Overloaded binary plus operator test:\n";
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n';
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n';
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n';
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n';
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n';
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n';
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n';
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n';
}
