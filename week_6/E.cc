#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
const int SIZE = 301 + 10;
const int INF = 1e9;
struct Meteor
{
    int x, y;
    int time;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = INF;
int destroyed[SIZE][SIZE];
bool vis[SIZE][SIZE];
struct pos
{
    int x, y;
    int steps;
};
std::queue<pos> que;
bool judge(int x, int y)
{
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}
void bfs()
{
    vis[0][0] = true;
    pos p1 = {0, 0, 0};
    que.push(p1);
    while (!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        if (destroyed[p2.x][p2.y] == INF)
        {
            ans = p2.steps;
            return;
        }
        for (int i = 0; i != 4; i++)
        {
            int x_ = p2.x + dx[i];
            int y_ = p2.y + dy[i];
            if (judge(x_, y_) && destroyed[x_][y_] - 1 > p2.steps && vis[x_][y_] == false)
            {
                vis[x_][y_] = true;
                pos p3 = {x_, y_, p2.steps + 1};
                que.push(p3);
            }
        }
    }
}
int main()
{
    int M;
    std::cin >> M;
    memset(vis, false, sizeof vis);
    for (int i = 0; i != SIZE; i++)
    {
        for (int j = 0; j != SIZE; j++)
        {
            destroyed[i][j] = INF;
        }
    }
    for (int i = 0; i != M; i++)
    {
        int x, y, time;
        std::cin >> x >> y >> time;
        destroyed[x][y] = std::min(destroyed[x][y], time);
        for (int i = 0; i != 4; i++)
        {
            int x_ = x + dx[i];
            int y_ = y + dy[i];
            if (judge(x_, y_))
            {
                // destroyed[x_][y_] = std::min(destroyed[x][y],destroyed[x_][y_]);
                // 假设一个陨石没有被砸，但旁边的陨石被砸中之前就被砸过，那么这个语句就是错误的
                destroyed[x_][y_] = std::min(time, destroyed[x_][y_]);
            }
        }
    }
    bfs();
    if (ans == INF)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << ans;
    }
    return 0;
}