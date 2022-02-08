#include <iostream>
#include <functional>

int sum1(int a, int b) { return a + b; }

void print() {}

int main()
{
    // std::is_function< decltype(var) > == true 
    // only if var is function (not lambda and other functors)
    // 
    // std::function is functor, not only function
    // function is always functor, but not on the contary

    auto lambda = []() {};
    std::cout << std::boolalpha;

    // std::function is not function (but functor)
    std::cout << std::is_function< std::function<int> >::value << "\n\n";

    // function "sum1" is function
    std::cout << std::is_function<decltype(sum1)>::value << "\n";
    std::cout << typeid(sum1).name() << "\n\n";

    // function "print" is function
    std::cout << std::is_function<decltype(print)>::value << "\n";
    std::cout << typeid(print).name() << "\n\n";

    // lambda expression is not function (but functor)
    std::cout << std::is_function<decltype(lambda)>::value << "\n";
    std::cout << typeid(lambda).name() << "\n\n";

    // here are errors
    //std::cout << std::is_function<decltype([]() {})>::value << "\n";
    //std::cout << typeid([]() {}).name() << "\n\n";

    //dynamic_cast < std::function < int(int, int) > >(sum1)

    // create functor from function
    std::function < int(int, int) > func = sum1;

    // work with functor as with function
    std::cout << func(5, 7) << "\n\n";

    // create functor from lambda expression
    std::function < int(int, int) > func1 = [](int a, int b) { return a + b; };
    std::cout << typeid(func1).name() << "\n\n";

    // work with functor as with lambda
    std::cout << func1(5, 7) << "\n";;

    return EXIT_SUCCESS;
}