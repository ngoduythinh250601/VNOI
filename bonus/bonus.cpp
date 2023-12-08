#include <bits/stdc++.h>

using namespace std;

int n, k, total, T[1002][1002];

int main()
{
    cin >> n >> k;
    int read_int;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> read_int;
            T[i][j] = T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1] + read_int;
        }
    for (int i = 0; i <= n - k; i++)
        for (int j = 0; j <= n - k; j++)
            total = max(total, T[i + k][j + k] - T[i + k][j] - T[i][j + k] + T[i][j]);
    cout << total;
    return 0;
}