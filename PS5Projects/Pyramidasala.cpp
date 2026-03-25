#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    vector<Node*> children;
    Node(int value) : value(value) {}
};

void printTreeFlat(vector<Node*>& nodes, int N) {
    for (int i = 1; i <= N; i++) {
        cout << nodes[i]->value << ":";
        for (Node* child : nodes[i]->children)
            cout << " " << child->value;
        cout << "\n";  
    }
}

Node* reconstruct(vector<long>& pre, vector<long>& post,
                  int ps, int pe, int qs, int qe,
                  vector<Node*>& nodes,
                  vector<int>& pos) {          

    Node* root = nodes[pre[ps]];
    if (ps == pe) return root;

    int cur_ps = ps + 1;
    int cur_qs = qs;

    while (cur_ps <= pe) {
        int childRoot = pre[cur_ps];
        int k = pos[childRoot];                
        int size = k - cur_qs + 1;

        root->children.push_back(
            reconstruct(pre, post,
                        cur_ps, cur_ps + size - 1,
                        cur_qs, cur_qs + size - 1,
                        nodes, pos));
        cur_ps += size;
        cur_qs += size;
    }
    return root;
}

int main() {
    long N, M;
    cin >> N >> M;

    vector<Node*> nodes(N + 1);
    for (long i = 1; i <= N; i++) nodes[i] = new Node(i);

    vector<long> seq1(N + 1, 0), seq2(M + 1, 0), seq3(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> seq1[i];
    for (int i = 1; i <= M; i++) cin >> seq2[i];
    for (int i = 1; i <= N; i++) cin >> seq3[i];
    vector<int> pos(N + 1);
    for (int i = 1; i <= N; i++) pos[seq3[i]] = i;

    Node* root = reconstruct(seq1, seq3, 1, N, 1, N, nodes, pos);

    printTreeFlat(nodes, N);
    return 0;
}
