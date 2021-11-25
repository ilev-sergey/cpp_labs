#include <iostream>

constexpr bool isPrimeLoop(int i, int k)
{
    if (k * k <= i)
    {
        if (i % k == 0)
            return false;

        isPrimeLoop(i, k + 1);
    }
    else
    {
        return true;
    }
}

constexpr bool isPrime(int i)
{
    return isPrimeLoop(i, 2);
}

constexpr int nextPrime(int k)
{
    if (isPrime(k))
        return k;

    return nextPrime(k + 1);
}

constexpr int getPrimeLoop(int i, int k)
{
    if (i == 0)
        return k;

    return getPrimeLoop(i - 1, nextPrime(k + 1));
}

constexpr int getPrime(int i)
{
    return getPrimeLoop(i - 1, 2);
}

int main()
{
    constexpr int test = getPrime(1);

    std::cout << "1st prime number: " << getPrime(1) << "\n"; // 2
    std::cout << "5th prime number: " << getPrime(5) << "\n"; // 11
    std::cout << "15th prime number: " << getPrime(15) << "\n"; // 47

    return EXIT_SUCCESS;
}