#include <bits/stdc++.h>
using namespace std;

int main() {
    long n = 0,m = 0;
    cin >> n >> m;
    vector<int> freq(6, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x - 1]++;
    }
    long minimumFreq = n - m; //The minimum frequency of any one number for the flips provided to create winning scenario
    bool possible = false;
    for (int f : freq){
        if(f >= minimumFreq){
            possible = true;
            break;
        }
    }
    if (possible) {
        cout << "Ja" << endl;
    }
    else {
        cout << "Nej" << endl;
    }
    return 0;
}