#include <cstdio>
#include <iostream>
#include <queue>
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 1, -1, 0, 0};
int a, b, c;
int retime;
int maze[100][100][100];
bool vis[100][100][100] = {{{0}}};
struct pos
{
    int x;
    int y;
    int z;
    int time;
};
int ans;
std::queue<pos> que;
bool judge(int x, int y, int z)
{
    return (x < a && y < b && z < c && x >= 0 && y >= 0 && z >= 0);
}
void bfs(int x, int y, int z)
{
    pos p1 = {x, y, z, 0};
    vis[x][y][z] = true;
    que.push(p1);
    while (!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        if (p2.x == a - 1 && p2.y == b - 1 && p2.z == c - 1)
        {
            ans = p2.time;
            return;
        }
        for (int i = 0; i != 6; i++)
        {
            int x_n = p2.x + dx[i];
            int y_n = p2.y + dy[i];
            int z_n = p2.z + dz[i];
            if (vis[x_n][y_n][z_n] == false && judge(x_n, y_n, z_n) && maze[x_n][y_n][z_n] == 0)
            {
                vis[x_n][y_n][z_n] = true;
                pos p3 = {x_n, y_n, z_n, p2.time + 1};
                que.push(p3);
            }
        }
    }
}
int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i != k; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &retime);
        for (int i = 0; i != a; i++)
        {
            for (int j = 0; j != b; j++)
            {
                for (int k = 0; k != c; k++)
                {
                    scanf("%d", &maze[i][j][k]);
                    vis[i][j][k] = false;
                }
            }
        }
        bfs(0, 0, 0);
        std::cout << (ans <= retime ? ans : -1) << std::endl;
        ans = 0;
    }
    return 0;
}