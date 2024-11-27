
#include <cstring>
#include <iostream>
int n, k;
const int size = 1e2 + 1;
char chessp[size][size];
int ans;
bool line[size];
void dfs(int row, int count)
{
    if (count == k)
    {
        ans++;
        return;
    }
    if (row > n - 1)
    {
        return;
    }
    for (int i = 0; i != n; i++)
    {
        if (line[i] == false && chessp[row][i] == '#')
        {
            line[i] = true;
            dfs(row + 1, count + 1);
            line[i] = false;
        }
    }
    dfs(row + 1, count);
}

int main()
{
    for (; std::cin >> n >> k;)
    {
        ans = 0;
        if (n == -1 && k == -1)
        {
            return 0;
        }
        memset(line, false, sizeof line);
        for (int i = 0; i != n; i++)
        {
            for (int j = 0; j != n; j++)
            {
                std::cin >> chessp[i][j];
            }
        }
        dfs(0, 0);
        std::cout << ans << std::endl;
    }
    return 0;
}