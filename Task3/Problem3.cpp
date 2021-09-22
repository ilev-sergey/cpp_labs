#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

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


    sort(array.begin(), array.end(), [](int a, int b)
        {
            return a > b;
        });
    
    cout << "Массив отсортирован по убыванию: " << endl;;
    for (int & x : array)
    {
        cout << x << " ";
    }
    cout << endl;


    sort(array.begin(), array.end(), [](int a, int b)
        {
            return a < b;
        });

    cout << "Массив отсортирован по возрастанию: " << endl;
    for (int & x : array)
    {
        cout << x << " ";
    }


    return EXIT_SUCCESS;
}
