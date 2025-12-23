#include <iostream> 
#include <cmath> 
using namespace std;

int main() {
    float x = 0, x0 = 1;
    double eps = 0.000001, lambda = -0.2;
    while (abs(x - x0) > eps) 
    {
        x0 = x;
        x = lambda * (0.25 * pow(x0, 3) + x0 - 1.2502) + x0;
    }
    cout << "Корень по итерации: " << x << endl;
    return 0;
}