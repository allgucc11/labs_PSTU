#include <iostream>
#include <fstream>
using namespace std;

void printFile(char name[])
{
    ifstream f(name);
    char s[256];

    cout << "Файл " << name << ":" << endl;

    while (f.getline(s, 256))
    {
        cout << s << endl;
    }

    f.close();
}

void copyFile(char f1[], char f2[])
{
    ifstream in(f1);
    ofstream out(f2);
    char s[256];

    while (in.getline(s, 256))
    {
        if (s[0] != 'A' && s[0] != 'a')
        {
            out << s << endl;
        }
    }

    in.close();
    out.close();
}

int countFirstWord(char name[])
{
    ifstream f(name);
    char s[256];
    int k = 0;

    if (f.getline(s, 256))
    {
        for (int i = 0; s[i] != '\0' && s[i] != ' '; i++)
        {
            k++;
        }
    }

    f.close();
    return k;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char f1[] = "F1.txt";
    char f2[] = "F2.txt";

    cout << "Исходный файл" << endl;
    printFile(f1);

    copyFile(f1, f2);

    cout << endl;
    cout << "Полученный файл" << endl;
    printFile(f2);

    cout << endl;
    cout << "Количество символов в первом слове F2 = " << countFirstWord(f2) << endl;

    return 0;
}