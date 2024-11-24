// D - 奇怪的电梯
#include <iostream>
#include <queue>
const int size = 200;
typedef struct fl
{
    int floor;
    int steps;
} fl;
int up_down[size + 1];
int ans = 0;
bool vis[size + 1];
int N, A, B;
std::queue<fl> m_que;
void bfs()
{
    vis[A] = true;
    fl temp;
    temp.floor = A;
    temp.steps = 0;
    m_que.push(temp);
    while (!m_que.empty())
    {
        fl fir = m_que.front();
        m_que.pop();
        if (fir.floor == B)
        {
            ans = fir.steps;
            break;
        }
        int next_floor = fir.floor + up_down[fir.floor];
        if (next_floor <= N && vis[next_floor] == false)
        {
            vis[next_floor] = true;
            fl new_fl;
            new_fl.floor = next_floor;
            new_fl.steps = fir.steps + 1;
            m_que.push(new_fl);
        }
        int next_floor2 = fir.floor - up_down[fir.floor];
        if (next_floor2 >= 1 && vis[next_floor2] == false)
        {
            vis[next_floor2] = true;
            fl new_fl;
            new_fl.floor = next_floor2;
            new_fl.steps = fir.steps + 1;
            m_que.push(new_fl);
        }
    }
}

int main()
{
    std::cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> up_down[i];
    }
    bfs();
    std::cout << (ans == 0 ? -1 : ans);
    return 0;
}
