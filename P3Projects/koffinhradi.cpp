#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    cin >> n;

    vector<array<long long, 2>> arr(n);
    for (auto &[x,y] : arr) cin >> x >> y;

    sort(arr.begin(), arr.end(),[](auto a, auto b){
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });

    long long drinks = 0, sum = 0;
    priority_queue<long long> q;
    for(auto [t, s] : arr) {
        q.push(t);
        sum += t;
        while(sum > s){
            long long curr = q.top(); 
            q.pop();
            q.push(curr/2);
            sum -= ceil(curr/2.0);
            ++drinks;
        }
    }

    cout << drinks << endl;
}
