// C - 马的遍历
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
int n, m, x, y;
int matrix[400][400];
bool vis[400][400];
typedef struct pos
{
    int x;
    int y;
    int steps;
} pos;
std::queue<pos> position;
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
bool judge(int x,int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return true;
    }
    return false;
}
void bfs(int x, int y)
{
    pos temp;
    temp.x = x;
    temp.y = y;
    temp.steps = 0;
    position.push(temp);
    while (!position.empty())
    {
        pos p1 = position.front();
        position.pop();
        for(int i = 0;i != 8;i++)
        {
            int x_n = p1.x + dx[i];
            int y_n = p1.y + dy[i];
            if(vis[x_n][y_n] == false && judge(x_n,y_n))
            {
                vis[x_n][y_n] = true;
                pos p2;
                p2.x = x_n;
                p2.y = y_n;
                p2.steps = p1.steps + 1;
                position.push(p2);
                matrix[p2.x][p2.y] = p2.steps;
            }
        }
    }
}
int main()
{
    std::cin >> n >> m >> x >> y;
    memset(vis, false, sizeof vis);
    memset(matrix, -1, sizeof matrix);
    vis[x][y] = true;
    matrix[x][y] = 0;
    bfs(x,y);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            printf("%-5d",matrix[i][j]);
        }
        std::cout << std::endl;
    }
    return 0;
}