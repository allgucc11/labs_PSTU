#include <iostream> 
#include <cmath> 
using namespace std;

int main() {
    float a, b, c;
    float fa, fb, fc;
    double eps = 0.000001;
    a = 0;
    b = 2;
    while (b - a > eps)
    {
        c = (a + b) / 2;
        fa = 0.25 * pow(a, 3) + a - 1.2502;
        fb = 0.25 * pow(b, 3) + b - 1.2502;
        fc = 0.25 * pow(c, 3) + c - 1.2502;
        if (fa * fc < 0)
        { 
            b = c; 
        }
        else if (fc * fb < 0) 
        {
            a = c; 
        }
        else 
        {
            cout << "ошибка" << endl;
            break;
        }
    }
    cout << "Корни: " << a << "; " << b << endl;
    return 0;
}
