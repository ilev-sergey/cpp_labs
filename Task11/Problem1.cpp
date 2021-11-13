#include <iostream>

int sum(int a, int b) { return a + b; }

template <typename T>
T& func(const T& a, const T& b) {}

template <typename>
struct is_function
{
    static constexpr bool value = false;
};

template <typename Return_t, typename ... Args>
struct is_function<Return_t(Args...)>
{
    static constexpr bool value = true;
    using return_t = Return_t;
};

int main()
{
    std::cout << std::boolalpha;

    std::cout << "Is it function?\n";
    std::cout << "int\t\t"          << is_function<int>::value << "\n";
    std::cout << "int()\t\t"        << is_function<int()>::value << "\n";
    std::cout << "int(int, bool)\t" << is_function<int(int, bool)>::value << "\n";
    std::cout << "void\t\t"         << is_function<void>::value << "\n";
    std::cout << "void()\t\t"       << is_function<void()>::value << "\n";
    std::cout << "sum\t\t"          << is_function<decltype(sum)>::value << "\n";
    std::cout << "func<double>\t"   << is_function<decltype(func<double>)>::value << "\n\n";

    // more than one suitable overload
    //std::cout << "std::max\t\t" << is_function<decltype(std::max<double, double>)>::value << "\n\n";

    std::cout << "Return type of\n";

    std::cout << "sum\t\t"        << typeid( is_function<decltype(sum)>::return_t).name() << "\n";
    std::cout << "func<double>\t" << typeid( is_function<decltype(func<double>)>::return_t ).name() << "\n";

    return EXIT_SUCCESS;
}