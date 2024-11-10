#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::map<std::string, int> m_map;
    for(int i = 1;i <= n;i++)
    {
        std::string temp;
        std::cin >> temp;
        m_map.insert(std::make_pair(temp, i));
    }
    std::vector<std::pair<std::string,int>> m_vec(m_map.begin(),m_map.end());
    std::sort(m_vec.begin(),m_vec.end(),[](std::pair<std::string,int> &p1,std::pair<std::string,int> &p2)->bool{
        return p1.first.size() > p2.first.size();
    });
    auto i = m_map.find(m_vec[0].first);
    std::cout << i->second << std::endl;
    std::cout << i->first << std::endl;
    return 0;
}