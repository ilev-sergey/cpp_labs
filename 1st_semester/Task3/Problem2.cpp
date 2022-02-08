#include <iostream>
#include <Windows.h>
#include <vector>

std::vector<int> mergeSort(std::vector<int>&);
std::vector<int> merge(std::vector<int>&, std::vector<int>&);

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    cout << "Введите количество элементов массива: ";
    int length;
    cin >> length;

    vector<int> array(length, 0);
    cout << "Введите массив: ";
    for (int i = 0; i < length; ++i)
    {
        cin >> array[i];
    }

    array = mergeSort(array);

    for (int & x : array)
    {
        cout << x << " ";
    }

    return EXIT_SUCCESS;
}

std::vector<int> mergeSort(std::vector<int> & array)
{
    using std::vector;

    if (array.size() <= 1)
    {
        return array;
    };

    vector<int> left;
    vector<int> right;

    for (int i = 0; i < array.size(); ++i)
    {
        if (i < array.size() / 2)
        {
            left.push_back(array[i]);
        }
        else
        {
            right.push_back(array[i]);
        }
    }
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

std::vector<int> merge(std::vector<int> & left, std::vector<int> & right)
{
    using std::vector;
    
    vector<int> array;

    int leftPosition = 0;
    int rightPosition = 0;

    while (leftPosition < left.size() && rightPosition < right.size())
    {
        if (left[leftPosition] <= right[rightPosition])
        {
            array.push_back(left[leftPosition]);
            ++leftPosition;
        }
        else
        {
            array.push_back(right[rightPosition]);
            ++rightPosition;
        }
    }

    while (leftPosition < left.size())
    {
        array.push_back(left[leftPosition]);
        ++leftPosition;
    }

    while (rightPosition < right.size())
    {
        array.push_back(right[rightPosition]);
        ++rightPosition;
    }
    return array;
}