#include <bits/stdc++.h>
using namespace std;

int main() {
    int cityCount, lineCount;
    cin >> cityCount >> lineCount;

    vector<int> edge(cityCount, -1);

    for (int i = 0; i < lineCount; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        if (u == (v + 1) % cityCount) swap(u,v);

        if (v != (u + 1) % cityCount) continue;

        edge[u] = i;
    }

    if (cityCount == 2) {
        edge[0] = max(edge[0], edge[1]);
        edge[1] = max(edge[0], edge[1]);
    }

    if (*min_element(begin(edge),end(edge)) == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    for (auto e : edge)cout << e+1 << endl;
}