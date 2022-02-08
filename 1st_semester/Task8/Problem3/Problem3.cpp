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

    std::cout << "Trying create Fraction{1, 0}:\n";
    try
    {
        Fraction/*{1, 0}*/; // problem
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "Error: " << error.what() << "\n";
    }

    //int numerator{ 0 };
    //int denominator{ 0 };
    //std::cout << "Enter a fraction:\n";
    //std::cin >> numerator >> denominator;
    //try
    //{
    //    //Fraction fraction{ numerator, denominator };
    //    //fraction.reduceFraction();
    //    //std::cout << fraction;
    //}
    //catch (const std::invalid_argument& error)
    //{
    //    std::cout << "Error: " << error.what();
    //}
    //catch (...)
    //{
    //    std::cout << "Unknown error\n";
    //}

    return EXIT_SUCCESS;
}