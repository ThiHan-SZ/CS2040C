#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    long n,m,k;
    cin>>n>>m>>k;

    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(),arr.rend());
    long long days = 0;
    for(int i=0; i < n; i++){
        if(arr[i]*m<=k){
            days++;
        }
        else{
            cout<<":(";
            break;
        }
    }
    if (days>0){
        cout<<days;
    }
}3