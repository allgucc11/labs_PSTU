#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите размер матрицы";
	cin >> n;

	int a[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Введите число номер " << j + 1 << "столбца номер " << i + 1;
			cin >> a[i][j];
		}
	}

	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}

	cout << "Транспонированная матрица:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}