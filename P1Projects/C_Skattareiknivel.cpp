#include <bits/stdc++.h>
using namespace std;

int main(){
    double l = 0, s = 0; cin >> l >> s;
    l /= 100.0; s /= 100.0;
    vector<long long> monthly_salary(12,0);
    long long sum = 0;
    for (size_t i = 0; i < 12; i++)
    {
        cin >> monthly_salary[i];
    }

    for(long long salary : monthly_salary) sum += salary;

    cout<< sum <<endl;
}