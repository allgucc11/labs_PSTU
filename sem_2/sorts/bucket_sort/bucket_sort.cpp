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

    int bucket[10][100];
    int count[10];

    for (int i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int k = a[i] / 10;

        bucket[k][count[k]] = a[i];
        count[k]++;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i] - 1; j++)
        {
            for (int k = 0; k < count[i] - 1 - j; k++)
            {
                if (bucket[i][k] > bucket[i][k + 1])
                {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    int t = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            a[t] = bucket[i][j];
            t++;
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