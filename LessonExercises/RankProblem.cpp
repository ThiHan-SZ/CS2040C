#include <bits/stdc++.h>
using namespace std;

vector<string> make_Teams(int n){
    vector<string> teams;
    teams.reserve(n);
    for(int i = 1; i<=n; ++i){
        teams.push_back("T"+to_string(i));
    }
    return teams;
}

int main() {
    long n=0 , m=0;
    cin>>n>>m;
    vector<pair<string,string>> games(m);
    vector<string> teams = make_Teams(n);
    for(int i = 0; i<m; ++i){
        cin>>games[i].first>>games[i].second;
    }

    for(int i = 0; i<m; ++i){
        auto it  = find(teams.begin(),teams.end(),games[i].first);
        auto it2 = find(teams.begin(),teams.end(),games[i].second);
        if(it != teams.end() && it2 != teams.end()){
            size_t idxWin = it - teams.begin();
            size_t idxLose = it2 - teams.begin();
            if (idxWin < idxLose) continue;
            string losingTeam = teams[idxLose];
            teams.erase(teams.begin() + idxLose);
            teams.insert(teams.begin() + idxWin, losingTeam);
        }
    }
    for(int i = 0; i<n; ++i){
        cout<<teams[i]<<" ";
    }
    return 0;
}