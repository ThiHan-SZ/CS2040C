#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <string>

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    long long best_g = (s.back() == 'G') ? 1 : 0;
    long long best_a = (s.back() == 'A') ? 1 : 0;
    long long best_d = (s.back() == 'D') ? 1 : 0;

    long long g = best_g, a = best_a, d = best_d;

    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == 'G') ++g;
        else if (s[i] == 'A') ++a;
        else if (s[i] == 'D') ++d;

        if ((best_a + best_g) == 0 || (g * (best_a + best_g) > best_g * (a + g))) {
            best_a = a;
            best_g = g;
            best_d = d;
        }
    }

    cout << best_g << "-" << best_a << "\n";
    return 0;
}

