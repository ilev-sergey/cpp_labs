#include <iostream>
#include <functional>

template <typename Type, typename ... Args>
auto callFunction(Type functionPtr, Args ... args)
{
    return functionPtr(args ...);
}

int sum(int a, int b)
{
    return a + b;
}

void print()
{
    std::cout << "Hello, world!";
}

int main()
{
    std::cout << callFunction(sum, 14, -8) << "\n";
    std::cout << callFunction(([](int a, int b) { return a + b; }), 14, -8) << "\n";

    callFunction(print);
    std::cout << "\n";

    std::cout << callFunction([](int a, int b) { return std::max(a, b); }, 18, 25);

    return EXIT_SUCCESS;
}