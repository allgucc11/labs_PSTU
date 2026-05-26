#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

class Money {
private:
    long rubles;
    int kopecks;

public:
    void normalize() {
        if (kopecks >= 100) {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
        else if (kopecks < 0) {
            long rubles_to_subtract = (abs(kopecks) + 99) / 100;
            rubles -= rubles_to_subtract;
            kopecks += rubles_to_subtract * 100;
        }
    }

    Money() : rubles(0), kopecks(0) {}
    Money(long r, int k) : rubles(r), kopecks(k) { normalize(); }
    Money(const Money& other) : rubles(other.rubles), kopecks(other.kopecks) {}
    ~Money() {}

    long getRubles() const { return rubles; }
    int getKopecks() const { return kopecks; }
    void setRubles(long r) { rubles = r; normalize(); }
    void setKopecks(int k) { kopecks = k; normalize(); }

    Money operator+(const Money& other) {
        return Money(rubles + other.rubles, kopecks + other.kopecks);
    }

    double operator/(const Money& other) const {
        double val1 = rubles + kopecks / 100.0;
        double val2 = other.rubles + other.kopecks / 100.0;
        return val1 / val2;
    }

    Money operator*(double factor) const {
        double total = (rubles + kopecks / 100.0) * factor;
        long newRubles = static_cast<long>(total);
        int newKopecks = static_cast<int>(round((total - newRubles) * 100));
        return Money(newRubles, newKopecks);
    }

    friend istream& operator>>(istream& in, Money& a);
    friend ostream& operator<<(ostream& out, const Money& a);
};

istream& operator>>(istream& in, Money& a) {
    cout << "Рубли: ";
    in >> a.rubles;
    cout << "Копеек: ";
    in >> a.kopecks;
    a.normalize();
    return in;
}

ostream& operator<<(ostream& out, const Money& a) {
    out << a.rubles << " руб. ";
    if (a.kopecks < 10) out << "0";
    out << a.kopecks << " коп.";
    return out;
}

int main() {
    setlocale(LC_ALL, "RUS");
    Money a, b, c;
    double factor;

    cout << "Введите первую сумму: " << endl;
    cin >> a;
    cout << "Введите вторую сумму: " << endl;
    cin >> b;

    cout << "Частное: " << a << " / " << b << " = " << a / b << endl;

    cout << "Введите множитель: ";
    cin >> factor;
    c = a * factor;
    cout << a << " * " << factor << " = " << c << endl;

    return 0;
}