#include <bits/stdc++.h>

using namespace std;

int l, r, result;

bool check(int x)
{
    int total = 0;
    for (int i = 2; i <= int(sqrt(x)); i++)
        if (x % i == 0)
            total = total + i + (x / i);
    if (int(sqrt(x)) * int(sqrt(x)) == x)
        total -= int(sqrt(x));
    return total + 1 > x;
}

int main()
{
    cin >> l >> r;
    for (int i = l; i <= r; i++)
        if (check(i))
            result++;
    cout << result;
}