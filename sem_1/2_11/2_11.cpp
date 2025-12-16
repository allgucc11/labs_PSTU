#include <iostream>
using namespace std;

int main()
{
	int N, tmp;
	bool plusFirst = false;
	bool minusFirst = false;

	cout << "Введите длину последовательности" << endl;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		if (!plusFirst && !minusFirst)
		{
			if (tmp > 0)
			{
				plusFirst = true;
			}
			else if (tmp < 0)
			{
				minusFirst = true;
			}
		}
		if (plusFirst)
		{
			cout << "Сначала ввели положительное число";
		}
		else if (minusFirst)
		{
			cout << "Сначала ввели отрицательное число";
		}
		else
		{
			cout << "Все элементы были нулевыми";
		}
		cout << endl;
	}
	return 0;
}