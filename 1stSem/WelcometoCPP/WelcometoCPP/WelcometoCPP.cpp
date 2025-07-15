#include <iostream>
#include <string>
#include <math.c>
using namespace std;
const float PI = 3.14159;
int main()
{
    string school;
    cout << "Enter name of Uni\n";
    getline(cin, school);
    cout << "name of scool" << school << endl;
    float radius;
    cout << "Enter the radiaus of the circle ";
    cin >> radius;
    float area = PI * radius * radius;
    cout << "Area of the circle: " << area << endl;
    //const datatype variable name = value
    return 0;
}