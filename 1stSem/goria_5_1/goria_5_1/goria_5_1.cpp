#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float grade1, grade2, grade3, result;
    
    cout << "Enter Your Grades : \n";
    cout << "Computer Studies: "; cin >> grade1;
    cout << "\n General Academics: "; cin >> grade2;
    cout << "\n Physical Education: "; cin >> grade3;
    result = (grade1 + grade2 + grade3) / 3;
    cout << "\n\n Your Average is: "<< setprecision(4) << result;
    if(result >=70)
        cout <<" You Passed :-)";
    else
        cout << " You Failed :-(";
    return 0;
}
