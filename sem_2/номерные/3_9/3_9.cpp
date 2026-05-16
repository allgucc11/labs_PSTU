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
    
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            a[k] = a[i];
            k++;
        }
    }

    cout << "Новый массив: ";
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}