// M - Lake Counting S
#include <cstring>
#include <iostream>
#include <queue>
typedef struct point
{
    int x;
    int y;
} point;
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, 0, -1, 1, 0, -1, 1, -1};
bool available[200][200];
char field[200][200];
int ans = 0;
std::queue<point> m_que;
void bfs(int x, int y)
{
    point temp;
    temp.x = x;
    temp.y = y;
    m_que.push(temp);
    while (!m_que.empty())
    {
        point p = m_que.front();
        m_que.pop();
        for (int i = 0; i != 8; i++)
        {
            int n_x = p.x + dx[i];
            int n_y = p.y + dy[i];
            if (available[n_x][n_y] == true && field[n_x][n_y] == 'W')
            {
                available[n_x][n_y] = false;
                point p2;
                p2.x = n_x;
                p2.y = n_y;
                m_que.push(p2);
            }
        }
    }
}
int main()
{
    int N, M;
    std::cin >> N >> M;
    memset(available, 0, sizeof available);
    for (int i = 0; i != N; i++)
    {
        for (int j = 0; j != M; j++)
        {
            available[i][j] = true;
            std::cin >> field[i][j];
        }
    }
    for (int i = 0; i != N; i++)
    {
        for (int j = 0; j != M; j++)
        {
            if (field[i][j] == 'W' && available[i][j] == true)
            {
                available[i][j] = false;
                bfs(i, j);
                ans++;
            }
        }
    }
    std::cout << ans;
    return 0;
}