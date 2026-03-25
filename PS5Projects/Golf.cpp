#include <bits/stdc++.h>
using namespace std;

// --- BIT (4 lines) ---
vector<long> bit;
int M;
void upd(int i, int v){ for(i++; i<=M; i+=i&-i) bit[i]+=v; }
int qry(int i){ int s=0; for(i++; i>0; i-=i&-i) s+=bit[i]; return s; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<string> players(N);
    for(auto& p : players) cin >> p;

    map<string, long> sim;
    for(auto& p : players) sim[p] = 0;

    vector<long> allScores = {0};
    vector<tuple<char,string,long>> queries; 

    for(int i = 0; i < Q; i++){
        char t; cin >> t;
        if(t == '!'){
            int u; cin >> u;
            while(u--){
                string s; long v; cin >> s >> v;
                sim[s] += v;
                allScores.push_back(sim[s]); 
                queries.push_back({'!', s, v});
            }
        } else {
            string s; cin >> s;
            queries.push_back({'?', s, 0});
        }
    }

    sort(allScores.begin(), allScores.end());
    allScores.erase(unique(allScores.begin(), allScores.end()), allScores.end());
    auto idx = [&](long v){ return (int)(lower_bound(allScores.begin(), allScores.end(), v) - allScores.begin()); };

    M = allScores.size();
    bit.assign(M + 1, 0);

    map<string, long> cur;
    for(auto& p : players){ cur[p] = 0; upd(idx(0), 1); }

    for(auto& [t, name, val] : queries){
        if(t == '!'){
            upd(idx(cur[name]), -1); 
            cur[name] += val;
            upd(idx(cur[name]),  1); 
        } else {
            int i = idx(cur[name]);
            cout << (i > 0 ? qry(i-1) : 0) + 1 << " " << cur[name] << "\n";
        }
    }
}
