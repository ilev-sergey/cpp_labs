#include <iostream>

template <typename T>
struct decay
{
private:
    using U = typename std::remove_reference<T>::type;
public:
    using type =
        typename std::conditional< std::is_array<U>::value,             // if (U is array)
            typename std::remove_extent<U>::type*,                      //     { ... }
                                                                        // else
            typename std::conditional< std::is_function<U>::value,      //     if (U is function)
                typename std::add_pointer<U>::type,                     //         { ... }
                                                                        //     else
                typename std::remove_cv<U>::type                        //         { ... }
            >::type
        >::type;
};

// if (U is array)
// {
//     return (type of U_element)*;
// }
// else
// {
//     if (U is function)
//     {
//         return U*;
//     }
//     else
//     {
//         return non_const U;
//     }
// }

int main()
{
    std::cout << std::boolalpha
        << std::is_same< decay<int>::type,        int  >::value << "\n"
        << std::is_same< decay<int&>::type,       int  >::value << "\n"
        << std::is_same< decay<int&&>::type,      int  >::value << "\n"
        << std::is_same< decay<const int&>::type, int  >::value << "\n"
        << std::is_same< decay<int[2]>::type,     int* >::value << "\n"
        << std::is_same< decay<int(int)>::type,   int(*)(int) >::value << "\n";

    return EXIT_SUCCESS;
}