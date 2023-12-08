#include <bits/stdc++.h>

using namespace std;

#define TASK "LABUDOVI"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define forU(i,a,b) for (int i = a; i<=b; i++)

struct gan
{
    int x,y;
};

int m,n;
gan a[1];
string s[1500];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r",stdin);
        freopen(output_file, "w",stdout);
    #endif // ONLINE_JUDGE
    cin >>m >>n;
    int dem = -1;
    forU(i,0,m-1) cin >>s[i];
    forU(i,0,m-1) forU(j,0,n-1)
    {
        if (s[i][j] == 'L')
        {
            dem++;
            a[dem].x = i;
            a[dem].y = j;
        }
    }

    return(0);
}
