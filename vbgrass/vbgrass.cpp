#include <bits/stdc++.h>

using namespace std;

int r, c, total;
bool grass[102][102], dd[102][102];
char read_char;
int addx[4] = {0, 1, 0, -1};
int addy[4] = {1, 0, -1, 0};

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            cin >> read_char;
            if (read_char == '#')
                grass[i][j] = true;
        }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (grass[i][j])
            {
                if (dd[i][j] == false)
                {
                    dd[i][j] = true;
                    total++;
                    for (int k = 0; k < 4; k++)
                    {
                        if (grass[i + addx[k]][j + addy[k]])
                        {
                            dd[i + addx[k]][j + addy[k]] = true;
                        }
                    }
                }
            }
    cout << total;
    return 0;
}