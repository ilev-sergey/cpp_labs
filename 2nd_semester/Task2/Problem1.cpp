#include <iostream>
#include <vector>

void printInfo(const std::vector<int>& vector)
{
    std::cout << "size = " << vector.size() <<
        ", capacity = " << vector.capacity() << "\n\n";
}

int main()
{
    std::vector<int> vector(100, 0);

    printInfo(vector); // ����� ������������� capacity = size

    std::cout << "push_back(1)\n";
    vector.push_back(0);

    printInfo(vector); // ����� push back (���� size = capacity) capacity *= 1.5

    std::cout << "reserve(1000)\n";
    vector.reserve(1000);
    printInfo(vector); // ����� reserve(n) capacity = n

    std::cout << "reserve(150)\n";
    vector.reserve(150);
    printInfo(vector); // ����� reserve(n) (n < capacity): capacity �� ����������

    std::cout << "reserve(200000000)\n";
    vector.reserve(200000000);
    vector.resize(200000000);
    printInfo(vector);

    //std::cout << "push_back(0)\n"; 
    //vector.push_back(0); // std::bad_alloc
    //printInfo(vector);

    return EXIT_SUCCESS;
}