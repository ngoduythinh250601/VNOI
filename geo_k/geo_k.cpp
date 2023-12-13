#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << setprecision(7) << sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    return 0;
}