#include <iostream>
using namespace std;

int main()
{
	int n, mx, mn;
	cin >> n;

	int* ptr1 = &mx;
	int* ptr2 = &mn;

	int c;
	cin >> c;

	*ptr1 = c;
	*ptr2 = c;

	for (int i = 2; i <= n; i++)
	{
		cin >> c;
	}
	if (c < *ptr2)
	{
		*ptr2 = c;
	}
	if (c > *ptr1)
	{
		ptr1 = c
	}
	cout << "max:" << mx << endl;
	cout << "min:" << mn << endl;

	return 0;
}