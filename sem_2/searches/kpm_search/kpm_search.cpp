#include <iostream>
#include <cstring>
using namespace std;

void makeTable(char p[], int table[])
{
    int m = strlen(p);

    table[0] = 0;

    int j = 0;

    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = table[j - 1];
        }

        if (p[i] == p[j])
        {
            j++;
        }

        table[i] = j;
    }
}

int kmpSearch(char s[], char p[])
{
    int n = strlen(s);
    int m = strlen(p);

    int table[100];

    makeTable(p, table);

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
        {
            j = table[j - 1];
        }

        if (s[i] == p[j])
        {
            j++;
        }

        if (j == m)
        {
            return i - m + 1;
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

    int k = kmpSearch(s, p);

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