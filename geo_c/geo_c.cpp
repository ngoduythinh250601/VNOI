#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAX_N = 1e5 + 5;
ll x[MAX_N], y[MAX_N];
int n;

ll calc(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){
    return abs((x1+x2)*(y1-y2) + (x2+x3)*(y2-y3) + (x3+x1)*(y3-y1));
}

int main(){
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 2; i < n; i++)
        ans += calc(x[0], y[0], x[i], y[i], x[i-1], y[i-1]);
    if (ans < 0) ans = -ans;
    if (ans % 2 == 0){
        cout << ans / 2;
    } else {
        cout << ans / 2 << ".5";
    }
    return 0;
}