#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите размер массива:";
	cin >> n;

	int a[100];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите число номер " << i + 1 << ":";
		cin >> a[i];
	}
	
	cout << "Изначальный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	int p, q;
	cout << "Введите p и q:";
	cin >> p >> q;

	while (p < q)
	{
		int temp = a[p];
		a[p] = a[q];
		a[q] = temp;

		p++;
		q--;
	}

	cout << "Новый массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	return 0;
}