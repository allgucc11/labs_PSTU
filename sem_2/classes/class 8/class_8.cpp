#include <iostream>
#include <string>
#include <cstdlib>
#include <clocale>
using namespace std;

const int evNothing = 0;
const int evMessage = 100;

const int cmMake = 1;
const int cmAdd = 2;
const int cmDel = 3;
const int cmShow = 4;
const int cmGet = 5;
const int cmQuit = 6;

struct TEvent {
    int what;
    int command;
    int a;
};

class Object {
protected:
    string name;
    int age;

public:
    virtual ~Object() {}
    virtual void Show() = 0;
    virtual void Input() = 0;
    virtual void HandleEvent(const TEvent& e) = 0;
};

class Person : public Object {
public:
    Person() : Object() { name = ""; age = 0; }

    void Show() override {
        cout << "Имя: " << name << ", Возраст: " << age << " лет" << endl;
    }

    void Input() override {
        cout << " Имя: "; cin >> name;
        cout << " Возраст: "; cin >> age;
    }

    void HandleEvent(const TEvent& e) override {
        if (e.what == evMessage && e.command == cmGet) {
            cout << ">> Имя: " << name << endl;
        }
    }
};

class Employee : public Person {
    float salary;
    string position;

public:
    void Show() override {
        cout << "Имя: " << name << ", Возраст: " << age << " лет, "
            << "Должность: " << position << ", Зарплата: " << salary << " руб." << endl;
    }

    void Input() override {
        cout << " Имя: "; cin >> name;
        cout << " Возраст: "; cin >> age;
        cout << " Должность: "; cin >> position;
        cout << " Зарплата: "; cin >> salary;
    }

    void HandleEvent(const TEvent& e) override {
        if (e.what == evMessage && e.command == cmGet) {
            cout << ">>> Имя сотрудника: " << name << endl;
        }
    }
};

class Vector {
protected:
    Object** beg;
    int size;
    int cur;
public:
    Vector() : beg(nullptr), size(0), cur(0) {}

    ~Vector() {
        for (int i = 0; i < cur; i++) delete beg[i];
        delete[] beg;
    }

    void Create(int n) {
        if (beg) {
            for (int i = 0; i < cur; i++) delete beg[i];
            delete[] beg;
        }
        size = n;
        cur = 0;
        beg = new Object * [size];
        cout << "[Группа создана на " << size << " мест]" << endl;
    }

    void Add() {
        if (cur >= size) {
            cout << "[Ошибка] Группа заполнена!" << endl;
            return;
        }
        cout << " Выберите тип: " << endl;
        cout << " 1 - Человек (Person)" << endl;
        cout << " 2 - Сотрудник (Employee)" << endl;
        cout << " > ";
        int t; cin >> t;
        Object* p = (t == 1) ? new Person() : new Employee();
        p->Input();
        beg[cur++] = p;
        cout << "[Элемент добавлен. Всего: " << cur << "/" << size << "]" << endl;
    }

    void Show() {
        if (cur == 0) {
            cout << "[Группа пуста]" << endl;
            return;
        }
        cout << "========== Содержимое группы ==========" << endl;
        for (int i = 0; i < cur; i++) {
            cout << i + 1 << ". ";
            beg[i]->Show();
        }
        cout << "=======================================" << endl;
    }

    void Del() {
        if (cur > 0) {
            delete beg[--cur];
            cout << "[Элемент удален. Осталось: " << cur << "/" << size << "]" << endl;
        }
        else {
            cout << "[Ошибка] Группа пуста, нечего удалять!" << endl;
        }
    }

    int Size() { return cur; }

    void HandleEvent(const TEvent& e) {
        if (e.what != evMessage) return;
        if (e.command == cmGet && e.a >= 1 && e.a <= cur) {
            cout << "=== Вывод имени для элемента #" << e.a << " ===" << endl;
            beg[e.a - 1]->HandleEvent(e);
        }
    }
};

class Dialog : public Vector {
    int EndState;

    void ClearEvent(TEvent& e) { e.what = evNothing; }
    void EndExec() { EndState = 1; }
    int Valid() { return EndState; }

public:
    Dialog() : EndState(0) {
        cout << "\n========== ПРОГРАММА УПРАВЛЯЕМАЯ СОБЫТИЯМИ ==========" << endl;
        cout << "Команды:" << endl;
        cout << "  mN - создать группу на N мест (например: m5)" << endl;
        cout << "   + - добавить элемент в группу" << endl;
        cout << "   - - удалить последний элемент из группы" << endl;
        cout << "   s - показать всю группу" << endl;
        cout << "  zN - вывести имя элемента с номером N (например: z2)" << endl;
        cout << "   q - выход из программы" << endl;
        cout << "========================================================" << endl;
    }

    void GetEvent(TEvent& e) {
        string s;
        cout << "\n> "; cin >> s;
        char c = s[0];
        e.what = evMessage;
        switch (c) {
        case 'm':
            e.command = cmMake;
            e.a = (s.length() > 1) ? atoi(s.substr(1).c_str()) : 0;
            cout << "[Команда: СОЗДАТЬ ГРУППУ]" << endl;
            break;
        case '+':
            e.command = cmAdd;
            cout << "[Команда: ДОБАВИТЬ ЭЛЕМЕНТ]" << endl;
            break;
        case '-':
            e.command = cmDel;
            cout << "[Команда: УДАЛИТЬ ЭЛЕМЕНТ]" << endl;
            break;
        case 's':
            e.command = cmShow;
            cout << "[Команда: ПОКАЗАТЬ ГРУППУ]" << endl;
            break;
        case 'z':
            e.command = cmGet;
            e.a = (s.length() > 1) ? atoi(s.substr(1).c_str()) : 0;
            cout << "[Команда: ВЫВОД ИМЕНИ ПО НОМЕРУ " << e.a << "]" << endl;
            break;
        case 'q':
            e.command = cmQuit;
            cout << "[Команда: ВЫХОД]" << endl;
            break;
        default:
            e.what = evNothing;
            cout << "[Неизвестная команда!] Попробуйте: mN, +, -, s, zN, q" << endl;
            break;
        }
    }

    void HandleEvent(TEvent& e) {
        if (e.what != evMessage) return;
        switch (e.command) {
        case cmMake:
            if (e.a > 0) Create(e.a);
            else cout << "[Ошибка] Укажите размер: m5 (создать на 5 мест)" << endl;
            ClearEvent(e);
            break;
        case cmAdd:
            Add();
            ClearEvent(e);
            break;
        case cmDel:
            Del();
            ClearEvent(e);
            break;
        case cmShow:
            Show();
            ClearEvent(e);
            break;
        case cmGet:
            Vector::HandleEvent(e);
            ClearEvent(e);
            break;
        case cmQuit:
            EndExec();
            ClearEvent(e);
            break;
        }
    }

    void Execute() {
        TEvent e;
        do {
            EndState = 0;
            GetEvent(e);
            if (e.what != evNothing) HandleEvent(e);
        } while (!Valid());
        cout << "\nПрограмма завершена. До свидания!" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Dialog d;
    d.Execute();
    return 0;
}