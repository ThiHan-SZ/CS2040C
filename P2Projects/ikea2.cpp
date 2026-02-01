#include <bits/stdc++.h>
using namespace std;
long long sum(size_t left, size_t right, const vector<pair<long long, int>>& a) {
    long long sum = 0;
    for (size_t i = left; i < right; ++i) {
        sum += a[i].first;
    }
    return sum;
}
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

    long long maxWeight = sum(0,take2,a);
    long long right = min<long long>(n, take1 + take2);
    long long nextWeight = sum(take2,right,a);

    long long take, total;
    if (maxWeight < nextWeight) {
        take = take2;
        total = maxWeight;
    } else {
        take = take1;
        total = sum(0,take,a);
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
