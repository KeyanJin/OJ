#include <cstring>
#include <iostream>
#include <queue>
const int size = 100;
int n, m;
bool avai[size + 100][size + 100];
char maze[size + 100][size + 100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct pos
{
    int x;
    int y;
};
bool judge(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return true;
    }
    return false;
}
std::queue<pos> que;
void bfs(int x, int y)
{
    pos p1;
    p1.x = x;
    p1.y = y;
    que.push(p1);
    while (!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        if (p2.x == n && p2.y == m)
        {
            std::cout << "Yes";
            return;
        }
        for (int i = 0; i != 4; i++)
        {
            int x_n = p2.x + dx[i];
            int y_n = p2.y + dy[i];
            if (judge(x_n, y_n) && avai[x_n][y_n] == true)
            {
                avai[x_n][y_n] = false;
                pos p3;
                p3.x = x_n;
                p3.y = y_n;
                que.push(p3);
            }
        }
    }
    std::cout << "No";
}
int main()
{
    memset(avai, false, sizeof avai);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> maze[i][j];
            if (maze[i][j] == '.')
            {
                avai[i][j] = true;
            }
        }
    }
    bfs(1, 1);
    return 0;
}
