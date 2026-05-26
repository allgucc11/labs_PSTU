#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

class Object {
public:
    Object() {}
    virtual ~Object() {}
    virtual void Show() = 0;
};

class Pair : public Object {
protected:
    int first;
    int second;

public:
    Pair() : first(0), second(1) {}
    Pair(int f, int s) : first(f), second(s) { if (second == 0) second = 1; }
    Pair(const Pair& other) : first(other.first), second(other.second) {}
    virtual ~Pair() {}

    int getFirst() const { return first; }
    int getSecond() const { return second; }
    void setFirst(int f) { first = f; }
    void setSecond(int s) { if (s != 0) second = s; }

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    bool operator==(const Pair& other) const {
        return (first == other.first && second == other.second);
    }

    int multiply() const {
        return first * second;
    }

    Pair operator-(const Pair& other) const {
        return Pair(first - other.first, second - other.second);
    }

    virtual void Show() {
        cout << "Pair: (" << first << "," << second << ")" << endl;
    }

    friend istream& operator>>(istream& in, Pair& p);
    friend ostream& operator<<(ostream& out, const Pair& p);
};

istream& operator>>(istream& in, Pair& p) {
    in >> p.first >> p.second;
    if (p.second == 0) p.second = 1;
    return in;
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

class Rational : public Pair {
private:
    int gcd(int a, int b) const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        if (second < 0) {
            first = -first;
            second = -second;
        }
        int g = gcd(first, second);
        first /= g;
        second /= g;
    }

public:
    Rational() : Pair(0, 1) {}
    Rational(int num, int den) : Pair(num, den) {
        if (second == 0) second = 1;
        reduce();
    }

    Rational(const Rational& other) : Pair(other) { reduce(); }
    ~Rational() {}

    int getNumerator() const { return first; }
    int getDenominator() const { return second; }
    void setNumerator(int num) { first = num; reduce(); }
    void setDenominator(int den) { if (den != 0) second = den; reduce(); }

    Rational& operator=(const Rational& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    Rational operator+(const Rational& other) const {
        return Rational(first * other.second + second * other.first,
            second * other.second);
    }

    Rational operator-(const Rational& other) const {
        return Rational(first * other.second - second * other.first,
            second * other.second);
    }

    Rational operator/(const Rational& other) const {
        return Rational(first * other.second, second * other.first);
    }

    Rational operator*(const Rational& other) const {
        return Rational(first * other.first, second * other.second);
    }

    bool operator==(const Rational& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return first * other.second < other.first * second;
    }

    bool operator>(const Rational& other) const {
        return first * other.second > other.first * second;
    }

    bool operator<=(const Rational& other) const {
        return first * other.second <= other.first * second;
    }

    bool operator>=(const Rational& other) const {
        return first * other.second >= other.first * second;
    }

    virtual void Show() {
        cout << "Rational: " << first << "/" << second << endl;
    }

    friend istream& operator>>(istream& in, Rational& r);
    friend ostream& operator<<(ostream& out, const Rational& r);
};

istream& operator>>(istream& in, Rational& r) {
    cout << "Введите числитель и знаменатель: ";
    in >> r.first >> r.second;
    if (r.second == 0) r.second = 1;
    r.reduce();
    return in;
}

ostream& operator<<(ostream& out, const Rational& r) {
    if (r.second == 1)
        out << r.first;
    else
        out << r.first << "/" << r.second;
    return out;
}

class Vector {
private:
    Object** beg;
    int size;
    int cur;

public:
    Vector() : beg(0), size(0), cur(0) {}
    Vector(int n) {
        beg = new Object * [n];
        cur = 0;
        size = n;
    }
    ~Vector() {
        if (beg != 0) delete[] beg;
        beg = 0;
    }

    void Add(Object* p) {
        if (cur < size) {
            beg[cur] = p;
            cur++;
        }
    }

    friend ostream& operator<<(ostream& out, const Vector& v);
};

ostream& operator<<(ostream& out, const Vector& v) {
    if (v.size == 0) {
        out << "Empty" << endl;
        return out;
    }
    Object** p = v.beg;
    for (int i = 0; i < v.cur; i++) {
        (*p)->Show();
        p++;
    }
    return out;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Класс PAIR ===" << endl;
    Pair p1(5, 10);
    Pair p2(3, 4);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p1 == p2? " << (p1 == p2 ? "Да" : "Нет") << endl;
    cout << "Произведение полей p1: " << p1.multiply() << endl;
    cout << "p1 - p2 = " << (p1 - p2) << endl;

    cout << "\n=== Класс RATIONAL (дроби) ===" << endl;
    Rational a, b, c;

    cout << "Введите первую дробь: ";
    cin >> a;
    cout << "Введите вторую дробь: ";
    cin >> b;

    cout << "\nПервая дробь: " << a << endl;
    cout << "Вторая дробь: " << b << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a < b? " << (a < b ? "Да" : "Нет") << endl;
    cout << "a > b? " << (a > b ? "Да" : "Нет") << endl;
    cout << "a <= b? " << (a <= b ? "Да" : "Нет") << endl;
    cout << "a >= b? " << (a >= b ? "Да" : "Нет") << endl;

    cout << "\n=== Полиморфизм (Vector) ===" << endl;

    Vector v(5);

    Pair pairObj(10, 20);
    Rational rat1(1, 2);
    Rational rat2(3, 4);

    v.Add(&pairObj);
    v.Add(&rat1);
    v.Add(&rat2);

    cout << "Содержимое вектора:" << endl;
    cout << v;

    return 0;
}