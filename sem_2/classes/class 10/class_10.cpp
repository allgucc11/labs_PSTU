#include <iostream>
#include <fstream>
#include <clocale>
#include <cstdio>
using namespace std;

class Money {
private:
    long rubles;
    int kopecks;

    void normalize() {
        if (kopecks >= 100) {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
        else if (kopecks < 0) {
            long r = (-kopecks + 99) / 100;
            rubles -= r;
            kopecks += r * 100;
        }

        if (rubles < 0) {
            rubles = 0;
            kopecks = 0;
        }
    }

public:
    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) { normalize(); }
    Money(const Money& m) : rubles(m.rubles), kopecks(m.kopecks) {}
    ~Money() {}

    long getRubles() const { return rubles; }
    int getKopecks() const { return kopecks; }

    void setRubles(long r) {
        rubles = r;
        normalize();
    }

    void setKopecks(int k) {
        kopecks = k;
        normalize();
    }

    Money& operator=(const Money& m) {
        if (this != &m) {
            rubles = m.rubles;
            kopecks = m.kopecks;
        }
        return *this;
    }

    bool operator==(const Money& m) const {
        return rubles == m.rubles && kopecks == m.kopecks;
    }

    bool operator!=(const Money& m) const {
        return !(*this == m);
    }

    double operator/(const Money& m) const {
        double a = rubles + kopecks / 100.0;
        double b = m.rubles + m.kopecks / 100.0;

        if (b == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
            return 0;
        }

        return a / b;
    }

    Money operator*(double k) const {
        double total = (rubles * 100 + kopecks) * k;
        long res = (long)(total + 0.5);
        return Money(res / 100, res % 100);
    }

    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};

istream& operator>>(istream& in, Money& m) {
    char c;

    in >> m.rubles;

    if (in.peek() == ',') {
        in >> c;
        in >> m.kopecks;
    }
    else {
        in >> m.kopecks;
    }

    m.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Money& m) {
    out << m.rubles << ",";
    if (m.kopecks < 10) out << "0";
    out << m.kopecks;
    return out;
}

int make_file(const char* name) {
    ofstream fout(name);
    if (!fout) return -1;

    int n;
    Money m;

    cout << "Введите количество записей: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введите сумму " << i + 1 << " (рубли копейки): ";
        cin >> m;
        fout << m << endl;
    }

    fout.close();
    return n;
}

int print_file(const char* name) {
    ifstream fin(name);
    if (!fin) return -1;

    Money m;
    int k = 0;

    while (fin >> m) {
        cout << k + 1 << ". " << m << endl;
        k++;
    }

    fin.close();
    return k;
}

int delete_not_equal(const char* name, Money key) {
    ifstream fin(name);
    if (!fin) return -1;

    ofstream fout("temp.txt");
    Money m;
    int k = 0;

    while (fin >> m) {
        if (m == key) {
            fout << m << endl;
            k++;
        }
    }

    fin.close();
    fout.close();

    remove(name);
    rename("temp.txt", name);

    return k;
}

int change_equal(const char* name, Money key) {
    ifstream fin(name);
    if (!fin) return -1;

    ofstream fout("temp.txt");
    Money m;
    int k = 0;

    while (fin >> m) {
        if (m == key) {
            m = m * 0.5;
            k++;
        }
        fout << m << endl;
    }

    fin.close();
    fout.close();

    remove(name);
    rename("temp.txt", name);

    return k;
}

int add_begin(const char* name, int count) {
    ifstream fin(name);
    ofstream fout("temp.txt");

    if (!fout) return -1;

    Money m;

    for (int i = 0; i < count; i++) {
        cout << "Введите новую сумму " << i + 1 << " (рубли копейки): ";
        cin >> m;
        fout << m << endl;
    }

    if (fin) {
        while (fin >> m) {
            fout << m << endl;
        }
        fin.close();
    }

    fout.close();

    remove(name);
    rename("temp.txt", name);

    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char name[30];
    int command;
    int k;
    Money key;

    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Создать файл" << endl;
        cout << "2. Показать файл" << endl;
        cout << "3. Удалить все записи, не равные заданному значению" << endl;
        cout << "4. Уменьшить все записи с заданным значением в два раза" << endl;
        cout << "5. Добавить K записей в начало файла" << endl;
        cout << "6. Деление сумм" << endl;
        cout << "7. Умножение суммы на дробное число" << endl;
        cout << "0. Выход" << endl;
        cout << "> ";
        cin >> command;

        switch (command) {
        case 1:
            cout << "Имя файла: ";
            cin >> name;
            k = make_file(name);
            if (k < 0) cout << "Ошибка создания файла!" << endl;
            break;

        case 2:
            cout << "Имя файла: ";
            cin >> name;
            k = print_file(name);
            if (k == 0) cout << "Файл пуст!" << endl;
            if (k < 0) cout << "Ошибка чтения файла!" << endl;
            break;

        case 3:
            cout << "Имя файла: ";
            cin >> name;
            cout << "Введите значение (рубли копейки): ";
            cin >> key;
            k = delete_not_equal(name, key);
            if (k < 0) cout << "Ошибка чтения файла!" << endl;
            else cout << "Осталось записей: " << k << endl;
            break;

        case 4:
            cout << "Имя файла: ";
            cin >> name;
            cout << "Введите значение (рубли копейки): ";
            cin >> key;
            k = change_equal(name, key);
            if (k < 0) cout << "Ошибка чтения файла!" << endl;
            else cout << "Изменено записей: " << k << endl;
            break;

        case 5:
            cout << "Имя файла: ";
            cin >> name;
            cout << "K = ";
            cin >> k;
            k = add_begin(name, k);
            if (k < 0) cout << "Ошибка добавления!" << endl;
            else cout << "Добавлено записей: " << k << endl;
            break;

        case 6: {
            Money a, b;
            cout << "Введите первую сумму (рубли копейки): ";
            cin >> a;
            cout << "Введите вторую сумму (рубли копейки): ";
            cin >> b;
            cout << a << " / " << b << " = " << a / b << endl;
            break;
        }

        case 7: {
            Money a, c;
            double x;
            cout << "Введите сумму (рубли копейки): ";
            cin >> a;
            cout << "Введите дробное число: ";
            cin >> x;
            c = a * x;
            cout << a << " * " << x << " = " << c << endl;
            break;
        }

        case 0:
            cout << "Выход..." << endl;
            break;

        default:
            cout << "Нет такой команды!" << endl;
            break;
        }

    } while (command != 0);

    return 0;
}