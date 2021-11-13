#include <iostream>

template < bool C, typename True_Type >
struct enable_if
{
    using type = True_Type;
};

template < typename True_Type >
struct enable_if < false, True_Type > {};

int main()
{
    std::cout << std::boolalpha
        << std::is_same< enable_if< (10 > 5), bool>::type, bool >::value << "\n"
      //<< std::is_same< enable_if< (10 < 5), bool>::type, bool >::value << "\n"

        << std::is_same< enable_if< std::is_function<int(int)>::value, void>::type, void >::value << "\n"
      //<< std::is_same< enable_if< std::is_function<void    >::value, void>::type, void >::value << "\n"

        << std::is_same< enable_if< std::is_array<int[2]>::value, int*>::type, int* >::value << "\n"
      //<< std::is_same< enable_if< std::is_array<int   >::value, int*>::type, int* >::value << "\n"

        << std::is_same< enable_if< std::is_const<const int>::value, char>::type, char >::value << "\n";
      //<< std::is_same< enable_if< std::is_const<int      >::value, char>::type, char >::value << "\n";

    return EXIT_SUCCESS;
}