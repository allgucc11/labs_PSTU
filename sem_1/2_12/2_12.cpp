#include <iostream>
using namespace std;

int main()
{
	int n, tmp, max, min;
	cout << "¬ведите длинну последовательности" << endl;
	cin >> n;

	cout << "¬ведите первое число";
	cin >> tmp;
	max = tmp;
	min = tmp;

	for (int i = 2; i <= n; i++)
	{
		cout << "¬ведите следующее число";
		cin >> tmp;
		if (tmp > max)
		{
			max = tmp;
		}
		else if (tmp < min)
		{
			min = tmp;
		}
	}
	cout << "—умма минимального и максимального числа:" << min + max << endl;
	return 0;
}