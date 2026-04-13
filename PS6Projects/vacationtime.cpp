#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, F;
    cin >> A >> F;

    vector<vector<tuple<int,int,bool>>> adj(A);

    for (int i = 0; i < F; i++) {
        int o, d, c;
        string model;
        cin >> o >> d >> c >> model;
        bool isA380 = (model == "A380");
        adj[o].push_back({d, c, isA380});
    }

    const int INF = INT_MAX / 2;
    vector<array<int,2>> dist(A, {INF, INF});
    dist[0][0] = 0;

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (d > dist[u][used]) continue; 

        for (auto [v, c, isA380] : adj[u]) {
            if (isA380) {
                int nd = d + c;
                if (nd < dist[v][1]) {
                    dist[v][1] = nd;
                    pq.push({nd, v, 1});
                }
            } else {
                int nd = d + c;
                if (nd < dist[v][used]) {
                    dist[v][used] = nd;
                    pq.push({nd, v, used});
                }
            }
        }
    }

    int ans = dist[A-1][1];
    cout << (ans == INF ? -1 : ans) << endl;
}