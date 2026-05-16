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

    int p;
    cout << "Введите число, на которое хотите сдвинуть массив влево:";
    cin >> p;
    p = p%n;

    for (int j = 0; j < p; j++)
    {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
    }
    cout << "Получившийся массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    
    cout << endl;
    return 0;
}