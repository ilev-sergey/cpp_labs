#include <iostream>

template <typename ... Args>
int countSizeOfArgs(Args ... args)
{
    int res{ 0 };
    ((res += sizeof(Args)), ...); 

    //  res += sizeof(Arg1),
    //  res += sizeof(Arg2),
    //  ...
    //  res += sizeof(ArgN),
    
    return res;
}

int countSizeOfArgs_r() { return 0; }

template <typename First, typename ... Args>
int countSizeOfArgs_r(First first, Args ... args)
{
    return sizeof(First) + countSizeOfArgs_r(args ...);
}

int main()
{
    std::cout << "sizeof(int) = " << sizeof(int) << "\n";
    std::cout << "sizeof(double) = " << sizeof(double) << "\n";
    std::cout << "sizeof(bool) = " << sizeof(bool) << "\n";
    std::cout << "sizeof(char) = " << sizeof(char) << "\n";
    std::cout << "sizeof(const char*) = " << sizeof(const char*) << "\n";

    std::cout << "\n";

    std::cout << "Size of (1, 'a', 'p', -9.1) = " << countSizeOfArgs<>(1, 'a', 'p', -9.1) << "\n";
    std::cout << "Size of (1, 'a', 'p', -9.1) = " << countSizeOfArgs_r<>(1, 'a', 'p', -9.1) << "\n";

    std::cout << "\n";

    std::cout << "Size of (true, 'q', 'abc') = " << countSizeOfArgs<>(true, 'q', 'abc') << "\n";
    std::cout << "Size of (true, 'q', 'abc') = " << countSizeOfArgs_r<>(true, 'q', 'abc') << "\n";

    return EXIT_SUCCESS;
}