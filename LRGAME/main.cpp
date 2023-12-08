#include <bits/stdc++.h>

using namespace std;

#define TASK "vd1"
#define input_file TASK".inp"
#define output_file TASK".out"

#define forU(i,a,b) for (int i=a; i<=b; i++)

int nmax = 1000;
int a[nmax],n;

void doc()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
}

void process()
{
    int x = 4;
    int y = 5;
    int z = x + y;
    cout <<z <<endl;
    for (int i=1; i<=n; i++)
        if (a[i] == 2 || i <= 3)cout <<a[i] <<endl;
        else
        {
            cout <<a[i] <<endl;
        }
}

int main()
{
    doc();
    process();
}
