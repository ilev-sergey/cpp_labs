#include <iostream>
#include <Windows.h>
#include <vector>

int main2()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    cout << "¬ведите кол-во элементов: ";
    int length;
    cin >> length;

    vector<int> array{};
    array.resize(length);

    cout << "¬ведите элементы массива: ";
    for (int i = 1; i <= length; ++i)
    {
        cin >> array[i - 1];
    }

    cout << "¬ведите искомый элемент: ";
    int target;
    cin >> target;

    cout << "¬ведЄнный массив: " << endl;
    for (auto const& element : array)
        cout << element << ' ';
    cout << endl;

    int left = 0, right = length - 1;
    {
        int middle = 0;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (array[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                if (array[middle] > target)
                {
                    right = middle - 1;
                }
                else
                {
                    cout << "Element exists, position: " << ++middle;
                    return EXIT_SUCCESS;
                }
            }
        }
        cout << "Element not found";
        return EXIT_SUCCESS;
    }
    
}