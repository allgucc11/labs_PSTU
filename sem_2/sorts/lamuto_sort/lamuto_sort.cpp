#include <iostream>
using namespace std;

int partition(int a[], int left, int right)
{
    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;

    return i + 1;
}

void quickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int p = partition(a, left, right);

        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
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