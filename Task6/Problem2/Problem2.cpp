#include "Fraction.h"

int main()
{
    Fraction a{ 2, 5 };
    Fraction b{ 3, 8 };
    std::cout << "a = " << a << "b = " << b << "\n";

    std::cout << "a + b = " << a + b << "a - b = " << a - b <<
        "a * b = " << a * b << "a / b = " << a / b << "\n";

    std::cout << "Double a = " << a.convertToDouble() << "\n";
    std::cout << "Double b = " << b.convertToDouble() << "\n\n";

    std::cout << "a > b: " << std::boolalpha << (a > b) << "\n";
    std::cout << "a < b: " << std::boolalpha << (a < b) << "\n";
    std::cout << "a >= b: " << std::boolalpha << (a >= b) << "\n";
    std::cout << "a <= b: " << std::boolalpha << (a <= b) << "\n";
    std::cout << "a = b: " << std::boolalpha << (a == b) << "\n";
    std::cout << "a != b: " << std::boolalpha << (a != b) << "\n\n";

    std::cout << "++a = " << ++a;
    std::cout << "a++ = " << a++;
    std::cout << "a = " << a << "\n";

    int numerator;
    int denominator;
    std::cout << "Enter a fraction:\n";
    std::cin >> numerator >> denominator;
    Fraction fraction{ numerator, denominator };
    fraction.reduceFraction();
    std::cout << fraction;

    return EXIT_SUCCESS;
}