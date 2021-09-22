#include <iostream>
#include <Windows.h>
#include <vector>

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

    return EXIT_SUCCESS;
}

void mergeSort(std::vector<int>)
{

}