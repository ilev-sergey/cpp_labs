#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x = 0.0, y = 0.0;
	cout << "Введите x: ";
	cin >> x;
	cout << "Введите y: ";
	cin >> y;

	cout << x << ", " << y << endl;

	// x = a, y = b

	x *= y;	   // x = ab, y = b
	y /= x;    // x = ab, y = 1/a
	y = 1 / y; // x = ab, y = a
	x /= y;    // x = b,  y = a

	cout << x << ", " << y;

	return EXIT_SUCCESS;
}