#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;

struct Client
{
    string fio;
    string phone;
    string address;
    bool occupied = false;
};

int hashFunction(string fio)
{
    int sum = 0;

    for (int i = 0; i < fio.length(); i++)
    {
        sum += fio[i];
    }

    return sum % SIZE;
}

void insert(Client table[], string fio, string phone, string address)
{
    int index = hashFunction(fio);

    while (table[index].occupied)
    {
        index = (index + 1) % SIZE;
    }

    table[index].fio = fio;
    table[index].phone = phone;
    table[index].address = address;
    table[index].occupied = true;
}

void search(Client table[], string fio)
{
    int index = hashFunction(fio);
    int start = index;

    while (table[index].occupied)
    {
        if (table[index].fio == fio)
        {
            cout << "\nЭлемент найден:\n";
            cout << "ФИО: " << table[index].fio << endl;
            cout << "Телефон: " << table[index].phone << endl;
            cout << "Адрес: " << table[index].address << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
        {
            break;
        }
    }

    cout << "\nЭлемент не найден.\n";
}

void show(Client table[])
{
    cout << "\nХеш-таблица:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << ": ";

        if (table[i].occupied)
        {
            cout << table[i].fio;
        }
        else
        {
            cout << "Пусто";
        }

        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    Client table[SIZE];

    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        string fio;
        string phone;
        string address;

        cout << "\nВведите ФИО: ";
        getline(cin, fio);

        cout << "Введите телефон: ";
        getline(cin, phone);

        cout << "Введите адрес: ";
        getline(cin, address);

        insert(table, fio, phone, address);
    }

    show(table);

    string key;

    cout << "\nВведите ФИО для поиска: ";
    getline(cin, key);

    search(table, key);

    return 0;
}