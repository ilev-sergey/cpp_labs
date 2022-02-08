#include <iostream>
#include <Windows.h>
#include <vector>
#include <functional>

double calculate(double, double, std::function<double(double, double)>);

int main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    const int amountOfLambdas = 4;

    vector<function<double(double, double)>> lambdas =
    { [](double x, double y) {return x + y; },
      [](double x, double y) {return x - y; },
      [](double x, double y) {return x * y; },
      [](double x, double y) {return x / y; } };

    cout << "Введите x, y: ";
    double x;
    cin >> x;
    double y;
    cin >> y;

    cout << endl << "Вывод в формате: " << endl << "+ - * /" << endl << endl;
    for (int i = 0; i < amountOfLambdas; ++i)
    {
        cout << calculate(x, y, lambdas[i]) << " ";
    }
    cout << endl;
    
    return EXIT_SUCCESS;
}

double calculate(double x, double y, std::function<double(double, double)> function)
{
    return function(x, y);
}