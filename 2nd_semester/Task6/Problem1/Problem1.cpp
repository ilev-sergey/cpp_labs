#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream file("./Problem1/test.txt"); 

    std::string str{
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    };

    for (auto iterator = std::begin(str); iterator != std::end(str); ++iterator)
    {
        if (std::next(iterator) == std::end(str))
        {
            std::cout << *iterator;
            break;
        }

        if (*iterator == '"')
        {
            do {
                std::cout << *iterator;
                ++iterator;
                if (std::next(iterator) == std::end(str))
                {
                    std::cout << *iterator;
                    std::cout << "\nError! No closing '\"'";
                    exit(-1);
                }
            }
            while (!(*iterator != '\\' && *std::next(iterator) == '"'));
            std::cout << *iterator++;
        }

        if (*iterator == '/' && *std::next(iterator) == '/')
        {
            auto lower_bound = iterator;
            while (*iterator != '\n')
            {
                ++iterator;
            }
            str.erase(lower_bound, iterator);
            iterator = lower_bound;
        }

        if (*iterator == '/' && *std::next(iterator) == '*')
        {
            auto lower_bound = iterator;
            if (std::next(iterator, 2) == std::end(str))
            {
                std::cout << "\nError! No closing '*/'";
                exit(-1);
            }
            std::advance(iterator, 2);

            while(!(*iterator == '*' && *std::next(iterator) == '/'))
            {
                if (std::next(iterator) == std::end(str))
                {
                    std::cout << "\nError! No closing '*/'";
                    exit(-1);
                }
                ++iterator;
            }
            str.erase(lower_bound, iterator + 2);

            iterator = ((lower_bound == std::end(str)) ? iterator = lower_bound - 1: iterator = lower_bound);
        }

        std::cout << *iterator;
    }

    return EXIT_SUCCESS;
}