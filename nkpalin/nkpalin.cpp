#include <bits/stdc++.h>

using namespace std;

string s;
int n, dd[2001][2001], trace[2001][2001];

string get_result(int x, int y, int max)
{
    string result = "";
    while (x <= y)
    {
        if (trace[x][y] == 0)
        {
            result = result + s[x];
            x++;
            y--;
        }
        else if (trace[x][y] == -1)
            x++;
        else
            y--;
    }
    string rsv = result;
    reverse(rsv.begin(), rsv.end());
    return (max % 2) == 0 ? (result + rsv) : result.substr(0, max / 2) + rsv;
}

int main()
{
    cin >> s;
    n = s.length();
    int j;
    for (int i = 0; i < n; i++)
        dd[i][i] = 1;
    for (int distance = 1; distance < n; distance++)
        for (int i = 0; i < n - distance; i++)
        {
            j = i + distance;
            if (dd[i + 1][j] > dd[i][j - 1])
            {
                dd[i][j] = dd[i + 1][j];
                trace[i][j] = -1;
            }
            else
            {
                dd[i][j] = dd[i][j - 1];
                trace[i][j] = 1;
            }
            if (s[i] == s[j] && dd[i + 1][j - 1] + 2 >= dd[i][j])
            {
                dd[i][j] = dd[i + 1][j - 1] + 2;
                trace[i][j] = 0;
            }
        }

    cout << get_result(0, n - 1, dd[0][n-1]);
    return 0;
}