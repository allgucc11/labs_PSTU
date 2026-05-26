#include <iostream>
#include <string>
using namespace std;

class Computer {
private:
    string processor;
    int ram;
    int hdd;

public:
    Computer();
    Computer(string proc, int r, int h);
    Computer(const Computer& other);
    ~Computer();

    void setProcessor(string proc);
    void setRam(int r);
    void setHdd(int h);

    string getProcessor();
    int getRam();
    int getHdd();

    void show();
};

Computer::Computer() {
    processor = "";
    ram = 0;
    hdd = 0;
}

Computer::Computer(string proc, int r, int h) {
    processor = proc;
    ram = r;
    hdd = h;
}

Computer::Computer(const Computer& other) {
    processor = other.processor;
    ram = other.ram;
    hdd = other.hdd;
}

Computer::~Computer() {}

void Computer::setProcessor(string proc) {
    processor = proc;
}

void Computer::setRam(int r) {
    ram = r;
}

void Computer::setHdd(int h) {
    hdd = h;
}

string Computer::getProcessor() {
    return processor;
}

int Computer::getRam() {
    return ram;
}

int Computer::getHdd() {
    return hdd;
}

void Computer::show() {
    cout << "Процессор: " << processor
        << ", ОЗУ: " << ram << " ГБ"
        << ", ЖД: " << hdd << " ГБ" << endl;
}

Computer createPC() {
    string proc;
    int r, h;

    cout << "Введите процессор: ";
    cin >> proc;
    cout << "Введите объем ОЗУ (ГБ): ";
    cin >> r;
    cout << "Введите объем ЖД (ГБ): ";
    cin >> h;

    Computer c(proc, r, h);
    return c;
}

void showPC(Computer c) {
    c.show();
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "1. Конструктор без параметров" << endl;
    Computer comp1;
    comp1.show();

    cout << "\n2. Конструктор с параметрами" << endl;
    Computer comp2("Intel Core i7", 16, 512);
    comp2.show();

    cout << "\n3. Конструктор копирования (comp3 = comp2)" << endl;
    Computer comp3 = comp2;
    comp3.show();

    comp3.setProcessor("AMD Ryzen 5");
    comp3.setRam(32);
    comp3.setHdd(1024);
    cout << "После изменения comp3: ";
    comp3.show();

    cout << "\n4. Конструктор копирования (передача в функцию)" << endl;
    showPC(comp3);

    cout << "\n5. Конструктор копирования (возврат из функции)" << endl;
    Computer comp4 = createPC();
    comp4.show();

    return 0;
}