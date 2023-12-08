#include <bits/stdc++.h>

using namespace std;

int T, n[100001], a[100001], biggest[100001];

int main()
{
    a[0] = 0;
    a[1] = 1;
    biggest[1] = 1;
    for (int i = 2; i <= 100000; i++)
    {
        if (i % 2 == 0)
            a[i] = a[i / 2];
        else
            a[i] = a[i / 2] + a[i / 2 + 1];
        biggest[i] = max(biggest[i - 1], a[i]);
    }
    cin >> T;
    for (int i = 1; i <= T; i++)
        cin >> n[i];
    for (int i = 1; i <= T; i++)
        cout << biggest[n[i]] << "\n";
    return 0;
}