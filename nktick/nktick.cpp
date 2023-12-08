#include <bits/stdc++.h>

using namespace std;

int n,t[60001],r[60001],Q[60001];

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i < n; i++) cin >> r[i];
    Q[0] = 0;
    Q[1] = t[1]; 
    for (int i = 2; i <= n; i++) {
        Q[i] = min(Q[i-1] + t[i], Q[i-2] + r[i-1]);
    }
    cout << Q[n];
    return 0;
}