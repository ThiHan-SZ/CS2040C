#include <bits/stdc++.h>
using namespace std;


int main() {
    string input;
    getline(cin, input);
    stack<char> s;
    bool failed = false;
    for(size_t i = 0; i < input.length(); i++){
        if (input[i] == '.'){
            continue;
        }
        if(input[i] == 'p' || input[i] == 'g' || input[i] == 'o'){
            s.push(input[i]);
        }
        else{
            while(s.size() > 0  && s.top() != tolower(input[i])){
                s.pop();
            }
            if(s.size() == 0){
                failed = true;
            }
            if(s.size() > 0 && s.top() == tolower(input[i])){
                s.pop();
            }
        }
    }

    //count the remaining items
    int pcount = 0, gcount = 0, ocount = 0;
    while(!s.empty()){
        if(s.top() == 'p'){
            pcount++;
        }
        else if(s.top() == 'g'){
            gcount++;
        }
        else if(s.top() == 'o'){
            ocount++;
        }
        s.pop();
    }

    if(failed){
        cout << "Neibb" << endl;
        return 0;
    }

    cout << pcount << endl;
    cout << gcount << endl;
    cout << ocount << endl;

    return 0;
}
