#include <iostream>
#include <vector>

int main()
{
    int n,k;
    std::vector<int> mins;
    std::vector<int> maxs;
    std::vector<int> m_que;
    std::cin >> n >> k;
    for(int i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        m_que.push_back(temp);
    }
    for(int i = 0;i <= n - k;i++)
    {
        int min = m_que[i];
        int max = m_que[i];
        for(int j = i;j <= k - 1 + i;j++)
        {
            if(m_que[j] > max)
            {
                max = m_que[j];
            }
            if(m_que[j] < min)
            {
                min = m_que[j];
            }
        }
        mins.push_back(min);
        maxs.push_back(max);
    }
    for(auto i : mins)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(auto i : maxs)
    {
        std::cout << i << " ";
    }
    return 0;
}