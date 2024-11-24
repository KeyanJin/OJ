// I - 迷宫
#include <cstring>
#include <iostream>

const int size = 5;
int N, M, T;

bool maze[size + 1][size + 1];
bool vis[size + 1][size + 1];
int SX, SY, FX, FY;

int ans = 0;

typedef struct point
{
    int x;
    int y;
} point;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    if (x == FX && y == FY)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int n_x = x + dx[i];
        int n_y = y + dy[i];
        if (n_x >= 1 && n_x <= N && n_y >= 1 && n_y <= M && maze[n_x][n_y] && !vis[n_x][n_y])
        {
            vis[n_x][n_y] = true;
            dfs(n_x, n_y);
            vis[n_x][n_y] = false;
        }
    }
}

int main()
{
    std::cin >> N >> M >> T;
    std::cin >> SX >> SY >> FX >> FY;

    memset(maze, false, sizeof(maze));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            maze[i][j] = true;
        }
    }

    for (int i = 0; i < T; i++)
    {
        int x, y;
        std::cin >> x >> y;
        maze[x][y] = false;
    }

    memset(vis, false, sizeof(vis));
    vis[SX][SY] = true;
    dfs(SX, SY);

    std::cout << ans;
    return 0;
}