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
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	return 0;
}