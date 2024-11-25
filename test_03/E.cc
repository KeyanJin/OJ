#include <iostream>
#include <queue>
const int size = 1500 + 100;
int N, M;
bool avai[size][size];
char maze[size][size];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct pos
{
    int x;
    int y;
};
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
        if (p2.x > N || p2.y > M)
        {
            std::cout << "Yes" << std::endl;
            return;
        }
        for (int i = 0; i != 4; i++)
        {
            int x_n = p2.x + dx[i];
            int y_n = p2.y + dy[i];
            if (avai[x_n][y_n] == true && x_n >= 0 && y_n >= 0)
            {
                avai[x_n][y_n] = false;
                pos p3 = {x = x_n, y = y_n};
                que.push(p3);
            }
        }
    }
    std::cout << "No" << std::endl;
}
int main()
{
    while (std::cin >> N >> M)
    {
        int start_x, strat_y;
        for (int i = 0; i != size; i++)
        {
            for (int j = 0; j != size; j++)
            {
                avai[i][j] = true;
            }
        }
        for (int i = 0; i != N; i++)
        {
            for (int j = 0; j != M; j++)
            {
                std::cin >> maze[i][j];
                if (maze[i][j] == '#')
                {
                    avai[i][j] = false;
                }
                if (maze[i][j] == 'S')
                {
                    start_x = i;
                    strat_y = j;
                }
            }
        }
        bfs(start_x, strat_y);
    }
    return 0;
}
