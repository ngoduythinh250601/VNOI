#include <bits/stdc++.h>
#define modulo 14062008

using namespace std;

int n,k,Q[100001];
bool broken[100001];

int main(){
    cin >> n >> k;
    int pos;
    for (int i = 1; i <= k; i++) {
        cin >> pos;
        broken[pos] = true;
    }
    Q[0] = 0;
    Q[1] = 1;
    for (int i = 2; i <= n; i++) if (broken[i] == false) Q[i] = (Q[i-1] + Q[i-2]) % modulo;
    cout << Q[n];
    return 0;
}