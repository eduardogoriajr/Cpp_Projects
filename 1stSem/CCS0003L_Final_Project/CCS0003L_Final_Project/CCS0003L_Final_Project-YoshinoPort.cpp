#include <iostream>
using namespace std;

int main() {
    int choice;
    char ans;
cout << "Select a Topic to have a quiz:\n";
cout << "[1] THE History of GOMBURZA\n";
cout << "[2] Science Evolution Period\n";
cout << "[3] C++\n";
cout << "[4] Binary Operations\n";

cin >> choice;

    switch (choice) {
    case 1:
        cout << "Quiz 1 THE History of GOMBURZA\n";

            cout << "Question 1. at What year were the 3 priest Executed";
            switch (ans) {
                case ('A') || ('a') : "A. 1989";
            }
        break;
    case 2:
        cout << "You selected Option 2\n";
        break;
    case 3:
        cout << "You selected Option 3\n";
        break;
    default:
        cout << "Invalid selection\n";
        break;
    }
    return 0;
}
