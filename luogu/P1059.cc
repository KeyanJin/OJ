#include <iostream>
#include <set>

int main()
{
    int N;
    std::cin >> N;
    std::set<int> m_set;
    for(int i = 0;i != N;i++)
    {
        int temp;
        std::cin >> temp;
        m_set.insert(temp);
    }
    std::cout << m_set.size() << std::endl;
    for(auto i : m_set)
    {
        std::cout << i << " ";
    }
}