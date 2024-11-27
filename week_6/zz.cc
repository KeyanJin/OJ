#include <iostream>
#include <queue>

char maze[21][21];
int w, h;
bool avail[21][21];

struct pos
{
    int x;
    int y;
};

std::queue<pos> que;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool judge(int x, int y)
{
    return (x >= 0 && x < h && y >= 0 && y < w);
}

int bfs(int x, int y)
{
    int ans = 1;
    pos p1 = {x, y};
    que.push(p1);
    avail[x][y] = false;
    while (!que.empty())
    {
        pos p2 = que.front();
        que.pop();
        for (int i = 0; i != 4; i++)
        {
            int x_ = p2.x + dx[i];
            int y_ = p2.y + dy[i];
            if (avail[x_][y_] == true && judge(x_, y_))
            {
                pos p3 = {x_, y_};
                que.push(p3);
                avail[x_][y_] = false;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    for (; std::cin >> w >> h;)
    {
        int start_x, start_y;
        if (w == 0 && h == 0)
        {
            break;
        }
        for (int i = 0; i != h; i++)
        {
            for (int j = 0; j != w; j++)
            {
                avail[i][j] = false;
                std::cin >> maze[i][j];
                if (maze[i][j] == '.')
                {
                    avail[i][j] = true;
                }
                if (maze[i][j] == '@')
                {
                    start_x = i;
                    start_y = j;
                    avail[i][j] = true;
                }
            }
        }
        while (!que.empty())
            que.pop();
        int ans = bfs(start_x, start_y);
        std::cout << ans << std::endl;
    }
    return 0;
}