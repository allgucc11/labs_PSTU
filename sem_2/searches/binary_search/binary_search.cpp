#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == x)
        {
            return mid;
        }

        if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
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

    int k = binarySearch(a, n, x);

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