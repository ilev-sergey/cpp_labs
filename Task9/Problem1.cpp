#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// quiksort

template < typename T >
int setPartition(T& values, int left, int right)
{
    int x = values[right];
    int less = left;

    for (int i = left; i < right; ++i)
    {
        if (values[i] <= x)
        {
            std::swap(values[i], values[less]);
            ++less;
        }
    }

    std::swap(values[less], values[right]);
    return less;
}

template < typename T >
void quickSortImpl(T& values, int left, int right)
{
    if (left < right)
    {
        int q = setPartition(values, left, right);
        quickSortImpl(values, left, q - 1);
        quickSortImpl(values, q + 1, right);
    }
}

template < typename T >
void quickSort(T& values)
{
    if (!values.empty())
    {
        quickSortImpl(values, 0, values.size() - 1);
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

int main()
{
    std::cout << "Static array tests:\n\n";

    int a[] = { 2, 5, -6, 1, 11, -1 };

    std::cout << "Original array: " << "\n";
    print(a);
    std::cout << "\n\n";

    //quickSort(a);

    std::cout << "Sorted array: " << "\n";
    print(a);
    std::cout << "\n\n\n";

    // ===============================================

    std::cout << "Dynamic array tests:\n\n";

    int b[] = { 2, 5, -6, 1, 11, -1 };

    std::cout << "Original array: " << "\n";
    print(b);
    std::cout << "\n\n";

    //quickSort(b);

    std::cout << "Sorted array: " << "\n";
    print(b);
    std::cout << "\n\n\n";

    // ===============================================

    std::cout << "std::vector tests:\n\n";

    std::vector<int> c{ 2, 5, -6, 1, 11, -1 };

    std::cout << "Original vector: " << "\n";
    print(c);
    std::cout << "\n\n";

    quickSort(c);

    std::cout << "Sorted vector: " << "\n";
    print(c);
    std::cout << "\n";

    return EXIT_SUCCESS;
}