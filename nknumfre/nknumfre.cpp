#include <bits/stdc++.h>
#define MAX 200000

bool prime[MAX + 1];

int rvs(int x){
    int rvs_x = 0;
    while (x > 0) {
        rvs_x = rvs_x * 10 + (x % 10);
        x = x / 10;
    }
    return rvs_x;
}

int GCD(int x, int y)
{
    int r = x % y;
    while (r > 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{
    int a, b;
    int result = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
        if (GCD(i, rvs(i)) == 1)
            result++;
    printf("%d", result);
    return 0;
}