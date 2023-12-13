#include <bits/stdc++.h>
#include <math.h>

#define ll long long

using namespace std;

double quadrant(double x, double y)
{
    if (x > 0)
    {
        if (y >= 0)
            return atan(abs(y) / abs(x));
        else
            return 2 * M_PI - atan(abs(y) / abs(x));
    }
    else if (x == 0)
    {
        if (y >= 0)
            return M_PI / 2;
        else
            return M_PI / 2 + M_PI;
    }
    else
    {
        if (y >= 0)
            return M_PI - atan(abs(y) / abs(x));
        else
            return M_PI + atan(abs(y) / abs(x));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cout << setprecision(8);
    double ans = abs(quadrant(x1, y1) - quadrant(x2, y2));
    cout << (ans <= M_PI ? ans : 2*M_PI - ans);
    return 0;
}