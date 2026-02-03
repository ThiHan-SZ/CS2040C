#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<long long> readyTime(n, 0);
    for (size_t i = 0; i < n; ++i) {cin >> readyTime[i];}

    sort(readyTime.begin(),readyTime.end(),[](long long a, long long b){
        return a < b;
    });

    vector<long long> P(n);
    P[0] = readyTime[0];
    for (size_t i = 1; i < n; ++i) {
        P[i] = P[i-1] + readyTime[i];
    }

    long long minTotalWait = -1; 

    for (size_t i = 0; i < n; ++i) {
        
        long long count1 = i + 1;
        long long sum1 = P[i];
        long long wait1 = (count1 * readyTime[i]) - sum1;

        long long wait2 = 0;
        if (i < n - 1) {
            long long count2 = n - 1 - i;
            long long sum2 = P[n-1] - P[i];
            wait2 = (count2 * readyTime[n-1]) - sum2;
        }

        long long totalWait = wait1 + wait2;

        if (minTotalWait == -1 || totalWait < minTotalWait) {
            minTotalWait = totalWait;
        }
    }

    cout << minTotalWait << endl;

    return 0;
}