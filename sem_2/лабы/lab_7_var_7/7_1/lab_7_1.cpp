#include <iostream>
using namespace std;

double delenie(int a, int b)
{
    return (double)a / b;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    int b;

    cout << "Введите первое целое число: ";
    cin >> a;

    cout << "Введите второе целое число: ";
    cin >> b;

    if (b != 0)
    {
        cout << "Результат деления целых чисел: " << delenie(a, b) << endl;
    }
    else
    {
        cout << "На ноль делить нельзя" << endl;
    }

    return 0;
}