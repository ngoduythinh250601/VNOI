#include <bits/stdc++.h>
#define oo 10000000

using namespace std;

int n, d[25001], connected[25001], disconnect[25001];

int main(){
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> d[i];
    for (int i = 2; i <= n; i++) 
    {
        connected[i] = oo;
        disconnect[i] = oo;
    }
    connected[2] = d[2];
    for (int i = 3; i <= n; i++) {
        connected[i] = min(connected[i-1],disconnect[i-1]) + d[i];
        disconnect[i] = connected[i-1];
    }
    cout << connected[n];
    return 0;
}