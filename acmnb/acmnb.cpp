#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, result = 0, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a >> b;
        result += a;
        v.push_back(b - a);
    }
    sort(v.begin(), v.end());
    cout << result + accumulate(v.begin(), v.begin() + n, 0);
    return 0;
}