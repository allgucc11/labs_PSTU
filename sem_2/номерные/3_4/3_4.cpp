#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите размер массива: ";
	cin >> n;

	int a[100];
	for (int i = 0; i < n - 1; i++)
	{
		cout << "Введите число номер " << i + 1 << ":";
		cin >> a[i];
	}

	cout << "Массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	bool p = true;

	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i+1])
		{
			p = false;
			break;
		}
	}
	if (p == true)
	{
		cout << "Массив упорядочен по возростанию.";
	}
	else
	{
		cout << "Массив не упорядочен по возростанию.";
	}

	cout << endl;
	return 0;
}