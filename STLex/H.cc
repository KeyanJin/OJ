#include <iostream>
#include <queue>
#include <vector>
int main()
{
    std::queue<int> m_que;
    std::vector<int> minV;
    std::vector<int> maxV;
    int n,k;
    std::cin >> n >> k;
    for(auto i = 0;i != n;i++)
    {
        int temp;
        std::cin >> temp;
        m_que.push(temp);
    }
    for(;m_que.size() >= k;)
    {
        int max = m_que.front();
        int min = m_que.front();
        for(int i = 0;i != k;i++)
        {
            std::queue<int> new_que = m_que;
            int temp = new_que.front();
            if(temp > max)
            {
                max = temp;
            }
            else if(temp < min)
            {
                min = temp;
            }
            new_que.pop();
        }
        minV.push_back(min);
        maxV.push_back(max);
        m_que.pop();
    }
    for(auto i : minV)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(auto i : maxV)
    {
        std::cout << i << " ";
    }
    return 0;
}