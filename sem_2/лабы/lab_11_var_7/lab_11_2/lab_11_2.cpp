#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

struct Student
{
    char fam[30];
    char name[30];
    char otch[30];
    char address[100];
    char group[20];
    double rating;
};

struct Node 
{
    Student data;
    Node* prev;
    Node* next;
    Node(const Student& s) : data(s), prev(nullptr), next(nullptr) {}
};

void inputStudent(Student& s) 
{
    cout << "Фамилия: ";  
    cin >> s.fam;
    cout << "Имя: ";    
    cin >> s.name;
    cout << "Отчество: "; 
    cin >> s.otch;
    cin.ignore();
    cout << "Домашний адрес: "; 
    cin.getline(s.address, 100);
    cout << "Группа: ";  
    cin >> s.group;
    cout << "Рейтинг: "; 
    cin >> s.rating;
}

void createFile(char filename[]) 
{
    ofstream f(filename, ios::binary);
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; ++i)
    {
        cout << "\nСтудент номер " << i + 1 << endl;
        Student s;
        inputStudent(s);
        Node* newNode = new Node(s);
        if (!head)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* cur = head;
    while (cur) 
    {
        f.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    f.close();

    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void printFile(char filename[]) 
{
    ifstream f(filename, ios::binary);
    Student s;
    int i = 1;
    cout << "\nСодержимое файла:\n";
    while (f.read((char*)&s, sizeof(Student)))
    {
        cout << "\nСтудент номер " << i++ << endl;
        cout << "Фамилия: " << s.fam << endl;
        cout << "Имя: " << s.name << endl;
        cout << "Отчество: " << s.otch << endl;
        cout << "Адрес: " << s.address << endl;
        cout << "Группа: " << s.group << endl;
        cout << "Рейтинг: " << s.rating << endl;
    }
    f.close();
}

void deleteStudents(char filename[], double r) 
{
    ifstream f(filename, ios::binary);
    Node* head = nullptr;
    Node* tail = nullptr;
    Student s;
    while (f.read((char*)&s, sizeof(Student))) 
    {
        Node* newNode = new Node(s);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    f.close();

    Node* cur = head;
    while (cur)
    {
        Node* nextNode = cur->next;
        if (cur->data.rating < r) 
        {
            if (cur->prev)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                head = cur->next;
            }
            if (cur->next)
            {
                cur->next->prev = cur->prev;
            }
            else
            {
                tail = cur->prev;
            }
            delete cur;
        }
        cur = nextNode;
    }

    ofstream temp("temp.dat", ios::binary);
    cur = head;
    while (cur) 
    {
        temp.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    temp.close();

    remove(filename);
    rename("temp.dat", filename);

    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void addStudent(char filename[])
{
    ifstream f(filename, ios::binary);
    Node* head = nullptr;
    Node* tail = nullptr;
    Student s;
    while (f.read((char*)&s, sizeof(Student))) 
    {
        Node* newNode = new Node(s);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    f.close();

    cout << "\nВведите данные студента для добавления:\n";
    Student newStudent;
    inputStudent(newStudent);
    Node* newNode = new Node(newStudent);
    if (!head)
    {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    ofstream out(filename, ios::binary);
    Node* cur = head;
    while (cur)
    {
        out.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    out.close();

    while (head) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    char filename[] = "students.dat";

    createFile(filename);
    printFile(filename);

    double r;
    cout << "\nВведите рейтинг для удаления: ";
    cin >> r;
    deleteStudents(filename, r);

    cout << "\nПосле удаления студентов:\n";
    printFile(filename);

    addStudent(filename);
    cout << "\nПосле добавления студента:\n";
    printFile(filename);

    return 0;
}