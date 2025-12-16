#include <iostream>

using namespace std;

int main() 
{
    float l_n = 1, n = 1;
    bool nanana = false;

    while (n != 0)
    {
        if (n < l_n) 
        {
            nanana = true;
        }

        l_n = n;
        cin >> n;
    }
    if (nanana == true) 
    {
        cout << "да" << endl; 
    }
    else { cout << "нет" << endl; }

    return 0;
}