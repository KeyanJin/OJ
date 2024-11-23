#include <iostream>
#include <queue>
#include <vector>

int n;
const int size = 30;
int matrix[size][size];
bool available[size][size];

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
    if (x >= 0 && x < n && y >= 0 && y < n)
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
        for (int i = 0; i < 4; i++)
        {
            int n_x = p1.x + dx[i];
            int n_y = p1.y + dy[i];
            if (judge(n_x, n_y) && available[n_x][n_y] == true && matrix[n_x][n_y] == 0)
            {
                available[n_x][n_y] = false;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            available[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                available[i][j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == n - 1) && matrix[i][j] == 0)
            {
                available[i][j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0 && available[i][j] == true)
            {
                available[i][j] = false;
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matrix[i][j];
            if (j < n - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}