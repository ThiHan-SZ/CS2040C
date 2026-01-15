#include <bits/stdc++.h>
using namespace std;

int main() {

    double l, s;
    cin >> l >> s;
    l /= 100.0;
    s /= 100.0;

    double exemption = 0.0;
    long long h = 0;

    for (int month = 0; month < 12; ++month) {
        double currSalary;
        cin >> currSalary;

        currSalary -= floor(l * currSalary) + floor(s * currSalary); //Remove Pensions

        double bracket1 = min(409986.0, currSalary);                  //Calculate Amount in Bracket 1
        double bracket2 = min(1151012.0, currSalary) - bracket1;      //Calculate Amount in Bracket 2
        double bracket3 = max(0.0, currSalary - bracket1 - bracket2); //Calculate Amount in Bracket 3

        double witholding_d = floor(bracket1 * 0.3145 + bracket2 * 0.3795 + bracket3 * 0.4625); //Calculate Witholding
        long long witholding_l = (long long)witholding_d;                                       //Convert to Long

        exemption += 59665.0;

        double deduction = min(exemption, (double)witholding_l);
        witholding_l -= (long long)deduction;
        exemption -= deduction;

        currSalary -= (double)witholding_l;
        h += (long long)currSalary;
    }

    cout << h << "\n";
    return 0;
}
