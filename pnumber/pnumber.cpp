#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

bool prime[MAX + 1];

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = 2; i <= MAX; i++)
        prime[i] = true;
    for (int i = 2; i <= int(sqrt(MAX)); i++)
        if (prime[i])
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = false;
    for (int i = a; i <= b; i++)
        if (prime[i] == true)
            printf("%d\n", i);
    return 0;
}