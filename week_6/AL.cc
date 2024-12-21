// #include <algorithm>
// #include <cstring>
// #include <iostream>

// const int SIZE = 1001;
// int maze[SIZE][SIZE];
// bool vis[SIZE][SIZE];
// int dx[] = {0, 0, -1, 1};
// int dy[] = {1, -1, 0, 0};

// bool judge(int x, int y, int n, int m)
// {
//     return (x >= 0 && x < n && y >= 0 && y < m);
// }

// int dfs(int x, int y, int n, int m, int depth)
// {
//     if (!judge(x, y, n, m) || maze[x][y] < depth)
//     {
//         return 0;
//     }
//     if (vis[x][y])
//         return 0;
//     vis[x][y] = true;
//     int volume = depth;
//     for (int i = 0; i < 4; i++)
//     {
//         int x_ = x + dx[i];
//         int y_ = y + dy[i];
//         if(maze[x_][y_] != 0 && judge(x_, y_,n,m) && vis[x_][y_] == false)
//         {
//             volume += dfs(x_, y_, n, m, maze[x_][y_]);
//         }
//     }
//     return volume;
// }

// int main()
// {
//     int t;
//     std::std::cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         int n, m;
//         std::std::cin >> n >> m;
//         memset(vis, false, sizeof(vis));
//         for (int j = 0; j < n; j++)
//         {
//             for (int k = 0; k < m; k++)
//             {
//                 std::std::cin >> maze[j][k];
//             }
//         }
//         int std::max_volume = 0;
//         for (int k = 0; k < n; k++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (maze[k][j] != 0)
//                 {
//                     memset(vis, false, sizeof(vis));
//                     int volume = dfs(k, j, n, m, maze[k][j]);
//                     std::max_volume = std::std::max(std::max_volume, volume);
//                 }
//             }
//         }
//         std::std::cout << std::max_volume << std::std::endl;
//     }
//     return 0;
// }

#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
const int N = 1005;
int n, m;
int jump[4][4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int g[N][N];                                       
bool vis[N][N];
int ans;
int bfs(int x, int y)
{
    std::queue<std::pair<int, int>> q;
    q.push({x, y});
    int res = g[x][y];
    while (!q.empty())
    {
        std::pair<int, int> t = q.front();
        q.pop();
        int tx = t.first;
        int ty = t.second;
        for (int i = 0; i < 4; i++)
        {
            int X = tx + jump[i][0];
            int Y = ty + jump[i][1];
            if (!vis[X][Y] && X >= 1 && X <= n && Y <= m && Y >= 1 && g[X][Y] != 0)
            {
                vis[X][Y] = true;
                q.push({X, Y});
                res += g[X][Y]; 
            }
        }
    }
    return res;
}
int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                std::cin >> g[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] != 0)
                {
                    vis[i][j] = true;
                    int res = bfs(i, j);
                    ans = std::max(ans, res); 
                }
            }
        }
        std::cout << ans << std::endl;
        memset(vis, false, sizeof(vis)); 
    }

    return 0;
}