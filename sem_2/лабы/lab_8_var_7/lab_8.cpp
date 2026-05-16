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
    Student s;

    cout << "Введите количество студентов: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Студент номер " << i + 1 << endl;

        inputStudent(s);

        f.write((char*)&s, sizeof(Student));
    }

    f.close();
}

void printFile(char filename[])
{
    ifstream f(filename, ios::binary);

    Student s;
    int i = 1;

    cout << endl;
    cout << "Содержимое файла:" << endl;

    while (f.read((char*)&s, sizeof(Student)))
    {
        cout << endl;
        cout << "Студент номер " << i << endl;
        cout << "Фамилия: " << s.fam << endl;
        cout << "Имя: " << s.name << endl;
        cout << "Отчество: " << s.otch << endl;
        cout << "Адрес: " << s.address << endl;
        cout << "Группа: " << s.group << endl;
        cout << "Рейтинг: " << s.rating << endl;

        i++;
    }

    f.close();
}

void deleteStudents(char filename[], double r)
{
    ifstream f(filename, ios::binary);
    ofstream temp("temp.dat", ios::binary);

    Student s;

    while (f.read((char*)&s, sizeof(Student)))
    {
        if (s.rating >= r)
        {
            temp.write((char*)&s, sizeof(Student));
        }
    }

    f.close();
    temp.close();

    remove(filename);
    rename("temp.dat", filename);
}

void addStudent(char filename[])
{
    ofstream f(filename, ios::binary | ios::app);

    Student s;

    cout << endl;
    cout << "Введите данные студента для добавления:" << endl;

    inputStudent(s);

    f.write((char*)&s, sizeof(Student));

    f.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char filename[] = "students.dat";

    createFile(filename);

    printFile(filename);

    double r;

    cout << endl;
    cout << "Введите рейтинг для удаления: ";
    cin >> r;

    deleteStudents(filename, r);

    cout << endl;
    cout << "После удаления студентов:" << endl;
    printFile(filename);

    addStudent(filename);

    cout << endl;
    cout << "После добавления студента:" << endl;
    printFile(filename);

    return 0;
}