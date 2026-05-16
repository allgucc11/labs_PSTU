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

	int k;
	cout << "Введите номер строки для сортировки :";
	cin >> k;
	k--;

	for (int j = 0; j < n; j++)
	{
		for (int p = j + 1; p < n; p++)
		{
			if (a[k][j] > a[k][p])
			{
				for (int i = 0; i < n; i++)
				{
					int temp = a[i][j];
					a[i][j] = a[i][p];
					a[i][p] = temp;
				}
			}
		}
	}

	cout << "Получившаяся матрица:" << endl;
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