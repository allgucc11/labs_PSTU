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

struct StackNode 
{
    Student data;
    StackNode* next;
    StackNode(const Student& s) : data(s), next(nullptr) {}
};

struct Stack
{
    StackNode* top;
    Stack() : top(nullptr) {}
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

    Stack st;
    Stack tempStack;
    for (int i = 0; i < n; ++i) 
    {
        cout << "\nСтудент номер " << i + 1 << endl;
        Student s;
        inputStudent(s);
        StackNode* newNode = new StackNode(s);
        newNode->next = tempStack.top;
        tempStack.top = newNode;
    }
    while (tempStack.top)
    {
        StackNode* node = tempStack.top;
        tempStack.top = tempStack.top->next;
        node->next = st.top;
        st.top = node;
    }

    StackNode* cur = st.top;
    while (cur) 
    {
        f.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    f.close();

    while (st.top)
    {
        StackNode* t = st.top;
        st.top = st.top->next;
        delete t;
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
    Stack st;
    Student s;
    while (f.read((char*)&s, sizeof(Student)))
    {
        StackNode* newNode = new StackNode(s);
        newNode->next = st.top;
        st.top = newNode;
    }
    f.close();

    Stack newStack;
    StackNode* cur = st.top;
    while (cur)
    {
        if (cur->data.rating >= r)
        {
            StackNode* newNode = new StackNode(cur->data);
            newNode->next = newStack.top;
            newStack.top = newNode;
        }
        cur = cur->next;
    }

    Stack resultStack;
    while (newStack.top) 
    {
        StackNode* node = newStack.top;
        newStack.top = newStack.top->next;
        node->next = resultStack.top;
        resultStack.top = node;
    }

    ofstream temp("temp.dat", ios::binary);
    cur = resultStack.top;
    while (cur)
    {
        temp.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    temp.close();

    remove(filename);
    rename("temp.dat", filename);

    while (st.top)
    {
        StackNode* t = st.top;
        st.top = st.top->next;
        delete t;
    }
    while (newStack.top) 
    {
        StackNode* t = newStack.top;
        newStack.top = newStack.top->next;
        delete t;
    }
    while (resultStack.top) 
    {
        StackNode* t = resultStack.top;
        resultStack.top = resultStack.top->next;
        delete t;
    }
}

void addStudent(char filename[]) 
{
    ifstream f(filename, ios::binary);
    Stack st;
    Student s;
    while (f.read((char*)&s, sizeof(Student))) 
    {
        StackNode* newNode = new StackNode(s);
        newNode->next = st.top;
        st.top = newNode;
    }
    f.close();

    cout << "\nВведите данные студента для добавления:\n";
    Student newStudent;
    inputStudent(newStudent);
    StackNode* newNode = new StackNode(newStudent);
    newNode->next = st.top;
    st.top = newNode;

    Stack reversed;
    while (st.top) 
    {
        StackNode* node = st.top;
        st.top = st.top->next;
        node->next = reversed.top;
        reversed.top = node;
    }

    ofstream out(filename, ios::binary);
    StackNode* cur = reversed.top;
    while (cur) 
    {
        out.write((char*)&cur->data, sizeof(Student));
        cur = cur->next;
    }
    out.close();

    while (reversed.top)
    {
        StackNode* t = reversed.top;
        reversed.top = reversed.top->next;
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