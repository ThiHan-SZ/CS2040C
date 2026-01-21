#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums;
    int n;
    cin>>n;
    for(int i = 0; i < n; ++i){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    size_t len = nums.size();
    for(size_t i = 0; i < len; ++i){
        auto it = find(nums.begin()+i,nums.end(),nums[i]);
        if(it != nums.end()){
            nums.erase(it);
        }
        cout<<nums[i];
    }
    return 0;
}
