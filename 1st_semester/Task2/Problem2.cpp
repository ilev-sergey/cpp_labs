#include <iostream>
#include <Windows.h>
#include <vector>

int main1()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    cout << "������� ���-�� ���������: ";
    int length;
    cin >> length;

    vector<int> array{};
    array.resize(length);

    cout << "������� �������� �������: ";
    for (int i = 1; i <= length; ++i)
    {
        cin >> array[i - 1];
    }

    cout << "�������� ������: " << endl;
    for (auto const& element : array)
        cout << element << ' ';
    cout << endl;


    for (int j = 1, i, key; j < length; ++j) // insertion sort
    {
        key = array[j];
        i = j - 1;
        while (i >= 0 and array[i] > key)
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }


    cout << "��������������� ������: " << endl;
    for (auto const& element : array)
        cout << element << ' ';

    return EXIT_SUCCESS;
}