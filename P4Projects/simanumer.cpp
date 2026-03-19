#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    size_t n = 0;
    cin >> n;
    vector<string> phoneRecords(n);
    for (size_t i = 0; i < n; i++) {
        cin >> phoneRecords[i];
    }
    size_t q = 0;
    cin >> q;
    vector<string> queries(q);
    for (size_t i = 0; i < q; i++) {
        cin >> queries[i];
    }

    unordered_map<string, long> prefixMap;
    for (size_t i = 0; i < n; i++) {
        size_t length = phoneRecords[i].length();
        for(size_t j = 0; j < length; j++) {
            string prefix = phoneRecords[i].substr(0, j + 1);
            prefixMap[prefix] += 1;
        }
    }
    for (size_t i = 0; i < q; i++) {
        cout << prefixMap[queries[i]] << endl;
    }
    return 0;
}
