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
