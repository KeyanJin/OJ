#include <cstring>
#include <iostream>
#include <queue>
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
int ans = -1;
struct pos
{
    int x;
    int y;
    int steps;
};
char maze[310][310];
bool vis[310][310];
std::queue<pos> que;

bool judge(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}
void bfs(int start_x, int start_y)
{
    vis[start_x][start_y] = true;
    pos p1 = {start_x, start_y, 0};
    que.push(p1);
    while (!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        if (maze[p2.x][p2.y] == '=')
        {
            ans = p2.steps;
            return;
        }
        for (int i = 0; i != 4; i++)
        {
            int x_ = p2.x + dx[i];
            int y_ = p2.y + dy[i];
            if (vis[x_][y_] == false && judge(x_, y_))
            {
                vis[x_][y_] = true;
                if (maze[x_][y_] == '.' || maze[x_][y_] == '=')
                {
                    pos p3 = {x_, y_, p2.steps + 1};
                    que.push(p3);
                }
                else if (isLetter(maze[x_][y_]))
                {
                    for (int k = 0; k != n; k++)
                    {
                        for (int l = 0; l != m; l++)
                        {
                            if (k == x_ && l == y_)
                            {
                                continue;
                            }
                            else if (maze[k][l] == maze[x_][y_])
                            {
                                pos p3 = {k, l, p2.steps + 1};
                                que.push(p3);
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int start_x,start_y;
    std::cin >> n >> m;
    memset(vis, false, sizeof vis);
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != m; j++)
        {
            std::cin >> maze[i][j];
            if (maze[i][j] == '#')
            {
                vis[i][j] = true;
            }
            if(maze[i][j] == '@')
            {
                start_x = i;
                start_y = j;
            }
        }
    }
    bfs(start_x,start_y);
    std::cout << ans;
    return 0;
}