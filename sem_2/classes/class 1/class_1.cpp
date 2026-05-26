#include <iostream>
using namespace std;

class LinearEquation {
private:
    double first;
    double second;

public:
    LinearEquation(double a = 0, double b = 0) : first(a), second(b) {}

    void Read() {
        cout << "Введите A: ";
        cin >> first;
        cout << "Введите B: ";
        cin >> second;
    }

    void Show() const {
        cout << "y = " << first << "x + " << second << endl;
    }

    double Function(double x) const {
        return first * x + second;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Способ 1: Конструктор" << endl;
    LinearEquation eq1(2, 3);
    eq1.Show();
    cout << "y(5) = " << eq1.Function(5) << endl << endl;

    cout << "Способ 2: Ввод с клавиатуры" << endl;
    LinearEquation eq2;
    eq2.Read();
    eq2.Show();
    cout << "y(5) = " << eq2.Function(5) << endl << endl;

    cout << "Способ 3: Прямая инициализация" << endl;
    LinearEquation eq3(4, -1);
    eq3.Show();
    cout << "y(5) = " << eq3.Function(5) << endl << endl;

    cout << "Массив объектов" << endl;
    LinearEquation equations[3] = {
        LinearEquation(1, 2),
        LinearEquation(3, 4),
        LinearEquation(5, 6)
    };

    for (int i = 0; i < 3; i++) {
        cout << "Уравнение " << i + 1 << ": ";
        equations[i].Show();
        cout << "y(10) = " << equations[i].Function(10) << endl;
    }

    return 0;
}