#include "Array.h"

template <class Type>
void printInfo(Type * _ptr, std::size_t _length) // print for cpp array
{
    std::string result{ "[" };
    std::string comma;
    for (auto i = 0; i < _length; ++i)
    {
        result += comma + std::to_string(_ptr[i]);
        comma = ", ";
    }
    result += "]";
    std::cout << "arr  = " << result << "  |  location = " << _ptr << "  |  length = " << _length << "\n";
}

int main()
{
    std::size_t length = 6;
    int *b = new int[length] { 2, 5, -6, 1, 11, -1 };
    printInfo(b, length);

    Array<int> arr1{b, length};
    arr1.printInfo(1);

    std::cout << "\n========================================\n\n";

    b[2] = -1;
    printInfo(b, length);
    arr1.printInfo(1);

    delete[] b;

    std::cout << "\n========================================\n\n";

    Array<int> arr2;
    arr2.printInfo(2);
    std::cout << std::boolalpha << "arr2._ptr == static_cast<int*>(nullptr): " << (arr2.getPtr() == static_cast<int*>(nullptr)) << "\n";

    std::cout << "\n========================================\n\n";

    Array<int> arr3{ arr1 };
    arr3.printInfo(3);
    arr1.printInfo(1);

    std::cout << "\n========================================\n\n";

    Array<int> arr4{ std::move(arr1) };
    arr4.printInfo(4);
    arr3.printInfo(3);
    arr1.printInfo(1);

    std::cout << "\n========================================\n\n";

    Array<int> arr5;
    arr5 = arr4;
    arr5.printInfo(5);
    arr4.printInfo(4);

    std::cout << "\n========================================\n\n";

    Array<int> arr6;
    arr6 = std::move(arr4);
    arr6.printInfo(6);
    arr4.printInfo(4);

    std::cout << "\n========================================\n\n";

    std::cout << "arr6[4] = " << arr6[4] << "\n";

    arr6.printInfo(6);

    arr6.resize(10);
    arr6.printInfo(6);

    arr6.resize(4);
    arr6.printInfo(6);

    std::cout << "arr6.size() = " << arr6.size() << "\n";

    std::cout << "\n========================================\n\n";

    b = new int[2] { 2, -3};
    Array<int> arr7{ b, 2 };
    delete[] b;

    arr6.printInfo(6);
    arr7.printInfo(7);

    arr6.swap(arr7);
    std::cout << "\n";

    arr6.printInfo(6);
    arr7.printInfo(7);

    arr7.swap(arr6);
    std::cout << "\n";

    arr6.printInfo(6);
    arr7.printInfo(7);

    std::cout << "\n========================================\n\n";

    Array<int> arr8{ 1, 2, 8, 11 };
    arr8.printInfo(8);

    Array<bool> arr9{ true, false, true };
    arr9.printInfo(9);

    Array<std::string> arr10{ "Hello,", "world!"};
    arr10.printInfo(10);

    return EXIT_SUCCESS;
}