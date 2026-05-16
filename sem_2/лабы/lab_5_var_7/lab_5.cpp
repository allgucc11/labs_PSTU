#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swapRowCol(int a[100][100], int n, int row, int col)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[row][i];
        a[row][i] = a[i][col];
        a[i][col] = temp;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int a[100][100];

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][0] == a[0][j])
            {
                swapRowCol(a, n, i, j);
            }
        }
    }

    cout << "\nПосле обмена:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}