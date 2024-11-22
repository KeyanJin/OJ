#include <iostream>

int n;
const int size = 100;
char letters[size + 1][size + 1];
char ans[size + 1][size + 1];
char arr[] = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, -1, 1, 0, -1, 1};

bool dfs(int x, int y, int flag, int direction) 
{
    if (flag == 7) 
    {
        return true;
    }
    int n_x = x + dx[direction];
    int n_y = y + dy[direction];

    if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < n && letters[n_x][n_y] == arr[flag]) 
    {
        if (dfs(n_x, n_y, flag + 1, direction)) 
        {
            ans[n_x][n_y] = arr[flag];
            return true;
        }
    }
    return false;
}
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            ans[i][j] = '*';
        }
    }
    for (int i = 0; i < n; i++) 
    {
        std::cin >> letters[i];
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (letters[i][j] == 'y') 
            {
                for (int k = 0; k < 8; k++) 
                {
                    if (dfs(i, j, 1, k)) 
                    {
                        ans[i][j] = 'y';
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            std::cout << ans[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
}