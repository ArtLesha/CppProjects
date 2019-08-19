
/*
 This is a self-written container class for fixed point number
with 2 digits after decimal.
 FixedPoint2 consists of the following components:
 - variables that hold base part and fractional part of the number
 as integer values;
 - default constructor for base-fractional parts number input.
Changes sign of non-negative part if either one of the parts is negative;
 - constructor which decomposes double type input number into two parts
(base+fractional). The fractional part with 2 digits is obtained by
subtracting base part from input number, multiplying it by 100 and
rounding to integer number;
 - overloaded unary minus operator;
 - type cast to double type from FixedPoint2 type;
 - overloaded equality operator;
 - overloaded binary plus operator;
 - overloaded output/input operators;
*/

#include "FixedPoint2.hpp"
#include "input.hpp"
#include <iostream>

int main()
{
    std::cout << "Default constructor and overloaded output operator test:\n";
    FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	FixedPoint2 b(-2, 121);
	std::cout << b << '\n';

	FixedPoint2 c(2, -101);
	std::cout << c << '\n';

	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';

	FixedPoint2 e(0, -5);
	std::cout << e << '\n';

	std::cout << "\nOverloaded type cast test:\n";
	std::cout << static_cast<double>(e) << '\n';

	std::cout << "\ndouble into FixedPoint2 type constructor test:\n";
	FixedPoint2 f(0.01);
	std::cout << f << '\n';

	FixedPoint2 g(-0.01);
	std::cout << g << '\n';

	FixedPoint2 h(5.01);
	std::cout << h << '\n';

	FixedPoint2 i(-5.01);
	std::cout << i << "\n\n";

	testAddition();

	std::cout << "\nOverloaded unary minus test:\n";
	FixedPoint2 j(-0.48);
	std::cout << "Number before: " << j << '\n';
    std::cout << "Number after: "<< -j << '\n';

	std::cout << "\nEnter a floating point number\n"
              << "for overloaded input operator test: ";
	std::cin >> j;
	std::cout << "You entered: " << j << '\n';

	exit();

    return 0;
}
