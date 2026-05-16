#include <iostream>
using namespace std;

void quickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j)
    {
        quickSort(a, left, j);
    }

    if (i < right)
    {
        quickSort(a, i, right);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int a[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Введите число номер " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}