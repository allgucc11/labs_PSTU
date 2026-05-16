#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char help)
{
    if (n == 1)
    {
        cout << "Переложить диск 1 с " << from << " на " << to << endl;
        return;
    }

    hanoi(n - 1, from, help, to);

    cout << "Переложить диск " << n << " с " << from << " на " << to << endl;

    hanoi(n - 1, help, to, from);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    hanoi(n, 'A', 'C', 'B');

    return 0;
}