#include "../../Clock/Clock.hpp"

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>

template<int size>
void compareContainers()
{
    Clock clock;

    std::vector<int> vector(size);
    for (auto i = 0; i < size; ++i)
    {
        vector[i] = size - i;
    }

    std::array<int, size> array;
    for (auto i = 0; i < size; ++i)
    {
        array[i] = size - i;
    }

    std::deque<int> deque(size);
    for (auto i = 0; i < size; ++i)
    {
        deque[i] = size - i;
    }

    std::list<int> list(size);
    auto iter = list.begin();
    *(list.begin()) = size;
    for (auto i = 1; i < size; ++i)
    {
        iter = std::next(iter);
        *iter = size - i;
    }

    std::forward_list<int> forward_list(size);
    auto iterf = forward_list.begin();
    *(forward_list.begin()) = size;
    for (auto i = 1; i < size; ++i)
    {
        iterf = std::next(iterf);
        *iterf = size - i;
    }

    // Проверка заполнения контейнеров
    //std::cout << vector[0] << " " << vector[size - 1] << "\n";
    //std::cout << array[0] << " " << array[size - 1] << "\n";
    //std::cout << deque[0] << " " << deque[size - 1] << "\n";
    //std::cout << *(list.begin()) << " " << *(iter) << "\n";
    //std::cout << *(forward_list.begin()) << " " << *(iterf) << "\n\n";

    clock.start();
    std::sort(vector.begin(), vector.end());
    clock.stop();
    clock.printElapsed();

    clock.start();
    std::sort(array.begin(), array.end());
    clock.stop();
    clock.printElapsed();

    clock.start();
    std::sort(deque.begin(), deque.end());
    clock.stop();
    clock.printElapsed();

    clock.start();
    list.sort();
    clock.stop();
    clock.printElapsed();

    clock.start();
    forward_list.sort();
    clock.stop();
    clock.printElapsed();

    std::cout << '\n';

    // Проверка сортировки контейнеров
    //std::cout << vector[0] << " " << vector[size - 1] << "\n";
    //std::cout << array[0] << " " << array[size - 1] << "\n";
    //std::cout << deque[0] << " " << deque[size - 1] << "\n";
    //std::cout << *(list.begin()) << " " << *(std::prev(list.end())) << "\n";
    //auto current = forward_list.begin();
    //for (auto iter = forward_list.begin(); iter != forward_list.end(); ++iter)
    //{
    //    current = iter;
    //}
    //std::cout << *(forward_list.begin()) << " " << *(current) << "\n\n";
}

int main()
{
    compareContainers<10000>();
    compareContainers<100000>();
    compareContainers<200000>();

    return EXIT_SUCCESS;
}