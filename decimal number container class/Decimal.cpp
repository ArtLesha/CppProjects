#include "Decimal.hpp"
#include <cmath>  // pow(), round(), modf(), abs(), trunc()
#include <string> // std::string

// Default constructor which takes integer
// and fractional parts of the number as arguments
Decimal::Decimal(int64_t int_part = 0, int64_t fract_part = 0):
    m_integer{ int_part }, m_fractional{ fract_part }
{
    // Count the number of digits in the fractional part
    // presented as an integer
    int64_t temp{ std::abs(fract_part) };
    while (temp > 0)
    {
        temp /= 10;
        ++m_numDigits;
    }

    // Check if only one of the parts is negative
    // and change the sign for the ease of arithmetic operations
    if ((m_integer < 0) != (m_fractional < 0))
    {
        if (m_integer >= 0) // Change the sign if integer part is non-negative
            m_integer = -m_integer;
        else
            m_fractional = -m_fractional; // else change the sign of fractional part
    }
}

// Constructor for double-precision floating point number
// which parses it into two parts
Decimal::Decimal(double value)
{
    // Parse bit representation of double-precision floating point number
    // into sign, exponent and mantissa field. Then convert the value with
    // binary radix into decimal radix.
    uint64_t *bits{ reinterpret_cast<uint64_t *>(&value) };
    int      sign{ (*bits >> 63) ? -1 : 1 };
    int      exponent{ (static_cast<int>(*bits >> 52) & 0x7FF) - 1023 };
    double   mantissa{ 1.0 + (*bits & 0xF'FFFF'FFFF'FFFF) / std::pow(2.0, 52) };
    double   temp{ sign * std::pow(2.0, exponent) * mantissa };

    double int_part{},   // Integer part of floating point number
           fract_part{}; // Fractional part

    // Decompose the resulting number into integer and fractional parts
    fract_part = std::modf(temp, &int_part);
    m_integer = static_cast<int64_t>(int_part);

    // Count the number of digits in fractional part
    temp = std::abs(fract_part);
    while (temp > 0)
    {
        // 17 decimal places maximum
        if (m_numDigits == 17)
            break;

        temp *= 10.0;
        ++m_numDigits;
        temp -= std::trunc(temp); // Cut off the integer part
    }

    // Multiply the fractional part by 10 to the power of the number of digits
    // after decimal and cut off the remaining fractional part so that the number
    // becomes an integer
    m_fractional = std::round(fract_part * std::pow(10.0, m_numDigits));
}

// Constructor for string literal which parses it for a floating point number
Decimal::Decimal(std::string s)
{
    const int length { static_cast<int>(s.length()) };
    bool  decimal_flag{false}; // Flag for decimal separator presence
    short decimal_index{},     // Index of the decimal separator
          digit{},             // Decimal value of the current character literal
          exponent{},          // Value of the current power of ten
          sign{1};             // Sign of the parsed floating point number

    // Check the presence of the minus sign and decimal separator
    for (int i {}; i < length; ++i)
    {
        if (s[static_cast<unsigned int>(i)] == '-')
            sign = -1;

        // Find the first occurrence of decimal separator
        if (s[static_cast<unsigned int>(i)] == '.' && i + 1 < length)
        {
            decimal_index = i;
            decimal_flag = true;
            break;
        }
    }

    // Parse the integer part. If there is a decimal separator in the string,
    // then start from the character preceding it, otherwise from the end of
    // the string and iterate till the beginning of the string
    for (int i {decimal_flag ? (decimal_index - 1) : (length - 1)}; i >= 0; --i)
    {
        // Convert character literal into decimal digit.
        // If it's dot or another character, continue the loop
        digit = getDecDigit(s[static_cast<unsigned int>(i)]);
        if (digit == 10 || digit == 11)
            continue;

        // Increment integer part by the value of current digit
        // multiplied by 10 in power of it's order of magnitude
        m_integer += std::round(digit * (std::pow(10.0, exponent++)));
    }

    // Parse the fractional part, only if there is a decimal separator
    // in the string
    if (decimal_flag)
    {
        // Parse the part after decimal separator and count the number
        // of digits
        for (int i{decimal_index + 1}; i < length; ++i)
        {
            // 17 decimal places maximum
            if (m_numDigits == 17)
                break;

            // Convert character literal into decimal digit.
            // If it's dot or another character, continue the loop
            digit = getDecDigit(s[static_cast<unsigned int>(i)]);
            if (digit == 10 || digit == 11)
                continue;

            ++m_numDigits;
        }

        // Convert the fractional part of floating point number
        // in the string directly to the fractional part of an object.
        // Exponent equals [m_numDigits - 1] because the values of parsed
        // digits are multiplied, and not the fractional part
        exponent = m_numDigits - 1;
        for (int i{decimal_index + 1}; i < length; ++i)
        {
            // Last significant digit
            if (exponent == -1)
                break;

            // Convert character literal into decimal digit.
            // If it's dot or another character, continue the loop
            digit = getDecDigit(s[static_cast<unsigned int>(i)]);
            if (digit == 10 || digit == 11)
                continue;

            // Increment fractional part by the value of current digit
            // multiplied by 10 in power of [m_numDigits + order of magnitude]
            m_fractional += std::round(digit * std::pow(10.0, exponent--));
        }
    }

    // Multiply by a sign to take into account the case with a minus
    m_integer *= sign;
    m_fractional *= sign;
}

// Overloaded unary minus operator as member function
Decimal& Decimal::operator-()
{
    m_integer = -m_integer;
    m_fractional = -m_fractional;
    return *this;
}

// Type cast into double from Decimal type
Decimal::operator double() const
{
    return m_integer + m_fractional / std::pow(10.0, m_numDigits);
}

// Overloaded equality operator as friend function
bool operator==(const Decimal &x, const Decimal &y)
{
        return x.m_integer == y.m_integer && x.m_fractional == y.m_fractional;
}

// Overloaded binary plus operator as normal function
Decimal operator+(const Decimal &x, const Decimal &y)
{
    return { static_cast<double>(x) + static_cast<double>(y) };
}

// Overloaded output operator as normal function
std::ostream& operator<<(std::ostream &out, const Decimal &value)
{
    return out << static_cast<double>(value);
}

// Overloaded input operator as normal function
std::istream& operator>>(std::istream &in, Decimal &value)
{
    double temp{};
    in >> temp;
    value = Decimal{ temp };
    return in;
}

// Return decimal digit according to character literal
int getDecDigit(const char &ch)
{
    switch (ch)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '.': return 10; // Case for decimal separator
        default : return 11;
    }
}

// Test of overloaded binary plus operator
void testAddition()
{
    using std::cout;

    cout << "Overloaded binary plus operator test:\n";
	cout << std::boolalpha;
	cout << (Decimal(0.75) + Decimal(1.23) == Decimal(1.98)) << '\n';
	cout << (Decimal(0.75) + Decimal(1.50) == Decimal(2.25)) << '\n';
	cout << (Decimal(-0.75)+ Decimal(-1.23)== Decimal(-1.98))<< '\n';
	cout << (Decimal(-0.75)+ Decimal(-1.50)== Decimal(-2.25))<< '\n';
	cout << (Decimal(0.75) + Decimal(-1.23)== Decimal(-0.48))<< '\n';
	cout << (Decimal(0.75) + Decimal(-1.50)== Decimal(-0.75))<< '\n';
	cout << (Decimal(-0.75)+ Decimal(1.23) == Decimal(0.48)) << '\n';
	cout << (Decimal(-0.75)+ Decimal(1.50) == Decimal(0.75)) << '\n';
}
