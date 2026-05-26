#include <iostream>
#include <vector>
#include <queue>
#include <clocale>
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

    Money& operator=(const Money& m) {
        if (this != &m) {
            rubles = m.rubles;
            kopecks = m.kopecks;
        }
        return *this;
    }

    Money operator+(const Money& m) const {
        return Money(rubles + m.rubles, kopecks + m.kopecks);
    }

    bool operator==(const Money& m) const {
        return rubles == m.rubles && kopecks == m.kopecks;
    }

    bool operator!=(const Money& m) const {
        return !(*this == m);
    }

    bool operator<(const Money& m) const {
        return rubles * 100 + kopecks < m.rubles * 100 + m.kopecks;
    }

    bool operator>(const Money& m) const {
        return rubles * 100 + kopecks > m.rubles * 100 + m.kopecks;
    }

    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};

istream& operator>>(istream& in, Money& m) {
    in >> m.rubles >> m.kopecks;
    m.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Money& m) {
    out << m.rubles << ",";
    if (m.kopecks < 10) out << "0";
    out << m.kopecks;
    return out;
}

template <class T>
void input_vector(vector<T>& v) {
    int n;
    T x;

    cout << "Введите размер контейнера: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> x;
        v.push_back(x);
    }
}

template <class T>
void print_vector(vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <class T>
T find_min(vector<T> v) {
    T min = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] < min) min = v[i];
    }

    return min;
}

template <class T>
T find_max(vector<T> v) {
    T max = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (v[i] > max) max = v[i];
    }

    return max;
}

template <class T>
void add_min_end(vector<T>& v) {
    if (v.size() == 0) return;

    T min = find_min(v);
    v.push_back(min);
}

template <class T>
void delete_key(vector<T>& v, T key) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            v.erase(v.begin() + i);
            i--;
        }
    }
}

template <class T>
void add_min_max(vector<T>& v) {
    if (v.size() == 0) return;

    T min = find_min(v);
    T max = find_max(v);
    T s = min + max;

    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] + s;
    }
}

template <class T>
class Vector {
private:
    vector<T> data;

public:
    Vector() {}
    Vector(int n) {
        T x;
        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            cin >> x;
            data.push_back(x);
        }
    }

    ~Vector() {}

    void Show() {
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    T Min() {
        T min = data[0];

        for (int i = 1; i < data.size(); i++) {
            if (data[i] < min) min = data[i];
        }

        return min;
    }

    T Max() {
        T max = data[0];

        for (int i = 1; i < data.size(); i++) {
            if (data[i] > max) max = data[i];
        }

        return max;
    }

    void AddMinEnd() {
        if (data.size() == 0) return;

        T min = Min();
        data.push_back(min);
    }

    void DeleteKey(T key) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == key) {
                data.erase(data.begin() + i);
                i--;
            }
        }
    }

    void AddMinMax() {
        if (data.size() == 0) return;

        T s = Min() + Max();

        for (int i = 0; i < data.size(); i++) {
            data[i] = data[i] + s;
        }
    }
};

template <class T>
void input_queue(queue<T>& q) {
    int n;
    T x;

    cout << "Введите размер очереди: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> x;
        q.push(x);
    }
}

template <class T>
void print_queue(queue<T> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

template <class T>
void delete_key_queue(queue<T>& q, T key) {
    queue<T> temp;

    while (!q.empty()) {
        if (q.front() != key) {
            temp.push(q.front());
        }
        q.pop();
    }

    q = temp;
}

template <class T>
class QueueVector {
private:
    queue<T> data;

public:
    QueueVector() {}
    ~QueueVector() {}

    void Input() {
        int n;
        T x;

        cout << "Введите размер очереди: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            cin >> x;
            data.push(x);
        }
    }

    void Show() {
        queue<T> temp = data;

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

    T Min() {
        queue<T> temp = data;
        T min = temp.front();
        temp.pop();

        while (!temp.empty()) {
            if (temp.front() < min) min = temp.front();
            temp.pop();
        }

        return min;
    }

    T Max() {
        queue<T> temp = data;
        T max = temp.front();
        temp.pop();

        while (!temp.empty()) {
            if (temp.front() > max) max = temp.front();
            temp.pop();
        }

        return max;
    }

    void DeleteKey(T key) {
        queue<T> temp;

        while (!data.empty()) {
            if (data.front() != key) {
                temp.push(data.front());
            }
            data.pop();
        }

        data = temp;
    }

    void AddMinMax() {
        if (data.empty()) return;

        T s = Min() + Max();
        queue<T> temp;

        while (!data.empty()) {
            temp.push(data.front() + s);
            data.pop();
        }

        data = temp;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== ЗАДАЧА 1. vector<float> ===" << endl;
    vector<float> v1;
    input_vector(v1);

    cout << "Исходный контейнер: ";
    print_vector(v1);

    add_min_end(v1);
    cout << "После добавления минимального элемента в конец: ";
    print_vector(v1);

    float key1;
    cout << "Введите ключ для удаления: ";
    cin >> key1;
    delete_key(v1, key1);
    cout << "После удаления ключа: ";
    print_vector(v1);

    add_min_max(v1);
    cout << "После добавления суммы min и max к каждому элементу: ";
    print_vector(v1);


    cout << "\n=== ЗАДАЧА 2. vector<Money> ===" << endl;
    vector<Money> v2;
    input_vector(v2);

    cout << "Исходный контейнер: ";
    print_vector(v2);

    add_min_end(v2);
    cout << "После добавления минимального элемента в конец: ";
    print_vector(v2);

    Money key2;
    cout << "Введите ключ для удаления (рубли копейки): ";
    cin >> key2;
    delete_key(v2, key2);
    cout << "После удаления ключа: ";
    print_vector(v2);

    add_min_max(v2);
    cout << "После добавления суммы min и max к каждому элементу: ";
    print_vector(v2);


    cout << "\n=== ЗАДАЧА 3. Параметризированный класс Vector ===" << endl;
    int n;
    cout << "Введите размер Vector<float>: ";
    cin >> n;

    Vector<float> v3(n);

    cout << "Исходный контейнер: ";
    v3.Show();

    v3.AddMinEnd();
    cout << "После добавления минимального элемента в конец: ";
    v3.Show();

    float key3;
    cout << "Введите ключ для удаления: ";
    cin >> key3;
    v3.DeleteKey(key3);
    cout << "После удаления ключа: ";
    v3.Show();

    v3.AddMinMax();
    cout << "После добавления суммы min и max к каждому элементу: ";
    v3.Show();


    cout << "\n=== ЗАДАЧА 4. queue<Money> ===" << endl;
    queue<Money> q;
    input_queue(q);

    cout << "Исходная очередь: ";
    print_queue(q);

    Money key4;
    cout << "Введите ключ для удаления (рубли копейки): ";
    cin >> key4;

    delete_key_queue(q, key4);
    cout << "После удаления ключа: ";
    print_queue(q);


    cout << "\n=== ЗАДАЧА 5. Параметризированный класс с queue ===" << endl;
    QueueVector<float> qv;

    qv.Input();

    cout << "Исходная очередь: ";
    qv.Show();

    float key5;
    cout << "Введите ключ для удаления: ";
    cin >> key5;
    qv.DeleteKey(key5);

    cout << "После удаления ключа: ";
    qv.Show();

    qv.AddMinMax();
    cout << "После добавления суммы min и max к каждому элементу: ";
    qv.Show();

    return 0;
}