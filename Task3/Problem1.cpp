#include <iostream>
#include <Windows.h>

int fibonacciNumber(int);

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    cout << "Введите номер числа Фибоначчи: ";
    int number;
    cin >> number;
    cout << "Число Фиббоначи с номером " << number << ": " << fibonacciNumber(number);

    return EXIT_SUCCESS;
}

int fibonacciNumber(int number)
{
    switch (number)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return fibonacciNumber(number - 1) + fibonacciNumber(number - 2);
    }
}