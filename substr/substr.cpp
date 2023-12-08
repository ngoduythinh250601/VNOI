#include <bits/stdc++.h>

using namespace std;

#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ii pair<int, int>

string a, b;
int z[2000005];

void Z_function(string s)
{
    int n = s.length();
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        else
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int main()
{
    FIO;
    cin >> a >> b;
    Z_function(b + a);
    int na = a.length(), nb = b.length();
    for (int i = nb; i < na + nb; i++)
        if (z[i] >= nb)
            cout << i - nb + 1 << " ";
}