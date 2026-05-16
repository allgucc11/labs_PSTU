#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    int a[100];

    cout << "Введите массив:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cout << "Введите число для поиска: ";
    cin >> x;

    int k = linearSearch(a, n, x);

    if (k != -1)
    {
        cout << "Элемент найден. Его индекс: " << k << endl;
        cout << "Номер элемента: " << k + 1 << endl;
    }
    else
    {
        cout << "Элемент не найден" << endl;
    }

    return 0;
}