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
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	return 0;