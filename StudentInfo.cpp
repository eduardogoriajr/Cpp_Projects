#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open the file for writing
    ofstream fout;
    fout.open("C:\\TW01\\StudentInfo.doc");
    fout << "Eduardo Sanqui Goria Jr\n";
    fout << "BSIT-WMA\n";
    fout << "202411896";
    fout.close();

    // Open the file for reading
    string myFile;
    ifstream myReadFile("C:\\TW01\\StudentInfo.doc");
    if (myReadFile.is_open()) {
        while (getline(myReadFile, myFile)) {
            cout << myFile << endl; // Output the file content to the terminal
        }
        myReadFile.close();
    } else {
        cout << "Unable to open file";
    }

    // Pause the console in case you want to open the exe.file
    cout << "Press any key to continue...";
    system("pause");
    return 0;
}

