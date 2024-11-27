#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
const int size_ = 108;
int n, m;
char mp[size_][size_];
bool vis[size_][size_];
struct pos
{
    int x, y;
} positions[size_];
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool judge(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
void bfs(int sx, int sy)
{
    pos fir;
    fir.x = sx, fir.y = sy;
    vis[sx][sy] = true;
    queue<pos> q;
    q.push(fir);
    while (!q.empty())
    {
        pos t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int tx = t.x + dx[i];
            int ty = t.y + dy[i];
            if (judge(tx, ty) && !vis[tx][ty] && mp[tx][ty] == '@')
            {
                vis[tx][ty] = true;
                pos tmp;
                tmp.x = tx, tmp.y = ty;
                q.push(tmp);
            }
        }
    }
}
int main()
{
    while (cin >> n >> m)
    {
        if(m == 0)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mp[i][j];
            }
        }
        int count = 0;
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mp[i][j] == '@' && !vis[i][j])
                {
                    bfs(i, j);
                    count++;
                }
            }
        }
        cout << count << std::endl;
    }
    return 0;
}