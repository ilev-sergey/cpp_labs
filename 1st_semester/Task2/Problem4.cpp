#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

int main4()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите первую последовательность: ";
	string string1;
	cin >> string1;
	int length1 = string1.length();

	cout << "¬ведите вторую последовательность: ";
	string string2;
	cin >> string2;
	int length2 = string2.length();

	vector <vector<int>> matrix(length1 + 1, vector<int>(length2 + 1));

	for (int line = 1; line <= length1; ++line) // input of matrix
	{
		for (int column = 1; column <= length2; ++column)
		{
			cin >> matrix[line][column];
		}
	}

	for (int line = 0; line <= length1; ++line) // output of matrix
	{
		for (int column = 0; column <= length2; ++column)
		{
			cout << matrix[line][column] << " ";
		}
		cout << endl;
	}
	
	for (int line = 0; line <= length1; ++line) // filling of matrix
	{
		for (int column = 0; column <= length2; ++column)
		{
			if (string1[line] == string2[column])
			{
				matrix[line][column] = matrix[line - 1][column - 1];
			}
			else
			{
				matrix[line][column] = max(matrix[line - 1][column], matrix[line][column - 1]);
			}
		}
		cout << endl;
	}
			
	string LCS = "";
	int x_i = length1 - 1, y_i = length2 - 1;
	while ((x_i >= 0) && (y_i >= 0))
	{
		if (string1[x_i] == string2[y_i])
		{
			LCS += string1[x_i];
			x_i, y_i = x_i - 1, y_i - 1;
		}
		else
		{
			if (matrix[x_i - 1][y_i] > matrix[x_i][y_i - 1])
			{
				x_i -= 1;
			}
			else
			{
				y_i -= 1;
			}
		}
	}
	return EXIT_SUCCESS;
}