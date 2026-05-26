#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

template <class T>
class Vector {
private:
    int size;
    T* data;

public:
    Vector(int s = 0, T k = T()) : size(s) {
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = k;
    }

    Vector(const Vector<T>& a) {
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
    }

    ~Vector() {
        delete[] data;
        data = nullptr;
    }

    Vector<T>& operator=(const Vector<T>& a) {
        if (this == &a) return *this;
        delete[] data;
        size = a.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = a.data[i];
        return *this;
    }

    T& operator[](int index) {
        if (index >= 0 && index < size)
            return data[index];
        else {
            cout << "Ошибка: индекс вне диапазона!" << endl;
            static T dummy = T();
            return dummy;
        }
    }

    int operator()() const {
        return size;
    }

    Vector<T> operator+(const T k) const {
        Vector<T> temp(size);
        for (int i = 0; i < size; i++)
            temp.data[i] = data[i] + k;
        return temp;
    }

    Vector<T> operator*(const T k) const {
        Vector<T> temp(size);
        for (int i = 0; i < size; i++)
            temp.data[i] = data[i] * k;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Vector<T>& a) {
        for (int i = 0; i < a.size; i++)
            out << a.data[i] << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Vector<T>& a) {
        for (int i = 0; i < a.size; i++) {
            in >> a.data[i];
        }
        return in;
    }
};

class Time {
private:
    int min;
    int sec;

    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec %= 60;
        }
        else if (sec < 0) {
            int m = (abs(sec) + 59) / 60;
            min -= m;
            sec += m * 60;
        }
    }

public:
    Time() : min(0), sec(0) {}
    Time(int m, int s) : min(m), sec(s) { normalize(); }
    Time(const Time& t) : min(t.min), sec(t.sec) { normalize(); }

    ~Time() {}

    int getMin() const { return min; }
    int getSec() const { return sec; }

    void setMin(int m) { min = m; }
    void setSec(int s) { sec = s; normalize(); }

    Time& operator=(const Time& t) {
        if (this != &t) {
            min = t.min;
            sec = t.sec;
        }
        return *this;
    }

    Time operator+(const Time& k) const {
        int totalSec = (min * 60 + sec) + (k.min * 60 + k.sec);
        return Time(totalSec / 60, totalSec % 60);
    }

    Time operator+(int s) const {
        int totalSec = min * 60 + sec + s;
        return Time(totalSec / 60, totalSec % 60);
    }

    Time operator*(double factor) const {
        int totalSec = (min * 60 + sec) * factor;
        return Time(totalSec / 60, totalSec % 60);
    }

    friend ostream& operator<<(ostream& out, const Time& t) {
        out << t.min << ":" << (t.sec < 10 ? "0" : "") << t.sec;
        return out;
    }

    friend istream& operator>>(istream& in, Time& t) {
        char c;
        in >> t.min >> c >> t.sec;
        t.normalize();
        return in;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    cout << "=== Тестирование Vector<int> ===" << endl;
    Vector<int> v1(5, 0);
    cout << "Введите 5 чисел: ";
    cin >> v1;
    cout << "v1 = " << v1 << endl;
    cout << "Размер: " << v1() << endl;
    cout << "v1[2] = " << v1[2] << endl;
    cout << "v1 + 10 = " << v1 + 10 << endl;

    cout << "\n=== Тестирование Vector<double> ===" << endl;
    Vector<double> v2(3, 0.0);
    cout << "Введите 3 числа: ";
    cin >> v2;
    cout << "v2 = " << v2 << endl;
    cout << "v2 * 2.5 = " << v2 * 2.5 << endl;

    cout << "\n=== Тестирование Vector<Time> ===" << endl;
    Time t1(1, 30);
    Vector<Time> v3(3, t1);
    cout << "Введите 3 времени (формат мин:сек): " << endl;
    cin >> v3;
    cout << "v3 = " << v3 << endl;
    cout << "Размер: " << v3() << endl;
    cout << "v3[1] = " << v3[1] << endl;

    return 0;
}