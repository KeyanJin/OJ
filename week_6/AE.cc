#include <cstring>
#include <iostream>
#include <queue>
const int SIZE = 41;
const int INF = 1e5;
int n, m, j;
char maze[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct Position
{
    int x;
    int y;
    int hurt; // 遇到的尖刺的次数
};
std::queue<Position> que;
bool judge(int x, int y)
{
    return (x < n && y < m && x >= 0 && y >= 0);
}
int seek_treasue(int start_x, int start_y, int treasure_x, int treasure_y)
{
    Position p1 = {start_x, start_y, 0};
    que.push(p1);
    vis[start_x][start_y] = true;
    while (!que.empty())
    {
        Position p2 = que.front();
        que.pop();
        if (p2.x == treasure_x && p2.y == treasure_y)
        {
            return p2.hurt;
        }
        for (int i = 0; i < 4; i++)
        {
            int x_ = p2.x + dx[i];
            int y_ = p2.y + dy[i];
            if (judge(x_, y_) && vis[x_][y_] == false && maze[x_][y_] != '#')
            {
                vis[x_][y_] = true;
                int hurt_count = p2.hurt;
                if (maze[x_][y_] == 's')
                {
                    hurt_count++;
                }
                Position p3 = {x_, y_, hurt_count};
                que.push(p3);
            }
        }
    }
    return INF;
}
int main()
{
    memset(vis, false, sizeof(vis));
    std::cin >> n >> m >> j;
    int start_x, start_y, treasure_x, treasure_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> maze[i][j];
            if (maze[i][j] == '@')
            {
                start_x = i;
                start_y = j;
            }
            if (maze[i][j] == 'x')
            {
                treasure_x = i;
                treasure_y = j;
            }
        }
    }
    int ans = seek_treasue(start_x, start_y, treasure_x, treasure_y);
    if (ans * 2 <= j)
    {
        std::cout << "SUCCESS" << std::endl;
    }
    else
    {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    return 0;
}