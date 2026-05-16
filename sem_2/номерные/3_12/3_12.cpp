#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Введите рамер матрицы:";
	cin >> n;

	int a[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Введите число номер " << j << " столбца номер " << i << ":";
			cin >> a[i][j];
		}
	}

	cout << "Изначальная матрица: " << endl;
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
		for (int j = 0; j < n; j++)
		{
			if (i + j == n - 1)
			{
				a[i][j] = 0;
			}
		}
	}

	cout << "Полученная матрица:" << endl;
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