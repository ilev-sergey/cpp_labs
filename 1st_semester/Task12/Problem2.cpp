#include <iostream>

template <int n, typename = typename std::enable_if< (n >= 0) >::type>
struct FibNumber
{
    static constexpr int value = FibNumber<n - 1>::value + FibNumber<n - 2>::value;
};

template <>
struct FibNumber<0>
{
    static constexpr int value = 0;
};

template <>
struct FibNumber<1>
{
    static constexpr int value = 1;
};

int main()
{
    std::cout << "Fibonacci number for n = 10: " << FibNumber<10>::value << "\n";
    return EXIT_SUCCESS;
}