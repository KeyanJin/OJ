#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int > m_set;
    int n,m;
    std::cin >> n >> m;
    for(int i = 0;i != m;i++)
    {
        int temp;
        std::cin >> temp;
        m_set.push_back(temp);
    }
    std::sort(m_set.begin(),m_set.end());
    for(auto i : m_set)
    {
        std::cout << i << " ";
    }
    return 0;
}