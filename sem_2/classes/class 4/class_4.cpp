#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

class Pair {
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

    Pair operator-(const Pair& other) const {
        return Pair(first - other.first, second - other.second);
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
    out << p.first << "/" << p.second;
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

    Rational operator*(const Rational& other) const {
        return Rational(first * other.first, second * other.second);
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

void f1(Pair& p) {
    p.setFirst(5);
    p.setSecond(2);
}

Pair f2() {
    Rational r(3, 4);
    return r;
}

int main() {
    setlocale(LC_ALL, "RUS");
    Rational a, b, c;
    cin >> a;
    cin >> b;
    c = a + b;
    cout << a << " + " << b << " = " << c << endl;

    c = a - b;
    cout << a << " - " << b << " = " << c << endl;

    c = a * b;
    cout << a << " * " << b << " = " << c << endl;

    return 0;
}