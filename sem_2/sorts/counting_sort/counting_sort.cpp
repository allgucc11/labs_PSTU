#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    int a[100];

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы массива от 0 до 99:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count[100];

    for (int i = 0; i < 100; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    int k = 0;

    for (int i = 0; i < 100; i++)
    {
        while (count[i] > 0)
        {
            a[k] = i;
            k++;
            count[i]--;
        }
    }

    cout << "Отсортированный массив:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}