#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    cout<<s;

    long T=0,H=0;
    
    for(size_t i=0; i<s.length(); i++){
        if(s[i]=='T'){
            T+=1;
        }
        if(s[i]=='H'){
            H+=1;
        }
    }
    cout<<T<<"-"<<H;
}
