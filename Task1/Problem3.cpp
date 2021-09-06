#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	double a = 0.0, b = 0.0, c = 0.0; // ax^2 + bx + c = 0
	
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите c: ";
	cin >> c;

	double x1 = 0.0, x2 = 0.0;

	if (a == 0.0)
	{
		x1 = -c / b;
		cout << "Не является квадратным уравнением, x = " << x1;
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (D >= 0)
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << "x1 = " << x1 << ", " << "x2 = " << x2;
		}
		else
		{
			cout << "Решений нет";
		}
	}
	return EXIT_SUCCESS;
}