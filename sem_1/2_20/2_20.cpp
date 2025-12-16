#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	float S;
	bool t = 0;
	cout << "введите N: ";
	cin >> N;
	cout << "введите S: ";
	cin >> S;
	for (int i = 1; i <= N; i++)
	{
		float a = sin(i + i / N);
		if (a == S)
		{
			t = 1;
		}
	}
	if (t == 1)
	{
		cout << "да";
	}
	else
	{
		cout << "нет";
	}
	cout << endl;
	return 0;
}