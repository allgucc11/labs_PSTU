#include <iostream> 
#include <cmath> 
using namespace std;

int main() {
    double x = 2, x0 = 0;
    double eps = 0.000001;
    while (abs(x - x0) > eps)
    {
        x0 = x;
        x = x0 - (((0.25 * pow(x, 3)) + x - 1.2502) / ((0.75 * pow(x, 2)) + 1));
    }
    cout << "Корень по Ньютона:" << x << endl;
    return 0;
}