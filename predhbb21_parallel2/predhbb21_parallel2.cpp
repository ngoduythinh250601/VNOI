#include <bits/stdc++.h>

using namespace std;

int n, a[122], b[122];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++)
        if ((a[i] <= 1 && b[i] <= 2) || (a[i] <= 2 && b[i] <= 1))
            cout << "Yes\n";
        else
            cout << "No\n";
    return 0;
}