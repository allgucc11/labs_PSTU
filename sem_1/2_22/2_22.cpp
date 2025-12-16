#include <iostream>
#include <cmath>
using namespace std; 
int main()
{
	int N, k;
	float max = 0;
	cout << "введите N: ";
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		float a = sin(i + i / N);
		if (a > max)
		{
			max = a;
			k = i;
		}
	}
	cout << "max = " << max << "; i = " << k << std::endl;
	return 0;