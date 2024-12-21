#include <iostream>

const int N = 305;
int matrix[N][N];
int n, m;
int ans = 0;

int cal_edge_sum(int x1, int y1, int x2, int y2)
{
    int sum = 0;
    for (int i = x1; i <= x2; i++)
    {
        sum += matrix[i][y1] + matrix[i][y2];
    }
    for (int i = y1; i <= y2; i++)
    {
        sum += matrix[x1][i] + matrix[x2][i];
    }
    sum -= (matrix[x1][y1] + matrix[x2][y2] + matrix[x1][y2] + matrix[x2][y1]);
    return sum;
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int l = 1; i + l - 1 <= n && j + l - 1 <= m; l++)
            {
                int sum = cal_edge_sum(i, j, i + l - 1, j + l - 1);
                ans = std::max(sum, ans);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
