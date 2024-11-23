#include <iostream>
#include <queue>
#include <vector>
int n;
const int size = 30;
int matrix[size][size];
bool availalbe[size][size];
typedef struct point
{
    int x;
    int y;
} point;
std::queue<point> points;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool judge(int x, int y)
{
    if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1)
    {
        return true;
    }
    return false;
}
void bfs(int x, int y)
{
    std::vector<point> ps;
    point temp;
    temp.x = x;
    temp.y = y;
    points.push(temp);
    ps.push_back(temp);
    while (!points.empty())
    {
        point p1 = points.front();
        points.pop();
        for (int i = 0; i != 4; i++)
        {
            if (p1.x == 0 || p1.y == 0 || p1.x == n - 1 || p1.y == n - 1)
            {
                availalbe[p1.x][p1.y] = false;
                return;
            }
            int n_x = p1.x + dx[i];
            int n_y = p1.y + dy[i];
            if (judge(n_x, n_y) && availalbe[n_x][n_y] == true && matrix[n_x][n_y] == 0)
            {
                availalbe[n_x][n_y] = false;
                point p2;
                p2.x = n_x;
                p2.y = n_y;
                points.push(p2);
                ps.push_back(p2);
            }
        }
    }
    for (auto i : ps)
    {
        matrix[i.x][i.y] = 2;
    }
}
int main()
{
    std::cin >> n;
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            availalbe[i][j] = true;
        }
    }
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            if (matrix[i][j] == 1)
            {
                availalbe[i][j] = false;
            }
        }
    }
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            if (matrix[i][j] == 0 && availalbe[i][j] == true)
            {
                availalbe[i][j] = false;
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i != n; i++)
    {
        for (int j = 0; j != n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}