#include <iostream>
using namespace std;

int main(){
    double n,h,x,m,y;
    cin >> n >> h >> x >> m >> y;

    double work_hour = (n*h*y)/(x*m);
    cout << work_hour << endl;
    return 0;
}