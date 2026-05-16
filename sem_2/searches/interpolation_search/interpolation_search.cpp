#include <iostream>
using namespace std;

int interpolationSearch(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right && x >= a[left] && x <= a[right])
    {
        if (a[left] == a[right])
        {
            if (a[left] == x)
            {
                return left;
            }
            else
            {
                return -1;
            }
        }

        int pos = left + (x - a[left]) * (right - left) / (a[right] - a[left]);

        if (a[pos] == x)
        {
            return pos;
        }

        if (a[pos] < x)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
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

    cout << "Введите отсортированный массив:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int x;
    cout << "Введите число для поиска: ";
    cin >> x;

    int k = interpolationSearch(a, n, x);

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