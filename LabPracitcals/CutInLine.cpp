#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int actions = 0;
    cin >> actions;
    vector<string> act(actions);
    for(int i = 0; i < actions; i++){
        getline(cin >> ws, act[i]);
    }
    for(int i = 0; i < n; i++){

        if(act[i].find("cut")!= string::npos){
            cout << act[i];
            char c1 = act[i][4], c2 = act[i][6];
            cout << c1 << " " << c2 << endl;
        }
        else if(act[i].find("leave")!= string::npos){
            
        }
    }

    return 0;
}