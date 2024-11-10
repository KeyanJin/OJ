#include <iostream>
#include <queue>
#include <vector>
int main()
{
    int n;
    std::vector<int> nums;
    std::queue<int> m_que;
    std::cin >> n;
    for(int i = 0;i != n;i++)
    {
        int num;
        std::cin >> num;
        if(num == 1)
        {
            int a;
            std::cin >> a;
            m_que.push(a);
        }
        else if(num == 2)
        {
            if(m_que.empty())
            {
                std::cout << "ERR_CANNOT_POP" << std::endl;
            }
            else
            {
                m_que.pop();
            }
        }
        else if(num == 3)
        {
            if(m_que.empty())
            {
                std::cout << "ERR_CANNOT_QUERY" << std::endl;
            }
            else
            {
                std::cout << m_que.front() << std::endl;
            }
            
        }
        else if(num == 4)
        {
            std::cout << m_que.size() << std::endl;
        }
    }
    return 0;
}