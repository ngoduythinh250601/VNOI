#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define oo 1e18

using namespace std;

int m, n, col[1002][1002];

int biggestRect(int mm, int nn)
{
    int ans = 0;
    stack<ii> st;
    st.push({0, 0});
    for (int i = 1; i <= mm; i++)
    {
        for (int j = 1; j <= nn + 1; j++)
        {
            int pos = j;
            while (st.top().first > col[i][j])
            {
                pos = st.top().second;
                ans = max(ans, st.top().first * (j - pos));
                st.pop();
            }
            if (st.top().first < col[i][j])
                st.push({col[i][j], pos});
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n;
    int val;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> val;
            col[i][j] = val ? col[i - 1][j] + 1 : 0;
        }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << col[i][j] << " ";
        cout << endl;
    }
    cout << biggestRect(m, n);
}

/*
3 4
0 1 0 1
0 1 1 1
0 0 0 0
*/