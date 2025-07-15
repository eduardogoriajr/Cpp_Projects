#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *array = new int[size];

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    cout << "Array elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
	system("pause");
	delete[] array;
    return 0;
}

