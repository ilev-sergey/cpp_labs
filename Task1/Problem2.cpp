#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	long long c = 29979245800;

	int i;
	cout << "�������� ������� ���������:" << endl;
	cout << "1 - ��" << endl << "2 - �" << endl << "3 - �" << endl << "4 - �/�" << endl;
	cin >> i;

	double x;
	cout << "������� �������� ��������: ";
	cin >> x;

	switch (i) {
	case 1:
		cout << x << " ��" << " = " << x * c / 10 << " ���� - ��. ������";
		break;
	case 2:
		cout << x << " �" << " = " << x * c / 10 << " ���� - ��. ���� ����";
		break;
	case 3:
		cout << x << " �" << " = " << x / c * pow (10, 8) << " ���� - ��. ����������";
		break;
	case 4:
		cout << x << " �/�" << " = " << x / c * pow (10, 6) << " ���� - ��. ������������";
		break;
	}
	return EXIT_SUCCESS;
}