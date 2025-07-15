#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float sales, income, total;
    cout << "Enter Monthly Sales: ";
    cin >> sales;


    if (sales >= 50000)
        cout << "Income: " << 575 + (sales * 0.16);
    else if (sales < 50000 && sales >= 40000)
        cout << "Income: " << 550 + (sales * 0.14);
    else if (sales < 40000 && sales >= 30000)
        cout << "Income: " << 525 + (sales * 0.12);
    else if (sales < 30000 && sales >= 20000)
        cout << "Income: " << 500 + (sales * 0.09);
    else if (sales < 20000 && sales >= 10000)
        cout << "Income: " << 450 + (sales * 0.05);
    else if (sales < 10000)
        cout << "Income: " << 400 + (sales * 0.03);

    return 0;
}

