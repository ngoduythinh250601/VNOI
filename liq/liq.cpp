#include <bits/stdc++.h>

using namespace std;

int n, A[1001], Q[1001], result;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        Q[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) Q[i] = max(Q[i], Q[j] + 1);
        }
        result = max(result, Q[i]);
    }
    cout << result;
    return 0;
}