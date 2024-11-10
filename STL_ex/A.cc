#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::vector<std::string > strs;
    
    for(int i = 0;i != n;i++)
    {
        std::string str;
        std::getline(std::cin,str);
        strs.push_back(str);
    }
    for(auto i : strs)
    {
        std::map<char,int> m;
        m.insert(std::make_pair('a', 0));
        m.insert(std::make_pair('e', 0));
        m.insert(std::make_pair('i', 0));
        m.insert(std::make_pair('o', 0));
        m.insert(std::make_pair('u', 0));
        for(auto j : i)
        {
            for(auto &k : m)
            {
                if(j == k.first)
                {
                    k.second++;
                }
            }
        }
        for(auto l : m)
        {
            std::cout << l.first << ":" << l.second << "\n "[l.first == 'u'];
        }
        if(i != strs.back())
        {
            std::cout << '\n';
            std::cout << '\n';
        }
    }
    return 0;
}