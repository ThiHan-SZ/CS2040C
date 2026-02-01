#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<string> cards(n);
    string ordinal;
    for(size_t i = 0; i < n; ++i) {
        getline(cin >> ws, cards[i]);
    }
    getline(cin>>ws,ordinal);
    for(auto& card : cards) {
        cout << card << endl;
    }
    cout << ordinal;
    
    return 0;
}
