#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int, int> position;
    vector<Node*> neighbours;
    bool visited = false;
    int dist = -1;
    Node(int r,int c) : position({r,c}) {}
};

int shortestPath(Node* start, vector<Node*>& goals, vector<Node*>& allNodes) {
    if (!start || goals.empty()) return -1;

    for (Node* n : allNodes) {
        n->visited = false;
        n->dist = -1;
    }

    unordered_set<Node*> goalSet(goals.begin(), goals.end());

    queue<Node*> q;
    start->visited = true;
    start->dist = 0;
    q.push(start);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (goalSet.count(cur)) {
            return cur->dist;
        }

        for (Node* nxt : cur->neighbours) {
            if (!nxt->visited) {
                nxt->visited = true;
                nxt->dist = cur->dist + 1;
                q.push(nxt);
            }
        }
    }
    return -1; 
}
int main() {
    long h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    vector<vector<Node*>> nodes(h, vector<Node*>(w, nullptr));
    vector<Node*> allNodes;
    Node* start = nullptr;
    vector<Node*> goals;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            char ch = grid[r][c];
            if (ch != '#'){
                nodes[r][c] = new Node(r,c);
                allNodes.push_back(nodes[r][c]);
                if (ch == 'S') start = nodes[r][c];
                if (ch == 'G') goals.push_back(nodes[r][c]);
            }
        }
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            if (!nodes[r][c]) continue; // wall

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (0 <= nr && nr < h && 0 <= nc && nc < w && nodes[nr][nc]) {
                    nodes[r][c]->neighbours.push_back(nodes[nr][nc]);
                }
            }
        }
    }
    int result = shortestPath(start, goals, allNodes);
    if (result == -1) cout << "thralatlega nettengdur" << endl;
    else              cout << result << endl;
    return 0;
}
