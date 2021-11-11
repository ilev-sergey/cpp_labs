#include <iostream>
#include <string>
#include <vector>

template <typename Type, typename ... Args>
Type* createObject(Args ... args)
{
    Type* object = new Type{ args ... };
    return object;
}

int main()
{
    auto a = createObject<int>(7);
    std::cout << *a << "\n";
    delete a;

    auto b = createObject<std::string>("Hello, world!");
    std::cout << *b << "\n";
    delete b;

    auto v = createObject<std::vector<int>>(1, 3, -8);
    for (auto value : *v)
    {
        std::cout << value << " ";
    }
    std::cout << "\n";
    delete v;

    return EXIT_SUCCESS;
}