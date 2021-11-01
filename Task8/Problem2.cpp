#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
#include <string>

double calculateSqrt(const double& x)
{
    if (x > 10000)
    {
        throw std::invalid_argument("entered out of range value");
    }

    if (x < 0)
    {
        throw std::invalid_argument("entered invalid value");
    }

    return sqrt(x);
}

double division(const double& a, const double& b)
{
    if (b == 0)
    {
        throw std::domain_error("can't be divided by zero");
    }

    return a / b;
}


int main()
{
    try
    {
        std::cout << "Square root of 25 = " << calculateSqrt(25) << "\n\n";
        //std::cout << "Trying to calculate sqrt of -1:" << calculateSqrt(-1);
        //std::cout << "Trying to calculate sqrt of 1e9:" << calculateSqrt(1e9);
    }
    catch (const std::invalid_argument& error)
    {
        std::cout << "\n";
        std::cout << "Caught std::invalid_argument: " << error.what() << "\n";
        exit(-1);
    }
    catch (...)
    {
        std::cout << "\n";
        std::cout << "Unknown error\n";
        exit(-1);
    }

    try
    {
        std::cout << "28/4 = " << division(28, 4) << "\n\n";
        //std::cout << "Trying to calculate 28/0: " << division(28, 0);
    }
    catch (const std::domain_error& error)
    {
        std::cout << "\n";
        std::cout << "Caught std::domain_error: " << error.what() << "\n";
        exit(-1);
    }
    catch (...)
    {
        std::cout << "\n";
        std::cout << "Unknown error\n";
        exit(-1);
    }

    try
    {
        std::vector<int> v(2);
        std::cout << "v[1] = " << v.at(1) << "\n\n";
        //std::cout << "Trying to get v[2]: " << v.at(2);
    }
    catch (const std::out_of_range& error)
    {
        std::cout << "\n";
        std::cout << "Caught std::out_of_range: " << error.what() << "\n";
        exit(-1);
    }
    catch (...)
    {
        std::cout << "\n";
        std::cout << "Unknown error\n";
        exit(-1);
    }

    try
    {
        std::vector<int> v;
        //std::cout << "Trying to call v.resize(-1): ";
        //v.resize(-1);
    }
    catch (const std::length_error& error)
    {
        std::cout << "\n";
        std::cout << "Caught std::length_error: " << error.what() << "\n";
        exit(-1);
    }
    catch (...)
    {
        std::cout << "\n";
        std::cout << "Unknown error\n";
        exit(-1);
    }

    try
    {
        std::string s{ "a" };
        //std::getline(std::cin, s);
        if (s.empty())
        {
            throw std::logic_error("empty string entered");
        }
        std::cout << "s = " << s << "\n";
    }
    catch (const std::logic_error& error)
    {
        std::cout << "\n";
        std::cout << "Caught std::logic_error: " << error.what() << "\n";
        exit(-1);
    }
    catch (...)
    {
        std::cout << "\n";
        std::cout << "Unknown error\n";
        exit(-1);
    }

    return EXIT_SUCCESS;
}