#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N <= 2)
	{
		cout << "error";
	}
	else
	{
		for (int i = N - 1; i >= 0; i--)
		{
			for (int x = 1; x < i - N; x++)
			{
				cout << " ";
			}
			for (int j = 0; j <= 0; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	return 0;
}