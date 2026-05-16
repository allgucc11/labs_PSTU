#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    char s[256];
    char b[256];

    cout << "Введите строку: ";
    cin.getline(s, 256);

    cout << "Исходная строка: " << s << endl;

    int k = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            b[k] = s[i];
            k++;
        }
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = 0; j < k - 1 - i; j++)
        {
            if (b[j] > b[j + 1])
            {
                char temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    int m = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            s[i] = b[m];
            m++;
        }
    }

    cout << "Преобразованная строка: " << s << endl;

    return 0;
}