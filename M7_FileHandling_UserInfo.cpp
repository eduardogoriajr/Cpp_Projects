#include <iostream>
#include <fstream>
using namespace std;

int main() {

	ofstream fout;
	fout.open("C:\\TW01\\StudentInfo.doc");
	fout << "Eduardo Sanqui Goria Jr.\n";
	fout << "BSIT-WMA\n";
	fout << "202411896\n";
	fout.close();
	
	cout << fout;
	return 0;
}
