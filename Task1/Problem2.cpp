#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long c = 29979245800;

	int i;
	cout << "Выберите единицы измерения:" << endl;
	cout << "1 - Кл" << endl << "2 - А" << endl << "3 - В" << endl << "4 - В/м" << endl;
	cin >> i;

	double x;
	cout << "Введите исходное значение: ";
	cin >> x;

	switch (i) {
	case 1:
		cout << x << " Кл" << " = " << x * c / 10 << " СГСЭ - ед. заряда";
		break;
	case 2:
		cout << x << " А" << " = " << x * c / 10 << " СГСЭ - ед. силы тока";
		break;
	case 3:
		cout << x << " В" << " = " << x / c * pow (10, 8) << " СГСЭ - ед. потенциала";
		break;
	case 4:
		cout << x << " В/м" << " = " << x / c * pow (10, 6) << " СГСЭ - ед. напряжённости";
		break;
	}
	return EXIT_SUCCESS;
}