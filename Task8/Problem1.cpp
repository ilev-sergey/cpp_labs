#include <iostream>
#include <cmath>

enum class Codes
{
    SUCCESS,
    INVALID_VALUE,
    OUT_OF_RANGE
};

struct Struct
{
    double result{ 0 };
    Codes code;
};

Struct& calculateSqrt(double x)
{
    Struct data;

    if (x > 10000)
    {
        data.code = Codes::OUT_OF_RANGE;
        return data;
    }

    if (x < 0)
    {
        data.code = Codes::INVALID_VALUE;
        return data;
    }

    data = { sqrt(x), Codes::SUCCESS };
    return data;
}

void printData(const Struct& data)
{
    switch (data.code)
    {
    case Codes::INVALID_VALUE:
        std::cout << "Entered invalid value" << "\n";
        return;
    case Codes::OUT_OF_RANGE:
        std::cout << "Entered out of range value" << "\n";
        return;
    case Codes::SUCCESS:
        std::cout << "Square root = " << data.result << "\n";
    }
}

union Union
{
    double result{ 0 };
    Codes code;
};

Union& U_calculateSqrt(double x)
{
    Union data;

    if (x > 10000)
    {
        data.code = Codes::OUT_OF_RANGE;
        return data;
    }

    if (x < 0)
    {
        data.code = Codes::INVALID_VALUE;
        return data;
    }

    data.result = sqrt(x);
    return data;
}

void U_printData(const Union& data)
{
    switch (data.code)
    {
    case Codes::INVALID_VALUE:
        std::cout << "Entered invalid value" << "\n";
        return;
    case Codes::OUT_OF_RANGE:
        std::cout << "Entered out of range value" << "\n";
        return;
    }
    std::cout << "Square root = " << data.result << "\n";
}

int main()
{
    // Structure tests
    printData(calculateSqrt(25));
    printData(calculateSqrt(-1));
    printData(calculateSqrt(1e9));

    std::cout << "\n";

    // Union tests
    U_printData(U_calculateSqrt(25));
    U_printData(U_calculateSqrt(-1));
    U_printData(U_calculateSqrt(1e9));

    return EXIT_SUCCESS;
}