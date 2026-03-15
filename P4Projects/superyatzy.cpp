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
    auto it = find(freq.begin(), freq.end(), minimumFreq); //This will find the minimum frequency of any one number
    if (it != freq.end()) {
        cout << "Ja" << endl;
    }
    else {
        cout << "Nej" << endl;
    }
    return 0;
}