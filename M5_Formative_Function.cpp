#include <iostream>
using namespace std;

void doubledValue(int* ptr) {
    *ptr = *ptr * 2;
}

int main() {
    int num;
    cout << "Enter Integer to double: ";
    cin >> num;
    cout << "Original value: " << num << endl;

    doubledValue(&num);

    cout << "Doubled value: " << num << endl;
    return 0;
}

