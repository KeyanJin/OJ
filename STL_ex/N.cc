#include <iostream>
#include <map>
#include <string>
int main()
{
    int max = 0;
    std::map<char, int> m_map;
    char temp;
    for(int i = 0;i != 4;i++)
    {
        std::string str;
        std::getline(std::cin,str);
        for(auto i : str)
        {
            if(i <= 'Z' && i >= 'A')
            {
                m_map[i]++;
            }
        }
    }
    for(auto i : m_map)
    {
        if(i.second > max)
        {
            max = i.second;
        }
    }
    char arr[max][26];
    for(int i = 0;i < max;i++)
    {
        for(int j = 0;j < 26;j++)
        {
            if(i < max - m_map[j + 'A'])
            {
                arr[i][j] = ' ';
            }
            else
            {
                arr[i][j] = '*';
            }
        }
    }
    for(int i = 0;i < max;i++)
    {
        for(int j = 0;j < 26;j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(auto i : m_map)
    {
        std::cout << i.first << " ";
    }
    return 0;
}