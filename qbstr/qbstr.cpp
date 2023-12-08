#include <bits/stdc++.h>

using namespace std;

string a,b;
int n,m,dd[2001][2001];

int main(){
    cin >> a >> b;
    n = a.length();
    m = b.length();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            dd[i][j] = max(dd[i][j-1],dd[i-1][j]);
            if (a[i-1] == b[j-1])
                dd[i][j] = max(dd[i][j], dd[i-1][j-1] + 1);
        }
    cout << dd[n][m];
}