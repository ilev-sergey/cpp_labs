#include <iostream>
#include <iomanip>

constexpr long long factorial(int n)
{
    long long result{ 1 };
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

constexpr double exponent(int n)
{
    double result{ 0 };
    for (int i = 0; i <= n; ++i)
    {
        result += 1.0 / factorial(i);
    }
    return result;
}

int main()
{
    constexpr double exp{ exponent(2) }; // compile-time
    std::cout << "Expasion to 2 terms: " << exp << "\n";

    constexpr double exp1{ exponent(20) }; // compile-time
    std::cout << std::setprecision(20) << "Expasion to 20 terms: " << exp1 << "\n";

    std::cout << "\t\t  e = 2.7182818284590452353";

    return EXIT_SUCCESS;
}