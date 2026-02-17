#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    cin >> n;
    vector<vector<string>> list_segments;

    vector<string> dir;
    for(long i = 0; i < n; i++) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string segment;
        vector<string> list;
        while (getline(ss,segment,' ')){
            list.push_back(segment);
        }
        list_segments.push_back(list);
    }

    set<string> files;
    for(long i = 0; i < n; i++) {
        if(list_segments[i][0] == "cd") {
            if(list_segments[i][1] == "..") {
                if(dir.size()){
                    dir.pop_back();
                }
            }
            else {
                dir.push_back(list_segments[i][1]);
            }
        }
        else if(list_segments[i][0] == "nano") {
            string filename = "";
            if(dir.size() > 0){
                for(long j = 0; j < dir.size(); j++) {
                    filename += dir[j] + "/";
                }
                filename += list_segments[i][1];
            }
            else {
                filename = list_segments[i][1];
            }
            files.insert(filename); 
        }
    }

    for(auto it = files.begin(); it != files.end(); it++) {
        cout << "git add " << *it << endl;
    }

    cout << "git commit\ngit push" << endl;
    return 0;
}