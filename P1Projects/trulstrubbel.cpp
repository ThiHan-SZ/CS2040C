#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    long T = 0, H = 0;
    size_t i = 0;

    while(i < s.length()){
        if (s[i] == 'T') {
            T += 1;
        }
        if (s[i] == 'H') {
            H += 1;
        }
        if ((T >= 11 && T - H >= 2) || (H >= 11 && H - T >= 2)) {
            T = 0;
            H = 0;
        }
        i++;
    }
    cout <<T<<"-"<<H<<endl;
    return 0;
}