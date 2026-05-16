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

struct QueueNode
{
    Student data;
    QueueNode* next;
    QueueNode(const Student& s) : data(s), next(nullptr) {}
};

struct Queue 
{
    QueueNode* front;
    QueueNode* rear;
    Queue() : front(nullptr), rear(nullptr) {}
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

    Queue q;
    for (int i = 0; i < n; ++i) 
    {
        cout << "\nСтудент номер " << i + 1 << endl;
        Student s;
        inputStudent(s);
        QueueNode* newNode = new QueueNode(s);
        if (!q.front)
        {
            q.front = q.rear = newNode;
        }
        else 
        {
            q.rear->next = newNode;
            q.rear = newNode;
        }
    }

    QueueNode* cur = q.front;
    while (cur) 
    {
        f.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    f.close();

    while (q.front)
    {
        QueueNode* temp = q.front;
        q.front = q.front->next;
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
    Queue q;
    Student s;
    while (f.read((char*)&s, sizeof(Student)))
    {
        QueueNode* newNode = new QueueNode(s);
        if (!q.front)
        {
            q.front = q.rear = newNode;
        }
        else
        {
            q.rear->next = newNode;
            q.rear = newNode;
        }
    }
    f.close();

    Queue newQ;
    QueueNode* cur = q.front;
    while (cur) 
    {
        if (cur->data.rating >= r) 
        {
            QueueNode* newNode = new QueueNode(cur->data);
            if (!newQ.front)
            {
                newQ.front = newQ.rear = newNode;
            }
            else 
            {
                newQ.rear->next = newNode;
                newQ.rear = newNode;
            }
        }
        cur = cur->next;
    }

    ofstream temp("temp.dat", ios::binary);
    cur = newQ.front;
    while (cur)
    {
        temp.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    temp.close();

    remove(filename);
    rename("temp.dat", filename);

    while (q.front) 
    {
        QueueNode* t = q.front;
        q.front = q.front->next;
        delete t;
    }
    while (newQ.front) 
    {
        QueueNode* t = newQ.front;
        newQ.front = newQ.front->next;
        delete t;
    }
}

void addStudent(char filename[]) 
{
    ifstream f(filename, ios::binary);
    Queue q;
    Student s;
    while (f.read((char*)&s, sizeof(Student))) 
    {
        QueueNode* newNode = new QueueNode(s);
        if (!q.front)
        {
            q.front = q.rear = newNode;
        }
        else
        {
            q.rear->next = newNode;
            q.rear = newNode;
        }
    }
    f.close();

    cout << "\nВведите данные студента для добавления:\n";
    Student newStudent;
    inputStudent(newStudent);
    QueueNode* newNode = new QueueNode(newStudent);
    if (!q.front)
    {
        q.front = q.rear = newNode;
    }
    else
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }

    ofstream out(filename, ios::binary);
    QueueNode* cur = q.front;
    while (cur)
    {
        out.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    out.close();

    while (q.front) 
    {
        QueueNode* t = q.front;
        q.front = q.front->next;
        delete t;
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