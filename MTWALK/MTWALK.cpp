#include <bits/stdc++.h>

using namespace std;

#define TASK "MTWALK"
#define input_file TASK".inp"
#define output_file TASK".out"

#define forU(i,a,b) for (int i=a; i<=b; i++)

int n,mx,my,a[100][100],dd[100][100];
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

bool dfs(int x, int y)
{
    dd[x][y] = 1;
    if (x == n-1 && y == n-1) return 1;
    forU(i,0,3)
    {
        int u = x + dx[i], v = y + dy[i];
        if (u >= 0 && v >= 0 && u < n && v < n && a[u][v] >= mx && a[u][v] <= my && !dd[u][v])
            if (dfs(u,v)) return 1;
    }
    return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d",&n);
    forU(i,0,n-1) forU(j,0,n-1) scanf("%d",&a[i][j]);
    int res = 1000;
    forU(i,0,a[0][0])
    {
        int L = 0, R = 120;
        while( L <= R )
        {
            int mid = (L + R)>>1;
            memset(dd,0,sizeof dd);
            mx =  i; my = i + mid;
            bool ok = dfs(0,0);
            if ( L == R)
            {
                if (!ok) L = 1000000000;
                break;
            }
            if (ok) R = mid;
                else L = mid + 1;
        }
        res = min(res,L);
    }
    printf("%d\n",res);
}
