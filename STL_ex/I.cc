#include <algorithm>  
#include <iostream>  
#include <list>  
  
int main() {  
    std::list<int> m_list;  
    m_list.push_front(1);  
    int N;  
    std::cin >> N;  
    for (int i = 2; i <= N; ++i) 
    {  
        int k, p;  
        std::cin >> k >> p;  
        auto pos = std::find(m_list.begin(), m_list.end(), k);  
        if (pos != m_list.end()) 
        {
            if (p == 0) 
            {  
                if (pos == m_list.begin()) 
                {  
                    m_list.push_front(i);  
                } 
                else 
                {  
                    m_list.insert(pos, i);
                }  
            } 
            else if (p == 1) 
            {  
                auto next_pos = std::next(pos);  
                if (next_pos == m_list.end()) 
                {  
                    m_list.push_back(i);  
                } 
                else 
                {  
                    m_list.insert(next_pos, i);
                }  
            }  
        }  
    }  
    int M;  
    std::cin >> M;  
    for (int i = 0; i < M; ++i)
    {  
        int temp;  
        std::cin >> temp;  
        auto pos = std::find(m_list.begin(), m_list.end(), temp);  
        if (pos != m_list.end())
        {  
            m_list.erase(pos);  
        }  
    }  
    for (auto i : m_list) 
    {  
        std::cout << i << " ";  
    }  
    return 0;  
}