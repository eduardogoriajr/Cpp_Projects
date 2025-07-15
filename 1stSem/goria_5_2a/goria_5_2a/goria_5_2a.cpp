#include <iostream> 
#include <iomanip> 
using namespace std;

int main()
{
    int month, day;
    cout << "Enter month: "; cin >> month;
    cout << "\nEnter day: "; cin >> day;
    cout << "\n Zodiac sign for ";
    if (month == 1)
        cout << "January";
    else if (month == 2)
        cout << "February";
    else if (month == 3)
        cout << "March";
    else if (month == 4)
        cout << "April";
    else if (month == 5)
        cout << "May";
    else if (month == 6)
        cout << "June";
    else if (month == 7)
        cout << "July";
    else if (month == 8)
        cout << "August";
    else if (month == 9)
        cout << "September";
    else if (month == 10)
        cout << "Octover";
    else if (month == 11)
        cout << "November";
    else if (month == 12)
        cout << "December";

    cout << " " << day << " is ";
    if ((month == 1 && (day >= 20 && day <= 31)) || (month == 2 && (day >= 1 && day <= 18)))
        cout << "Aquarius";
    else if ((month == 2 && (day >= 19 && day <= 31)) || (month == 3 && (day >= 1 && day <= 20)))
        cout << "Pisces";
    else if ((month == 3 && (day >= 21 && day <= 31)) || (month == 4 && (day >= 1 && day <= 19)))
        cout << "Aries";
    else if ((month == 4 && (day >= 20 && day <= 30)) || (month == 5 && (day >= 1 && day <= 20)))
        cout << "Taurus";
    else if ((month == 5 && (day >= 21 && day <= 31)) || (month == 6 && (day >= 1 && day <= 20)))
        cout << "Gemini";
    else if ((month == 6 && (day >= 21 && day <= 30)) || (month == 7 && (day >= 1 && day <= 22)))
        cout << "Cancer";
    else if ((month == 7 && (day >= 23 && day <= 31)) || (month == 8 && (day >= 1 && day <= 22)))
        cout << "Leo";
    else if ((month == 8 && (day >= 23 && day <= 31)) || (month == 9 && (day >= 1 && day <= 22)))
        cout << "Virgo";
    else if ((month == 9 && (day >= 23 && day <= 30)) || (month == 10 && (day >= 1 && day <= 22)))
        cout << "Libra";
    else if ((month == 10 && (day >= 23 && day <= 31)) || (month == 11 && (day >= 1 && day <= 21)))
        cout << "Scorpio";
    else if ((month == 11 && (day >= 22 && day <= 30)) || (month == 12 && (day >= 1 && day <= 21)))
        cout << "Sagittarius";
    else if ((month == 12 && (day >= 22 && day <= 31)) || (month == 1 && (day >= 1 && day <= 19)))
        cout << "Capricorn";

    return 0;
}