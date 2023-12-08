#include <bits/stdc++.h>

using namespace std;

int c, n, w[17];
bool dd[5001];

int main()
{
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dd[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = c - w[i]; j >= 0; j--)
            if (dd[j])
                dd[j + w[i]] = true;
    for (int j = c; j >= 0; j--)
        if (dd[j])
        {
            cout << j;
            return 0;
        }
}