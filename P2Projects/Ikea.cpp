#include <bits/stdc++.h>
using namespace std;

int main() {
    long n=0, k=0;
    cin >> k >> n;
    vector<pair<string, long>> items(n);

    long lazyCarry = n/k; //truncation floor
    long maxCarry = (n+k-1)/k; 

    for(auto &item : items) cin >> item.first >> item.second;
    
    cout << endl;
    sort(items.begin(), items.end(), [](pair<string, long> a, pair<string, long> b) {
        return a.second < b.second;
    });

    bool obvious = false;
    if(lazyCarry > 0 && maxCarry < n) {
        obvious = (items[maxCarry-1].second < items[maxCarry].second);
    }
    long take = obvious ? maxCarry : lazyCarry;
    cout << take << endl;
    for(int i=0; i<take; i++) {
        cout << items[i].first << " " << items[i].second << endl;
    }


    return 0;
}
