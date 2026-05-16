#include <iostream>
using namespace std;

void delenie(double a, double b, double c, double d)
{
    double x;
    double y;
    double z;

    z = c * c + d * d;

    x = (a * c + b * d) / z;
    y = (b * c - a * d) / z;

    cout << "Результат деления комплексных чисел: ";

    if (y >= 0)
    {
        cout << x << " + " << y << "i" << endl;
    }
    else
    {
        cout << x << " - " << -y << "i" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double x1;
    double y1;
    double x2;
    double y2;

    cout << "Введите действительную часть первого комплексного числа: ";
    cin >> x1;

    cout << "Введите мнимую часть первого комплексного числа: ";
    cin >> y1;

    cout << "Введите действительную часть второго комплексного числа: ";
    cin >> x2;

    cout << "Введите мнимую часть второго комплексного числа: ";
    cin >> y2;

    if (x2 != 0 || y2 != 0)
    {
        delenie(x1, y1, x2, y2);
    }
    else
    {
        cout << "На нулевое комплексное число делить нельзя" << endl;
    }

    return 0;
}