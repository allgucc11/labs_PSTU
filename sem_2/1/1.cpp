#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    const int N = 100;
    int a[N];
    int real_size;

    cout << "Введите реальный размер массива (не больше " << N << "): ";
    cin >> real_size;

    srand(time(NULL));

    cout << "Исходный массив: ";
    for (int i = 0; i < real_size; i++)
    {
        a[i] = rand() % 21 - 10;
        cout << a[i] << " ";
    }
    cout << endl;

    int value_to_delete;
    cout << "Введите значение, которое нужно удалить: ";
    cin >> value_to_delete;

    for (int i = 0; i < real_size; i++)
    {
        if (a[i] == value_to_delete)
        {
            for (int j = i; j < real_size - 1; j++)
            {
                a[j] = a[j + 1];
            }
            real_size--;
            i--;
        }
    }

    cout << "Массив после удаления значения " << value_to_delete << ": ";
    for (int i = 0; i < real_size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < real_size; i++)
    {
        if (a[i] % 2 == 0)
        {
            for (int j = real_size; j > i; j--)
            {
                a[j] = a[j - 1];
            }
            a[i] = 0;

            real_size++;
            i++;
        }
    }

    cout << "Итоговый массив (с нулями перед четными элементами): ";
    for (int i = 0; i < real_size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}