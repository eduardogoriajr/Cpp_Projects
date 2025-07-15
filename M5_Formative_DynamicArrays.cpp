#include <iostream>
using namespace std;

int main(){
	int size; // ask for array size
	cout << "Enter the size of the array: ";
	cin >> size;
	
	int *array = new int[size]; // the size of array has been dynamically set by user
	
	cout << "Enter " << size << " integers: \n"; // ask for integers according to size
	for (int i = 0; i < size ;i++){
		cin >> array[i];
	}
	for (int i = 0; i < size;i++){ //loop function to see memory address
	 cout << "arr["<< i + 1 << "] = " << array[i] << "(Address: " << &array[i] << ")"<< endl; 
	 }
	
	system("pause");
	delete[] array;
	return 0;
}
