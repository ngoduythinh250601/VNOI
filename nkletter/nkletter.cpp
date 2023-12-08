#include <bits/stdc++.h>

using namespace std;

string Sb, Se;
int dup = 0;

int main(){
    cin >> Sb >> Se;
    int lb = Sb.length();
    int le = Se.length();
    for (int i = min(le, lb); i >= 1; i--){
        if (Sb.substr(lb - i, i) == Se.substr(0, i)) {
            cout << lb + le - i;
            return 0;
        }
    }
    cout << lb + le;
    return 0;
}