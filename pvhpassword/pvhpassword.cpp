#include <bits/stdc++.h>
#define MAX_LENGTH 100

using namespace std;

string S;
int key;
int total = 0;

int trans(char x){
    return (int(x) + key - int('a')) % 26;
}

int main()
{
    cin >> S >> key;
    for (int i = 0; i < S.length(); i++) total += trans(S[i]);
    cout << total;
    return 0;
}