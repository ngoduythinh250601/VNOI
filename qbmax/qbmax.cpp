#include <bits/stdc++.h>
#define oo 1000000000

using namespace std;

int m, n, a[102][102], Q[102][102];

int main()
{
    cin >> m >> n;
    //init
    for (int i = 0; i <= m + 1; i++)
        for (int j = 1; j <= n; j++)
            Q[i][j] = -oo;
    for (int i = 1; i <= m; i++)
        Q[i][0] = 0;
    //read
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    //calculate
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= m; i++)
            Q[i][j] = max(Q[i - 1][j - 1], max(Q[i][j - 1], Q[i + 1][j - 1])) + a[i][j];
    int result = -oo;
    for (int i = 1; i <= m; i++)
        result = max(Q[i][n], result);
    cout << result;
    return 0;
}