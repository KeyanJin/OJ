#include <iostream>
#include <vector>
class Character
{
    public:
        int m_count;
        char m_ch;
        Character(int count,char ch) : m_ch(ch),m_count(count){}
        Character(){}
};
int main()
{
    std::string str;
    std::cin >> str;
    std::vector<Character> chs;
    for(auto i : str)
    {
        Character ch = Character(0,i);
        if(chs.empty())
        {
            ch.m_count++;
            chs.push_back(ch);
        }
        else
        {
            for(auto  &j : chs)
            {
                if(i == j.m_ch)
                {
                    j.m_count++;
                }
            }
            ch.m_count++;
            chs.push_back(ch);
            
            
        } 
    }
    Character max = chs.at(0);
    for(auto i : chs)
    {
        if(max.m_count < i.m_count)
        {
            max.m_ch = i.m_ch;
            max.m_count = i.m_count;
        }else if(max.m_count == i.m_count)
        {
            if(max.m_ch > i.m_ch)
            {
                max.m_ch = i.m_ch;
                max.m_count = i.m_count;
            }
        }
    }
    std::cout << max.m_ch << " " << max.m_count;
    return 0;
}