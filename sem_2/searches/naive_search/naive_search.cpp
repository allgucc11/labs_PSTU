#include <iostream>
#include <cstring>
using namespace std;

int naiveSearch(char s[], char p[])
{
    int n = strlen(s);
    int m = strlen(p);

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        while (j < m && s[i + j] == p[j])
        {
            j++;
        }

        if (j == m)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char s[256];
    char p[100];

    cout << "Введите строку: ";
    cin.getline(s, 256);

    cout << "Введите подстроку для поиска: ";
    cin.getline(p, 100);

    int k = naiveSearch(s, p);

    if (k != -1)
    {
        cout << "Подстрока найдена" << endl;
        cout << "Индекс начала: " << k << endl;
        cout << "Позиция: " << k + 1 << endl;
    }
    else
    {
        cout << "Подстрока не найдена" << endl;
    }

    return 0;
}