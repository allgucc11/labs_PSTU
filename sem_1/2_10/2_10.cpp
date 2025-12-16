#include <iostream>
using namespace std;

int main()
{
	int N, a, max = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		if (a > max)
		{
			max = a;
		}
	}
	cout << "max: " << max;
	return 0;
}