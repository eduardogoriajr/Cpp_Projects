#include <iostream>
using namespace std;

void reverseString(char *str){
    char *ptr = str;
    while (*ptr!= '\0'){
        ptr++;
    }
    ptr--;

    cout << "Reversed string: ";
    while (ptr >= str) {
        cout << *ptr;
        ptr--;
    }
    cout << endl;
}

void countPunctuation(char *str) {
    int dotCount = 0, commaCount = 0, exclaCount = 0;
    char *ptr = str;

    while (*ptr != '\0'){
        if (*ptr == '.') dotCount++;
        else if (*ptr == ',') commaCount++;
        else if (*ptr == '!') exclaCount++;
        ptr++;
    }

    cout << "Dots (.): " << dotCount << endl;
    cout << "Commas (,): " << commaCount << endl;
    cout << "Exclamations (!): " << exclaCount << endl;
}

void toCapitalLetters(char *str){
    char *ptr = str;

    while (*ptr != '\0'){
        if (*ptr >= 'a' && *ptr <= 'z'){
            *ptr = *ptr - 32;
        }
        ptr++;
    }

    cout << "Converted to uppercase: " << str << endl;
}

int main() {
    char str[100];
    int menu;
    char again;

    do {
        cout << "Menu:" << endl;
        cout << "1. Reverse the string" << endl;
        cout << "2. Count punctuation marks (., !)" << endl;
        cout << "3. Convert to uppercase" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> menu;
        cin.ignore();

        switch (menu) {
            case 1:
                cout << "Enter a string: ";
                cin.getline(str, 100);
                reverseString(str);
                break;
            case 2:
                cout << "Enter a string: ";
                cin.getline(str, 100);
                countPunctuation(str);
                break;
            case 3:
                cout << "Enter a string: ";
                cin.getline(str, 100);
                toCapitalLetters(str);
                break;
            default:
                cout << "Invalid choice! Please enter either 1 / 2 / 3" << endl;
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> again;
        cin.ignore();
        cout << endl;

    } while (again == 'Y');

    return 0;
}
