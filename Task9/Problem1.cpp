#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

template < typename T, typename F >
int setPartition(T& values, int left, int right, F comp)
{
    int x = values[right];
    int less = left;

    for (int i = left; i < right; ++i)
    {
        if (comp(values[i], x))
        {
            std::swap(values[i], values[less]);
            ++less;
        }
    }

    std::swap(values[less], values[right]);
    return less;
}

template < typename T, typename F >
void quickSortImpl(T& values, int left, int right, F comp)
{
    if (left < right)
    {
        int q = setPartition(values, left, right, comp);
        quickSortImpl(values, left, q - 1, comp);
        quickSortImpl(values, q + 1, right, comp);
    }
}

template < typename T >
void quickSort(T& values, std::size_t length)
{
    if (length)
    {
        quickSortImpl(values, 0, length - 1, std::less<>());
    }
}

template < typename T, typename F >
void quickSort(T& values, std::size_t length, F comp)
{
    if (length)
    {
        quickSortImpl(values, 0, length - 1, comp);
    }
}

template < typename T >
void print(T(&array))
{
    std::string result{ "[" };
    std::string comma;
    for (auto value : array)
    {
        result += comma + std::to_string(value);
        comma = ", ";
    }
    std::cout << result + "]";
}

template < typename T >
void print(T(&array), std::size_t size)
{
    std::string result{ "[" };
    std::string comma;

    std::for_each(array, array + size, [&result, &comma](auto value)
        {
            result += comma + std::to_string(value);
            comma = ", ";
        });

    std::cout << result + "]";
}

int main()
{
    std::cout << "Static array tests:\n\n";

    constexpr int clength = 6;
    int a[clength]{ 2, 5, -6, 1, 11, -1 };

    std::cout << "Original array: " << "\n";
    print(a);
    std::cout << "\n\n";

    quickSort(a, clength);
    std::cout << "Sorted array: " << "\n";
    print(a);
    std::cout << "\n\n";

    quickSort(a, clength, std::greater<>()); // std::greater<>() = [](Type a, Type b){ return a > b }
    std::cout << "Descending sorted array: " << "\n";
    print(a);
    std::cout << "\n\n\n";

    // ===============================================

    std::cout << "Dynamic array tests:\n\n";

    int length = 6;
    int* b = new int[length] { 2, 5, -6, 1, 11, -1 };

    std::cout << "Original array: " << "\n";
    print(b, length);
    std::cout << "\n\n";

    quickSort(b, length);
    std::cout << "Sorted array: " << "\n";
    print(b, length);
    std::cout << "\n\n";

    quickSort(b, length, std::greater<>());
    std::cout << "Descending sorted array: " << "\n";
    print(b, length);
    std::cout << "\n\n";

    delete[] b;

    return EXIT_SUCCESS;
}