#include <map>
#include <string>
#include <iostream>
#include <cstdio>

int main()
{
    std::map<std::string, std::string> m_map;
    std::string str1, str2;
    std::cin >> str1;
    for (; std::cin >> str1;)
    {
        if (str1 == "END")
        {
            break;
        }
        std::cin >> str2;
        m_map[str2] = str1;
    }
    std::cin >> str1;
    std::cin.ignore();
    for (;;)
    {
        char ch;
        str1 = "";
        for (;;)
        {
            ch = getchar();
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            {
                str1 += ch;
            }
            else
            {
                break;
            }
        }
        if (str1 == "END")
        {
            break;
        }
        if (m_map.find(str1) == m_map.end())
        {
            std::cout << str1;
        }
        else
        {
            std::cout << m_map[str1];
        }
        std::cout << ch;
    }
    return 0;
}