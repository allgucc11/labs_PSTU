#include <iostream>
using namespace std;

int main()
{
	int N, r = 0;
	cin >> N;
	while (N > 0)
	{
		r = r * 10 + N % 10;
		N /= 10;
	}
	cout << r;
	return 0;
}