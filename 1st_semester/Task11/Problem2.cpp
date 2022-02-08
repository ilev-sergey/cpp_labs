#include <iostream>
#include <iomanip>

template <typename T>
struct is_const
{
    static constexpr bool value = false;
};

template <typename T>
struct is_const<const T>
{
    static constexpr bool value = true;
};

template <typename T>
struct add_const
{
    using type = const T;
};

template <typename T>
struct remove_const
{
    using type = T;
};

template <typename T>
struct remove_const <const T>
{
    using type = T;
};

int main()
{
    std::cout << std::boolalpha << std::left;
    int w{ 30 };
    using std::cout, std::setw;

    using T = int;
    cout << "Type = int\n\n";

    cout << setw(w) << "Const?"                    << is_const< T                     >::value << "\n";
    cout << setw(w) << "Const after add_const?"    << is_const< add_const<T>::type    >::value << "\n";
    cout << setw(w) << "Const after remove_const?" << is_const< remove_const<T>::type >::value << "\n\n\n";

    using F = const int;
    cout << "Type = const int\n\n";

    cout << setw(w) << "Const?"                    << is_const< F                     >::value << "\n";
    cout << setw(w) << "Const after add_const?"    << is_const< add_const<F>::type    >::value << "\n";
    cout << setw(w) << "Const after remove_const?" << is_const< remove_const<F>::type >::value << "\n";

    return EXIT_SUCCESS;
}