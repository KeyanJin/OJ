#include <iostream>
#include <queue>

char maze[31][31][31];
bool vis[31][31][31];

struct pos
{
    int x;
    int y;
    int z;
    int steps;
};

std::queue<pos> que;
int ans = -1;
int exit_x = -1, exit_y = -1, exit_z = -1;
int dx[] = {0, 0, 0, 0, -1, 1};
int dy[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 1, 0, -1, 0, 0};
int l, m, n;

bool judge(int x, int y, int z)
{
    return (x >= 0 && y >= 0 && z >= 0 && x < l && y < m && z < n);
}

void bfs(int start_x, int start_y, int start_z)
{
    vis[start_x][start_y][start_z] = true;
    pos p1 = {start_x, start_y, start_z, 0};
    que.push(p1);
    while (!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        if (p2.x == exit_x && p2.y == exit_y && p2.z == exit_z)
        {
            ans = p2.steps;
            return;
        }
        for (int i = 0; i < 6; i++)
        {
            int x_ = p2.x + dx[i];
            int y_ = p2.y + dy[i];
            int z_ = p2.z + dz[i];
            if (judge(x_, y_, z_) && !vis[x_][y_][z_])
            {
                vis[x_][y_][z_] = true;
                pos p3 = {x_, y_, z_, p2.steps + 1};
                que.push(p3);
            }
        }
    }
    ans = -1;
}

int main()
{
    for (;;)
    {
        int s_x = -1, s_y = -1, s_z = -1;
        ans = -1;
        exit_x = exit_y = exit_z = -1;
        std::cin >> l >> m >> n;
        if (l == 0 && m == 0 && n == 0)
        {
            break;
        }
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    vis[i][j][k] = false;
                    std::cin >> maze[i][j][k];
                    if (maze[i][j][k] == '#')
                    {
                        vis[i][j][k] = true;
                    }
                    else if (maze[i][j][k] == 'E')
                    {
                        exit_x = i;
                        exit_y = j;
                        exit_z = k;
                    }
                    else if (maze[i][j][k] == 'S')
                    {
                        s_x = i;
                        s_y = j;
                        s_z = k;
                    }
                }
            }
        }
        bfs(s_x, s_y, s_z);
        if (ans == -1)
        {
            std::cout << "Trapped!" << std::endl;
        }
        else
        {
            std::cout << "Escaped in " << ans << " minute(s)." << std::endl;
        }
    }
    return 0;
}