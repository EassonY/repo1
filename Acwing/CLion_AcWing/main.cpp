#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 20;

int n;
int g[N][N];
bool row[N], col[N], dg[N], udg[N];

void bfs(int x, int y, int s)
{
    if (y == n) y = 0, x ++;
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i ++) puts(g[i]);
            puts("");
        }
        return;
    }
    //不放皇后
    bfs(x, y + 1, s);

    //放皇后
    if(!row[x] && !col[y] && !dg[x + y] && !udg[n - x + y])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n - x + y] = true;
        bfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[n - x + y] = false;
        g[x][y] = '.';
    }


}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            g[i][j] = '.';
    bfs(0, 0, 0);


    return 0;
}
