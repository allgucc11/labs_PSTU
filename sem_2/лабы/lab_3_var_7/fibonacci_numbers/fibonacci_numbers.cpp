#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите количество чисел Фибоначчи: ";
    cin >> n;

    int a = 0;
    int b = 1;
    int c;

    cout << "Числа Фибоначчи:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a << " ";

        c = a + b;
        a = b;
        b = c;
    }

    cout << endl;

    return 0;
}