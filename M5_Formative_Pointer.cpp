#include <iostream>
using namespace std;
int main() {
	int num = 100; //declare initial value
	int *ptr = &num	; // pointer stores the address of num
	cout << "Initial value of num: " << num << endl;  // output of num
	cout << "Memory address of num(&num): "<< &num << endl; // output of num memory address
	cout << "Value stored in ptr(address of num): "<< ptr <<endl; // output of pointer that stored the memory address of num
	cout << "Value accessed via ptr(*ptr): "<< *ptr << endl; // output of pointer that stored the value of num
	cout << endl;
	
	*ptr = 200; //assigning new value to pointer
	cout << "After modifying value through ptr: \n"; 
	cout << "Updated value of num: "<< num << endl; //since pointer is refers to num, value of num is *ptr
	cout << "Value accessed via ptr(*ptr): "<< *ptr << endl; //value of pointer
	system("pause");
	return 0;
}
