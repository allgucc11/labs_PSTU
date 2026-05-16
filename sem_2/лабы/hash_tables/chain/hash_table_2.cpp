#include <iostream>
#include <string>

using namespace std;

const int SIZE = 10;

struct Node
{
    string fio;
    string phone;
    string address;

    Node* next;
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

void insert(Node* table[], string fio, string phone, string address)
{
    int index = hashFunction(fio);

    Node* newNode = new Node;

    newNode->fio = fio;
    newNode->phone = phone;
    newNode->address = address;
    newNode->next = nullptr;

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        Node* temp = table[index];

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void search(Node* table[], string fio)
{
    int index = hashFunction(fio);

    Node* temp = table[index];

    while (temp != nullptr)
    {
        if (temp->fio == fio)
        {
            cout << "\nЭлемент найден:\n";
            cout << "ФИО: " << temp->fio << endl;
            cout << "Телефон: " << temp->phone << endl;
            cout << "Адрес: " << temp->address << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nЭлемент не найден.\n";
}

void show(Node* table[])
{
    cout << "\nХеш-таблица:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << ": ";

        Node* temp = table[i];

        while (temp != nullptr)
        {
            cout << "[" << temp->fio << "] -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    Node* table[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        table[i] = nullptr;
    }

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