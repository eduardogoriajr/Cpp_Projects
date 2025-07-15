#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int month, day;
    cout << "Enter month: "; cin >> month;
    cout << "\nEnter day: "; cin >> day;
    cout << "\nZodiac sign for ";

    switch (month) {
    case 1: cout << "January"; break;
    case 2: cout << "February"; break;
    case 3: cout << "March"; break;
    case 4: cout << "April"; break;
    case 5: cout << "May"; break;
    case 6: cout << "June"; break;
    case 7: cout << "July"; break;
    case 8: cout << "August"; break;
    case 9: cout << "September"; break;
    case 10: cout << "October"; break;
    case 11: cout << "November"; break;
    case 12: cout << "December"; break;
    }

    cout << " " << day << " is ";

    switch (month) {
    case 1:
        if (day >= 20 && day <= 31) cout << "Aquarius";
        else cout << "Capricorn";
        break;
    case 2:
        if (day >= 1 && day <= 18) cout << "Aquarius";
        else cout << "Pisces";
        break;
    case 3:
        if (day >= 1 && day <= 20) cout << "Pisces";
        else cout << "Aries";
        break;
    case 4:
        if (day >= 1 && day <= 19) cout << "Aries";
        else cout << "Taurus";
        break;
    case 5:
        if (day >= 1 && day <= 20) cout << "Taurus";
        else cout << "Gemini";
        break;
    case 6:
        if (day >= 1 && day <= 20) cout << "Gemini";
        else cout << "Cancer";
        break;
    case 7:
        if (day >= 1 && day <= 22) cout << "Cancer";
        else cout << "Leo";
        break;
    case 8:
        if (day >= 1 && day <= 22) cout << "Leo";
        else cout << "Virgo";
        break;
    case 9:
        if (day >= 1 && day <= 22) cout << "Virgo";
        else cout << "Libra";
        break;
    case 10:
        if (day >= 1 && day <= 22) cout << "Libra";
        else cout << "Scorpio";
        break;
    case 11:
        if (day >= 1 && day <= 21) cout << "Scorpio";
        else cout << "Sagittarius";
        break;
    case 12:
        if (day >= 1 && day <= 21) cout << "Sagittarius";
        else cout << "Capricorn";
        break;
    default:
        cout << "Invalid Date";
    }

    return 0;
}
