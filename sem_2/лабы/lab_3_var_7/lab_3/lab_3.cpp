#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double eps = 0.0001;
    double sum = 0;
    double an = 1;
    int n = 1;

    while (abs(an) >= eps)
    {
        an = (1.0 - n) / ((3 * n + 2) * (3 * n + 1));
        sum += an;
        n++;
    }

    cout << "Сумма ряда = " << sum << endl;
    cout << "Количество членов = " << n - 1 << endl;

    return 0;
}