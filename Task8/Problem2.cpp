#include <iostream>
#include <cmath>
#include <exception>

double calculateSqrt(double x)
{
    if (x > 10000)
    {
        throw std::invalid_argument("Entered out of range value\n");
    }

    if (x < 0)
    {
        throw std::invalid_argument("Entered invalid value\n");
    }

    return sqrt(x);
}

int main()
{
    try
    {
        std::cout << "Square root of 25 = " << calculateSqrt(25) << "\n\n";
        //std::cout << "Trying to calculate sqrt of -1:" << calculateSqrt(-1) << "\n\n";
        std::cout << "Trying to calculate sqrt of 1e9:" << calculateSqrt(1e9) << "\n\n";
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "\n";
        std::cout << "Error: " << error.what();
        exit(-1);
    }	
    catch (...)
    {
        std::cout << "\n";
        std::cout << "Unknown error";
        exit(-1);
    }

    return EXIT_SUCCESS;
}