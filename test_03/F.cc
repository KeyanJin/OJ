// #include <algorithm>
// #include <iostream>
// int HP = 6;
// int n, m;
// int home_x, home_y;
// int dx[] = {0, 0, -1, 1};
// int dy[] = {1, -1, 0, 0};

// int maze[11][11];
// bool avail[11][11];
// int min_time = 1000000000;
// int ans = min_time;
// bool judge(int x, int y)
// {
//     if (x >= 1 && x <= n && y >= 1 && y <= m)
//     {
//         return true;
//     }
//     return false;
// }
// void dfs(int x, int y, int time, int HP)
// {
//     if (HP == 0)
//     {
//         return;
//     }
//     if (x == home_x && y == home_y)
//     {
//         int ans = std::min(min_time, time);
//         return;
//     }
//     else
//     {
//         for (int i = 0; i != 4; i++)
//         {
//             int x_n = x + dx[i];
//             int y_n = y + dy[i];
//             HP--;
//             if (HP == 0)
//             {
//                 return;
//             }
//             if (judge(x_n, y_n) && avail[x_n][y_n] == true)
//             {
//                 if (maze[x_n][y_n] == 4)
//                 {
//                     HP = 6;
//                 }
//                 avail[x_n][y_n] = false;
//                 HP--;
//                 dfs(x_n, y_n, time + 1,HP);
//                 HP++;
//                 avail[x_n][y_n] = false;
//             }
//         }
//     }
// }
// int main()
// {
//     int s_x,s_y;
//     std::cin >> n >> m;
//     for(int i = 1;i <= n;i++)
//     {
//         for(int j = 1;j <= m;j++)
//         {
//             avail[i][j] = true;
//         }
//     }
//     for(int i = 1;i <= n;i++)
//     {
//         for(int j = 1;j <= m;j++)
//         {
//             std::cin >> maze[i][j];
//             if(maze[i][j] == 0)
//             {
//                 maze[i][j] = false;
//             }
//             if(maze[i][j] == 2)
//             {
//                 s_x = i;
//                 s_y = j;
//             }
//         }
//     }
//     dfs(s_x, s_y,0, 6);
//     if(ans == min_time)
//     {
//         std::cout << -1;
//     }
//     else {
//         std::cout << ans;
//     }
// }
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

// 定义四个方向，分别是上、下、左、右
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS函数
int bfs(const vector<vector<int>>& grid, int n, int m) {
    // 定义起点和终点
    int startX, startY, endX, endY;

    // 先找到起点和终点的坐标
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 3) {
                endX = i;
                endY = j;
            }
        }
    }

    // 初始化队列，保存状态（x, y, currentHP）
    queue<tuple<int, int, int>> q;
    q.push({startX, startY, 6});  // 从起点出发，血量为66

    // 访问记录（访问过的格子和血量状态）
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(7, false)));

    // 设置起点为已访问
    visited[startX][startY][6] = true;

    // 步数计数
    int steps = 0;

    // 开始BFS
    while (!q.empty()) {
        int size = q.size();
        
        // 当前层的每一个节点
        for (int i = 0; i < size; ++i) {
            auto [x, y, hp] = q.front();
            q.pop();

            // 如果到达终点
            if (x == endX && y == endY) {
                return steps;
            }

            // 遍历四个方向
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // 检查是否越界
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                // 检查是否是障碍物
                if (grid[nx][ny] == 0) continue;

                // 计算新血量
                int newHP = hp - 1;
                if (grid[nx][ny] == 4) {
                    newHP = 6;  // 如果是鼠标格，血量恢复为66
                }

                // 如果新血量小于0或已经访问过该格子就跳过
                if (newHP < 0 || visited[nx][ny][newHP]) continue;

                // 标记为已访问
                visited[nx][ny][newHP] = true;

                // 将新状态加入队列
                q.push({nx, ny, newHP});
            }
        }

        // 步数增加
        steps++;
    }

    // 如果遍历结束仍未找到路径，返回-1
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    // 输入地图
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // 调用BFS函数
    int result = bfs(grid, n, m);
    
    // 输出结果
    cout << result << endl;

    return 0;
}
