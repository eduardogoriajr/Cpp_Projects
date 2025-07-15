#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    cout << "Enter First number\n";
    int x, y, z;
    cin >> x;
    cout << "Enter Second number\n";
    cin >> y;
    z = x + y;
    cout << "sum = " << z << endl;
    z = x - y;
    cout << "difference = " << z << endl;
    z = x * y;
    cout << "product = " << z << endl;
    z = x % y;
    cout << "remainder = " << z << endl;
    z = x / y;
    cout << "quotient = " << z << endl;
    return 0;
}