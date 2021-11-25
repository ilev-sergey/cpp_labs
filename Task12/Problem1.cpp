#include <iostream>
#include <type_traits>
#include <string>

static constexpr int N = 5;
static constexpr int K = 3;

template <int n, typename = typename std::enable_if< (n >= 0) >::type>
struct Factorial
{
    static constexpr int value = n * Factorial<n - 1>::value;
};

template <>
struct Factorial<0>
{
    static constexpr int value = 1;
};

template <int n, int k, typename = typename std::enable_if< (n >= k) >::type>
struct BinomCoeff
{
    static constexpr int value = Factorial<n>::value / Factorial<k>::value / Factorial<n - k>::value;
};

template <int n, int k = 0>
struct Triangle
{
    static void print()
    {
        if constexpr (n == 0) std::cout << std::string(N - n, ' ');

        if constexpr (n > 0 && k == 0)
        {
            Triangle<n - 1, k>::print();
            std::cout << "\n" << std::string(N - n, ' ');
        }

        std::cout << BinomCoeff<n, k>::value << " ";

        if constexpr (n > k)
        {
            Triangle<n, k + 1>::print();
        }
    }
};

int main()
{
    std::cout << "C for n = " << N << ", k = " << K << ": " << BinomCoeff<N, K>::value << "\n\n";

    std::cout << "Pascal's triangle for n = " << N << ":\n";
    Triangle<N>::print();

    std::cout << "\n";
    return EXIT_SUCCESS;
}