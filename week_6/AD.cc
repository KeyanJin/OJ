#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>


using namespace std;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Cell
{
    int x, y, height;
    Cell(int x, int y, int height) : x(x), y(y), height(height)
    {
    }
    bool operator>(const Cell &other) const
    {
        return height > other.height;
    }
};

int maxWaterVolume(int n, int m, const vector<vector<int>> &grid)
{
    if (n == 0 || m == 0)
        return 0;

    priority_queue<Cell, vector<Cell>, greater<Cell> > pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> water(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                pq.push(Cell(i, j, grid[i][j]));
                visited[i][j] = true;
            }
        }
    }

    int totalWater = 0;


    while (!pq.empty())
    {
        Cell current = pq.top();
        pq.pop();

        for (int d = 0; d < 4; ++d)
        {
            int nx = current.x + dx[d];
            int ny = current.y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny])
            {
                visited[nx][ny] = true;


                if (grid[nx][ny] < current.height)
                {
                    totalWater += current.height - grid[nx][ny];
                }


                pq.push(Cell(nx, ny, max(grid[nx][ny], current.height)));
            }
        }
    }

    return totalWater;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        if (t != 0)
            cin.ignore();

        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));


        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> grid[i][j];
            }
        }

        cout << maxWaterVolume(n, m, grid) << endl;
    }

    return 0;
}
