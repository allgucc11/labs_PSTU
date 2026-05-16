#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    int m;

    cout << "Введите количество строк: ";
    cin >> n;

    cout << "Введите количество столбцов: ";
    cin >> m;

    int** a = new int* [n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    cout << "Исходный массив:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int k;

    cout << "Введите номер столбца для удаления: ";
    cin >> k;

    k--;

    if (k >= 0 && k < m)
    {
        int** b = new int* [n];

        for (int i = 0; i < n; i++)
        {
            b[i] = new int[m - 1];
        }

        for (int i = 0; i < n; i++)
        {
            int t = 0;

            for (int j = 0; j < m; j++)
            {
                if (j != k)
                {
                    b[i][t] = a[i][j];
                    t++;
                }
            }
        }

        cout << "Массив после удаления столбца:" << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            delete[] b[i];
        }

        delete[] b;
    }
    else
    {
        cout << "Неверный номер столбца" << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }

    delete[] a;

    return 0;
}