#include <bits/stdc++.h>
using namespace std;

int main() {
    long n=0, k=0;
    cin >> k >> n;
    vector<pair<string, long>> items(n);

    long lazyCarry = n/k; //truncation floor
    long maxCarry = (n+k-1)/k; 
    long endNext = min(n, maxCarry + lazyCarry);

    for(auto &item : items) cin >> item.first >> item.second;
    
    stable_sort(items.begin(), items.end(), [](pair<string, long> a, pair<string, long> b) {
        return a.first < b.first;
    });
    stable_sort(items.begin(), items.end(), [](pair<string, long> a, pair<string, long> b) {
        return a.second < b.second;
    });

    long long maxWeight = accumulate(items.begin(), items.begin() + maxCarry, 0LL,
                                [](long long sum, const auto& p) {
                                    return sum + p.second;
                                });

    long long nextWeight = accumulate(items.begin() + maxCarry, items.begin() + endNext, 0LL,
                                [](long long sum, const auto& p) {
                                    return sum + p.second;
                                });

    long take = (maxWeight < nextWeight) ? maxCarry : lazyCarry;
    items.resize(take);
    long long totalweight = accumulate(items.begin(), items.begin()+take, 0LL,
                                    [](long long sum, const auto& p) {
                                        return sum + p.second;
                                    });
    
    cout << totalweight << endl;
    stable_sort(items.begin(), items.end(), [](pair<string, long> a, pair<string, long> b) {
        return a.first < b.first;
    });
    for(int i=0; i<take; i++) {
        cout << items[i].first << endl;
    }

    return 0;
}
