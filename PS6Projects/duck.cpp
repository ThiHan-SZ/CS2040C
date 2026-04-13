#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_;
    vector<int> orVal;  // OR of all edge f-values in this component

    DSU(int n) : parent(n), rank_(n, 0), orVal(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int x, int y, int f) {
        x = find(x); y = find(y);
        // Always OR the edge value into whichever root survives
        if (x == y) {
            orVal[x] |= f;
            return;
        }
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        orVal[x] |= orVal[y] | f;
        if (rank_[x] == rank_[y]) rank_[x]++;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
    int getOr(int x) { return orVal[find(x)]; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    // Build DSU once over all edges
    DSU dsu(N);
    for (int i = 0; i < M; i++) {
        int u, v, f;
        cin >> u >> v >> f;
        u--; v--;
        dsu.unite(u, v, f);
    }

    while (Q--) {
        int A, B;
        cin >> A >> B;
        A--; B--;

        if (!dsu.connected(A, B)) {
            cout << -1 << "\n";
        } else {
            // Answer = popcount of OR of all edges in the component
            int orAll = dsu.getOr(A);
            cout << __builtin_popcount(orAll) << "\n";
        }
    }
}