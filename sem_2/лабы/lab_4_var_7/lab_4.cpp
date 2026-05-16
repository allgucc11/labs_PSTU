#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int a[100];

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10 - 5;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int index = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }

    int k;
    cout << "Введите индекс: ";
    cin >> k;

    if (k >= 0 && k < n)
    {
        for (int i = n; i > k + 1; i--)
        {
            a[i] = a[i - 1];
        }
        a[k + 1] = 100;
        n++;
    }
    else
    {
        cout << "Неверный индекс!" << endl;
    }

    cout << "Итоговый массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}