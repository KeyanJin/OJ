// #include <iostream>
// #include <queue>
// #include <set>
// #include <utility>
// bool judge(int n)
// {
//     return (n >= 0 && n <= 100000);
// }
// int bfs(int N,int K)
// {
//     std::queue<std::pair<int,int> > que;
//     std::set<int> vis;
//     vis.insert(N);
//     que.push(std::make_pair(N, 0));
//     while(!que.empty())
//     {
//         int pos = que.front().first;
//         int steps = que.front().second;
//         if(pos == K)
//         {
//             return steps;
//         }
//         que.pop();
//         int pos_for = pos + 1;
//         int pos_bac = pos - 1;
//         int pos_dou = pos * 2;
//         if(vis.find(pos_for) == vis.end() && judge(pos_for))
//         {
//             vis.insert(pos_for);
//             que.push(std::make_pair(pos_for, steps + 1));
//         }
//         if(vis.find(pos_bac) == vis.end() && judge(pos_bac))
//         {
//             vis.insert(pos_bac);
//             que.push(std::make_pair(pos_bac, steps + 1));
//         }
//         if(vis.find(pos_dou) == vis.end() && judge(pos_dou))
//         {
//             vis.insert(pos_dou);
//             que.push(std::make_pair(pos_dou, steps + 1));
//         }
//     }
//     return -1;
// }
// int main()
// {
//     int N,K;
//     std::cin >> N >> K;
//     int ans = bfs(N,K);
//     std::cout << ans;
//     return 0;
// }
#include <iostream>
#include <queue>
#include <vector>

bool judge(int n)
{
    return (n >= 0 && n <= 100000);
}

int bfs(int N, int K)
{
    if (N == K)
        return 0;

    std::queue<int> que;
    std::vector<bool> visited(100001, false);
    visited[N] = true;
    que.push(N);

    int steps = 0;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; ++i)
        {
            int pos = que.front();
            que.pop();

            if (pos == K)
            {
                return steps;
            }

            if (pos - 1 >= 0 && !visited[pos - 1])
            {
                visited[pos - 1] = true;
                que.push(pos - 1);
            }

            if (pos + 1 <= 100000 && !visited[pos + 1])
            {
                visited[pos + 1] = true;
                que.push(pos + 1);
            }

            if (pos * 2 <= 100000 && !visited[pos * 2])
            {
                visited[pos * 2] = true;
                que.push(pos * 2);
            }
        }
        ++steps;
    }
    return -1;
}

int main()
{
    int N, K;
    std::cin >> N >> K;
    int ans = bfs(N, K);
    std::cout << ans;
    return 0;
}
