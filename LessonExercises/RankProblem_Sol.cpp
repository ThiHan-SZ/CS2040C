#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    for (int _ = 0; _ < q; _++) {
        string a, b;
        cin >> a >> b;

        int A = stoi(a.substr(1)); // drop leading 'T'
        int B = stoi(b.substr(1));

        auto itA = find(ans.begin(), ans.end(), A);
        auto itB = find(ans.begin(), ans.end(), B);

        int ia = (int)distance(ans.begin(), itA);
        int ib = (int)distance(ans.begin(), itB); // std::find + std::distance to get index [web:6]

        if (ia < ib) continue;

        ans.erase(ans.begin() + ib);
        ans.insert(ans.begin() + ia, B);
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << 'T' << ans[i];
    }
    cout << '\n';
    return 0;
}
