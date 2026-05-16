#include <iostream>
using namespace std;

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

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}