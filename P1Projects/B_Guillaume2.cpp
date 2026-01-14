#include <bits/stdc++.h>
using namespace std;


int main()
{
    long matches;
    cin >> matches;

    string results;
    cin >> results;

    vector<long> GA(2,0);
    vector<double> GA_ratio(results.length(),0);
    for (size_t i = results.size(), j = 0; i-- > 0; ++j) {
        if (results[i] == 'G') ++GA[0];
        if (results[i] == 'A') ++GA[1];
        if (GA[0] > 0 && GA[1] > 0) GA_ratio[j] = double(GA[0]) / double(GA[1]+GA[0]);
    }

    auto it = max_element(GA_ratio.begin(), GA_ratio.end());
    size_t max_idx =  it - GA_ratio.begin() + 1;

    GA = {0,0};
    for (size_t i = GA_ratio.size()-1; max_idx-- > 0; i--)
    {
        if (results[i] == 'G') ++GA[0];
        if (results[i] == 'A') ++GA[1];
    }

    cout << GA[0] << "-" << GA[1] << endl;

    return 0;
}