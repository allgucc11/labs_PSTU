#include <iostream>
#include <clocale>
using namespace std;

class Iterator {
    friend class Set;
private:
    int* elem;

public:
    Iterator() : elem(nullptr) {}
    Iterator(int* e) : elem(e) {}
    Iterator(const Iterator& it) : elem(it.elem) {}

    bool operator==(const Iterator& it) const { return elem == it.elem; }
    bool operator!=(const Iterator& it) const { return elem != it.elem; }

    void operator--() { --elem; }
    void operator--(int) { elem--; }
    int& operator*() const { return *elem; }
};

class Set {
private:
    int size;
    int* data;
    Iterator beg;
    Iterator end;

public:
    Set(int s, int k = 0) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
        beg = Iterator(data);
        end = Iterator(data + size);
    }

    Set(const Set& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        beg = Iterator(data);
        end = Iterator(data + size);
    }

    ~Set() {
        delete[] data;
        data = nullptr;
    }

    Set& operator=(const Set& other) {
        if (this == &other) return *this;
        size = other.size;
        if (data != nullptr) delete[] data;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        beg = Iterator(data);
        end = Iterator(data + size);
        return *this;
    }

    int& operator[](int index) {
        return data[index];
    }

    operator int() const {
        return size;
    }

    Set operator*(const Set& other) const {
        int* temp = new int[size];
        int count = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                if (data[i] == other.data[j]) {
                    bool found = false;
                    for (int k = 0; k < count; k++) {
                        if (temp[k] == data[i]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        temp[count] = data[i];
                        count++;
                    }
                    break;
                }
            }
        }

        Set result(count);
        for (int i = 0; i < count; i++) {
            result.data[i] = temp[i];
        }
        delete[] temp;
        return result;
    }

    Iterator first() const { return beg; }
    Iterator last() const { return end; }

    friend ostream& operator<<(ostream& out, const Set& s);
    friend istream& operator>>(istream& in, Set& s);
};

ostream& operator<<(ostream& out, const Set& s) {
    for (int i = 0; i < s.size; i++) {
        out << s.data[i] << " ";
    }
    return out;
}

istream& operator>>(istream& in, Set& s) {
    for (int i = 0; i < s.size; i++) {
        in >> s.data[i];
    }
    return in;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер множества: ";
    cin >> n;

    Set A(n);
    cout << "Введите " << n << " элементов: ";
    cin >> A;

    cout << "A = " << A << endl;
    cout << "Размер A = " << (int)A << endl;

    cout << "A[0] = " << A[0] << endl;

    cout << "Введите размер второго множества: ";
    cin >> n;
    Set B(n);
    cout << "Введите " << n << " элементов: ";
    cin >> B;

    cout << "B = " << B << endl;
    cout << "Размер B = " << (int)B << endl;

    Set C = A * B;
    cout << "Пересечение A и B = " << C << endl;

    return 0;
}