#include <iostream>
#include <cstring>
using namespace std;

void makeTable(char p[], int table[])
{
    int m = strlen(p);

    for (int i = 0; i < 256; i++)
    {
        table[i] = m;
    }

    for (int i = 0; i < m - 1; i++)
    {
        table[(unsigned char)p[i]] = m - 1 - i;
    }
}

int bmSearch(char s[], char p[])
{
    int n = strlen(s);
    int m = strlen(p);

    int table[256];

    makeTable(p, table);

    int i = m - 1;

    while (i < n)
    {
        int j = m - 1;
        int k = i;

        while (j >= 0 && s[k] == p[j])
        {
            k--;
            j--;
        }

        if (j < 0)
        {
            return k + 1;
        }

        i = i + table[(unsigned char)s[i]];
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

    int k = bmSearch(s, p);

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