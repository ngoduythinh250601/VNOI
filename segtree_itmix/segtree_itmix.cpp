#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>
#define vii vector<ii>
#define TR(v, i) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll MAX_N = 1e5 + 5;
const ll MOD_N = 1e9 + 7;
ll n, m;

struct Node
{
    ll lazy_add = 0;
    ll lazy_mul = 1;
    ll val = 0;
} st[MAX_N * 4 + 5];

void down(ll id, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    st[id * 2].lazy_add = (st[id * 2].lazy_add * st[id].lazy_mul + st[id].lazy_add) % MOD_N;
    st[id * 2].lazy_mul = (st[id * 2].lazy_mul * st[id].lazy_mul) % MOD_N;
    st[id * 2].val = (((mid - l + 1) * st[id].lazy_add % MOD_N) + (st[id * 2].val * st[id].lazy_mul % MOD_N)) % MOD_N;

    st[id * 2 + 1].lazy_add = (st[id * 2 + 1].lazy_add * st[id].lazy_mul + st[id].lazy_add) % MOD_N;
    st[id * 2 + 1].lazy_mul = (st[id * 2 + 1].lazy_mul * st[id].lazy_mul) % MOD_N;
    st[id * 2 + 1].val = (((r - mid) * st[id].lazy_add % MOD_N) + (st[id * 2 + 1].val * st[id].lazy_mul % MOD_N)) % MOD_N;

    st[id].lazy_add = 0;
    st[id].lazy_mul = 1;
}

void update(ll id, ll l, ll r, ll u, ll v, ll value, ll type)
{
    if (u > r || v < l)
        return;
    if (u <= l && r <= v)
    {
        Node &node = st[id];
        if (type == 1)
        {
            node.val = (node.val + (r - l + 1) * value) % MOD_N;
            node.lazy_add = (node.lazy_add + value) % MOD_N;
        }
        else if (type == 2)
        {
            node.val = (node.val * value) % MOD_N;
            node.lazy_add = (node.lazy_add * value) % MOD_N;
            node.lazy_mul = (node.lazy_mul * value) % MOD_N;
        }
        return;
    }
    ll mid = (l + r) >> 1;
    down(id, l, r);
    update(id * 2, l, mid, u, v, value, type);
    update(id * 2 + 1, mid + 1, r, u, v, value, type);
    st[id].val = (st[id * 2].val + st[id * 2 + 1].val) % MOD_N;
}

ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (u > r || v < l)
        return 0;
    if (u <= l && r <= v)
        return st[id].val;
    ll mid = (l + r) >> 1;
    down(id, l, r);
    return (get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v)) % MOD_N;
}

int main()
{
    FIO;
    cin >> n >> m;
    ll rd;
    for (int i = 1; i <= n; i++)
    {
        cin >> rd;
        update(1, 1, n, i, i, rd, 1);
    }
    ll type, u, v, x;
    for (int i = 1; i <= m; i++)
    {
        cin >> type >> u >> v;
        if (type == 4)
        {
            cout << get(1, 1, n, u, v) << "\n";
            continue;
        }
        cin >> x;
        if (type == 1)
            update(1, 1, n, u, v, x, 1);
        else if (type == 2)
            update(1, 1, n, u, v, x, 2);
        else
        {
            update(1, 1, n, u, v, 0, 2);
            update(1, 1, n, u, v, x, 1);
        }
    }
}