#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, n;
    cin >> k >> n;

    vector<string> name(n);
    vector<pair<long long, int>> a; 
    a.reserve(n);

    for (int i = 0; i < (int)n; ++i) {
        string s;
        long long w;
        cin >> s >> w;
        name[i] = s;
        a.push_back({w, i});
    }

    sort(a.begin(), a.end()); 

    long long take1 = n / k;
    long long take2 = (n + k - 1) / k;

    long long maxWeight = accumulate(a.begin(), a.begin() + take2, 0LL,
                                [](long long s, const auto& p) { return s + p.first; });
    long long right = min<long long>(n, take1 + take2);
    long long nextWeight = accumulate(a.begin() + take2, a.begin() + right, 0LL,
                                [](long long s, const auto& p) { return s + p.first; });
    
    long long take, total;
    if (maxWeight < nextWeight) {
        take = take2;
        total = maxWeight;
    } else {
        take = take1;
        total = accumulate(a.begin(), a.begin() + take, 0LL,
                            [](long long s, const auto& p) { return s + p.first; });
    }

    vector<string> ans;
    ans.reserve((size_t)take);
    for (int i = 0; i < (int)take; ++i) {
        ans.push_back(name[a[i].second]);
    }
    sort(ans.begin(), ans.end());

    cout << total << "\n";
    for (auto &s : ans) cout << s << "\n";
    return 0;
}
