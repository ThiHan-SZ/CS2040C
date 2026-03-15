#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n = 0, m = 0;
    cin >> n >> m;
    unordered_set<long long> s;
    for (int i = 0; i < n; i++) {
        size_t numPieces;
        cin >> numPieces;
        for(int j = 0; j < numPieces; j++) {
            long long piece;
            cin >> piece;
            if(1<= piece && piece <= m) {
                s.insert(piece);
            }
        }
    }
    if(s.size() == m) {
        cout << "Jebb" << endl;
    } else {
        cout << "Neibb" << endl;
    }
    return 0;
}
