#include <algorithm>
#include <iostream>
int HP = 6;
int n, m;
int home_x, home_y;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int maze[11][11];
bool avail[11][11];
int min_time = 1000000000;
int ans = min_time;
bool judge(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return true;
    }
    return false;
}
void dfs(int x, int y, int time, int HP)
{
    if (HP == 0)
    {
        return;
    }
    if (x == home_x && y == home_y)
    {
        int ans = std::min(min_time, time);
        return;
    }
    else
    {
        for (int i = 0; i != 4; i++)
        {
            int x_n = x + dx[i];
            int y_n = y + dy[i];
            HP--;
            if (HP == 0)
            {
                return;
            }
            if (judge(x_n, y_n) && avail[x_n][y_n] == true)
            {
                if (maze[x_n][y_n] == 4)
                {
                    HP = 6;
                }
                avail[x_n][y_n] = false;
                HP--;
                dfs(x_n, y_n, time + 1,HP);
                HP++;
                avail[x_n][y_n] = false;
            }
        }
    }
}
int main()
{
    int s_x,s_y;
    std::cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            avail[i][j] = true;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            std::cin >> maze[i][j];
            if(maze[i][j] == 0)
            {
                maze[i][j] = false;
            }
            if(maze[i][j] == 2)
            {
                s_x = i;
                s_y = j;
            }
        }
    }
    dfs(s_x, s_y,0, 6);
    if(ans == min_time)
    {
        std::cout << -1;
    }
    else {
        std::cout << ans;
    }
}