
/*
 This is a self-written container class for double-precision
floating point numbers.
 Decimal consists of the following components:
 - variables that hold integer and fractional parts of the number
 and number of digits after decimal separator as integer values;
 - default constructor for integer-fractional parts number input.
Changes sign of non-negative part if either one of the parts is negative;
 - constructor which parses double-precision floating point number in
IEEE 754 bit format into two parts;
 - constructor for a string literal which parses it, finds floating point
number and decomposes into two parts;
 - overloaded unary minus operator;
 - type cast to double type from Decimal type;
 - overloaded equality operator;
 - overloaded binary plus operator;
 - overloaded output/input operators;
*/

#include "Decimal.hpp"
#include "input.hpp"
#include <iostream>
#include <iomanip>  // std::setprecision()

int main()
{
    std::cout << "Default constructor and overloaded output operator test:\n";
    Decimal a(34, 56);
	std::cout << a << '\n';

	Decimal b(-2, 121);
	std::cout << b << '\n';

	Decimal c(2, -101);
	std::cout << c << '\n';

	Decimal d(-2, -8);
	std::cout << d << '\n';

	Decimal e(0, -5);
	std::cout << e << '\n';

	std::cout << "\nOverloaded type cast test:\n";
	std::cout << static_cast<double>(e) << '\n';

	std::cout << "\ndouble into Decimal type constructor test:\n";
	Decimal f(0.01);
	std::cout << f << '\n';

	Decimal g(-0.01);
	std::cout << g << '\n';

	Decimal h(5.01);
	std::cout << h << '\n';

	Decimal i(-5.01);
	std::cout << i << "\n\n";

	testAddition();

	std::cout << "\nOverloaded unary minus test:\n";
	Decimal j(-0.48);
	std::cout << "Number before: " << j << '\n';
    std::cout << "Number after: "<< -j << '\n';

    std::cout << "\nString constructor test:\n";
    Decimal k("  a12345cd6789..0123456711564er98  ");
    std::cout << std::setprecision(17) << k << '\n';

	std::cout << "\nEnter a floating point number\n"
              << "for overloaded input operator test: ";
	std::cin >> j;
	std::cout << "You entered: " << j << '\n';

	exit();

    return 0;
}
