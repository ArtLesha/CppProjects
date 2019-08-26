#ifndef DECIMAL_HPP_INCLUDED
#define DECIMAL_HPP_INCLUDED

#include <iostream>
#include <string>

class Decimal
{
private:
    int64_t m_integer{};    // Integer part
    int64_t m_fractional{}; // Fractional part, after decimal
    short   m_numDigits{};  // Number of digits after decimal

public:
    Decimal(int64_t, int64_t);
    Decimal(double);
    Decimal(std::string);
    Decimal& operator-();
    operator double() const;

    friend bool operator==(const Decimal&, const Decimal&);
};

Decimal operator+(const Decimal&, const Decimal&);
std::ostream& operator<<(std::ostream&, const Decimal&);
std::istream& operator>>(std::istream&, Decimal&);
int getDecDigit(const char&);
void testAddition();

#endif // DECIMAL_HPP_INCLUDED
