#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int nmax = 10000 + 5, MOD = 1000000000;
int adj[nmax],n,k,f[nmax][10];

void doc()
{
    cin >>n >>k;
    for (int i=1; i<=n; i++)
    {
        cin>>adj[i];
        adj[i]=n+1-adj[i];
    }
}

void solve()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=k; j++)
        {

        }
}

void print()
{
    cout<<n<<endl;
}

int main()
{
    doc();
    print();
}
