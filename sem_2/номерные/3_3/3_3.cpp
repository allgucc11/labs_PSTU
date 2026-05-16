#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите размер массива: ";
	cin >> n;

	int a[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите число номер " << n + 1 << ":";
		cin >> a[i];
	}

	cout << "Массив: ";

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int max = a[0];
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (max == a[i])
		{
			count++;
		}
	}
	cout << "Максимальный элемент: " << max << endl;
	cout << "Количество таких элементов: " << count << endl;

	return 0;
}