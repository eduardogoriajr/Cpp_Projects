#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float Php, sum;
    cout << "Enter Philippine Peso amount: ";
    float PhpToUsd = 1.000 / 43.33089;
    cin >> Php;
    cout << endl << "The amount's equivalent to:" << endl;
    sum = Php * PhpToUsd;
    cout << "USD: " << sum << endl;
    float PhpToEur = 0.734719 / 43.33089;
    sum = Php * PhpToEur;
    cout << "Euro: " << sum << endl;
    float PhpToYuan = 6.346934 / 43.33089;
    sum = Php * PhpToYuan;
    cout << "Yuan: " << sum << endl;
    float PhpToKoruna = 18.77263 / 43.33089;
    sum = Php * PhpToKoruna;
    cout << "Koruna: " << sum << endl;
    float PhpToKrone = 5.449007 / 43.33089;
    sum = Php * PhpToKrone;
    cout << "Krone: " << sum << endl;
    float PhpToSheqel = 3.726334 / 43.33089;
    sum = Php * PhpToSheqel;
    cout << "Sheqel: " << sum << endl;
    float PhpToDinar = 0.274588 / 43.33089;
    sum = Php * PhpToDinar;
    cout << "Dinar: " << sum << endl;
    return 0;
}