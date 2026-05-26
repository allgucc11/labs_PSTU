#include <iostream>
#include <string>
#include <clocale>
using namespace std;

const int MAX_SIZE = 30;

class Error {
public:
    virtual void what() {}
};

class IndexError : public Error {
protected:
    string msg = "Ошибка индекса!\n";
public:
    void what() { cout << msg; }
};

class SizeError : public Error {
protected:
    string msg = "Ошибка размера!\n";
public:
    void what() { cout << msg; }
};

class IndexOutOfBounds : public IndexError {
public:
    IndexOutOfBounds() { msg = "Индекс вне диапазона!\n"; }
};

class MaxSize : public SizeError {
public:
    MaxSize() { msg = "Превышен максимальный размер!\n"; }
};

class EmptySet : public SizeError {
public:
    EmptySet() { msg = "Множество пусто!\n"; }
};

class Set {
    int* data;
    int size;
public:
    Set() : size(0) {
        data = new int[MAX_SIZE];
    }

    Set(int n) : size(0) {
        if (n > MAX_SIZE) throw MaxSize();
        data = new int[MAX_SIZE];
    }

    ~Set() {
        delete[] data;
    }

    int find(int e) {
        for (int i = 0; i < size; i++) {
            if (data[i] == e) return i;
        }
        return -1;
    }

    void add(int e) {
        if (find(e) != -1) {
            cout << "Элемент " << e << " уже есть!\n";
            return;
        }
        if (size >= MAX_SIZE) throw MaxSize();
        data[size++] = e;
        cout << "Добавлен " << e << endl;
    }

    void del(int e) {
        int p = find(e);
        if (p == -1) {
            cout << "Элемент " << e << " не найден\n";
            return;
        }
        for (int i = p; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
        cout << "Удален " << e << endl;
    }

    void show() {
        if (size == 0) {
            cout << "{}\n";
            return;
        }
        cout << "{";
        for (int i = 0; i < size; i++)
            cout << " " << data[i];
        cout << " }\n";
    }

    int getSize() { return size; }

    int operator[](int i) {
        if (i < 0 || i >= size) throw IndexOutOfBounds();
        return data[i];
    }

    int operator()() { return size; }

    Set operator*(Set& other) {
        Set res;
        for (int i = 0; i < size; i++) {
            if (other.find(data[i]) != -1) {
                if (res.find(data[i]) == -1) {
                    res.data[res.size++] = data[i];
                }
            }
        }
        return res;
    }

    Set operator--() {
        if (size == 0) throw EmptySet();
        size--;
        cout << "Удален последний элемент\n";
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Set A, B;
    string cmd;

    cout << "\n=== МНОЖЕСТВО (макс.30) ===\n";
    cout << "mN - создать на N мест\n";
    cout << "+X - добавить X\n";
    cout << "-X - удалить X\n";
    cout << "-- - удалить последний\n";
    cout << "s - показать\n";
    cout << "i N - элемент по индексу\n";
    cout << "p - размер\n";
    cout << "* - пересечение\n";
    cout << "q - выход\n";

    while (true) {
        cout << "\n> ";
        cin >> cmd;

        try {
            if (cmd == "q") {
                cout << "До свидания!\n";
                break;
            }
            else if (cmd[0] == 'm') {
                int n = stoi(cmd.substr(1));
                A = Set(n);
                cout << "Создано на " << n << " мест\n";
            }
            else if (cmd[0] == '+') {
                int x = stoi(cmd.substr(1));
                A.add(x);
            }
            else if (cmd[0] == '-') {
                if (cmd.length() > 1 && cmd[1] == '-') {
                    --A;
                }
                else {
                    int x = stoi(cmd.substr(1));
                    A.del(x);
                }
            }
            else if (cmd == "s") {
                cout << "Множество: ";
                A.show();
            }
            else if (cmd[0] == 'i') {
                int i = stoi(cmd.substr(1));
                cout << "A[" << i << "] = " << A[i] << endl;
            }
            else if (cmd == "p") {
                cout << "Размер: " << A() << endl;
            }
            else if (cmd == "*") {
                cout << "Введите элементы второго множества (0 - конец):\n";
                int x;
                B = Set();
                cout << "> ";
                while (cin >> x && x != 0) {
                    B.add(x);
                }
                Set C = A * B;
                cout << "A: "; A.show();
                cout << "B: "; B.show();
                cout << "Пересечение: "; C.show();
            }
            else {
                cout << "Неизвестная команда. Команды: mN, +X, -X, --, s, iN, p, *, q\n";
            }
        }
        catch (IndexOutOfBounds& e) {
            e.what();
        }
        catch (MaxSize& e) {
            e.what();
        }
        catch (EmptySet& e) {
            e.what();
        }
        catch (...) {
            cout << "Неизвестная ошибка!\n";
        }
    }

    return 0;
}