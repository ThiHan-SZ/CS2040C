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

}